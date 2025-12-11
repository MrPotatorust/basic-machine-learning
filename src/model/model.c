#include "includes.h"
#include "model.h"

struct Model model_Constructor()
{
    struct Model self;

    self.weights = NULL;
    self.bias = 0;

    self.labelName = NULL;
    self.featureNames = NULL;
    self.featureCount = 0;
    self.data = NULL;

    self.loss = 0.0;
    self.learningRate = 0.0;
    self.batchSize = 0;
    self.epochs = 0;

    self.train = train;
    self.loadData = loadData;
    self.setTrainingConfig = setTrainingConfig;
    self.calculateWeightSlope = calculateWeightSlope;
    self.calculateBiasSlope = calculateBiasSlope;
    self.calculateLoss = calculateLoss;
    self.predict = predict;
    self.resetWeights = resetWeights;

    return self;
}

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames, int featureCount)
{
    self->data = csv;
    self->labelName = labelName;
    self->featureNames = featureNames;
    self->featureCount = featureCount;

    self->resetWeights(self);
}

void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize)
{
    self->epochs = epochs;
    self->learningRate = learningRate;
    self->batchSize = batchSize;
}

void train(struct Model *self)
{

    self->loss = self->calculateLoss(self);

    float *newWeights = malloc(self->featureCount * sizeof(float));

    self->calculateWeightSlope(self, 0);
    self->calculateBiasSlope(self);

    printf("  ====================================================== \n");
    printf("|| Weight: %f || Bias: %f || Loss: %f || \n", self->weights[0], self->bias, self->loss);
};

float calculateWeightSlope(struct Model *self, int weightIndex)
{

    float aggregate = 0;

    for (int curRow = 0; curRow < self->data->rowCount; curRow++)
    {
        float feature = getData(self->data, curRow, weightIndex);
        float label = getData(self->data, curRow, self->featureCount - 1);
        Row *startFeaturePointer = &self->data->rows[curRow * self->data->collumnCount];
        float prediction = self->predict(self, startFeaturePointer);

        aggregate += (prediction - label) * (2 * feature);
    }

    float slope = aggregate / self->data->rowCount;

    return slope;
}

float calculateBiasSlope(struct Model *self)
{
    float aggregate = 0;

    for (int curRow = 0; curRow < self->data->rowCount; curRow++)
    {
        float label = getData(self->data, curRow, self->featureCount - 1);
        Row *startFeaturePointer = &self->data->rows[curRow * self->data->collumnCount];
        float prediction = self->predict(self, startFeaturePointer);

        aggregate += (prediction - label) * 2;
    }

    float slope = aggregate / self->data->rowCount;

    return slope;
}

float calculateLoss(struct Model *self)
{
    int exampleCount = self->data->rowCount;

    float lossAggregate = 0;

    for (int curRow = 0; curRow < exampleCount; curRow++)
    {
        Row *startFeaturePointer = &self->data->rows[curRow * self->data->collumnCount];
        float label = getData(self->data, curRow, self->featureCount);

        float predictionVal = self->predict(self, startFeaturePointer);
        lossAggregate += pow(label - predictionVal, 2);
    }

    return lossAggregate / exampleCount;
}

float predict(struct Model *self, float features[])
{
    float prediction = 0;

    for (int curCol = 0; curCol < self->featureCount; curCol++)
    {
        prediction += features[curCol] * self->weights[curCol];
    }

    prediction += self->bias;

    return prediction;
}

void resetWeights(struct Model *self)
{

    if (!self->featureCount)
    {
        perror("No features are set");
        return;
    }

    float *weights = malloc(self->featureCount * sizeof(float));

    if (!weights)
    {
        perror("Could not initialize memory for weights");
        return;
    }

    for (int i = 0; i < self->featureCount; i++)
    {
        weights[i] = 0.0;
    }

    self->weights = weights;
}