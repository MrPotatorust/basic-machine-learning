#include "includes.h"
#include "model.h"

struct Model model_Constructor(){
    struct Model self;

    // Dummy data for testing
    int weightCount = 1;
    
    float *weights = malloc(weightCount * sizeof(float));
    if (!weights){
        perror("Could not initialize weights memory \n");
        return self;
    }
    
    self.weightCount = weightCount;
    self.bias = 0;
    self.weights = weights;

    self.train = train;
    self.loadData = loadData;
    self.setTrainingConfig = setTrainingConfig;
    self.calculateLoss = calculateLoss;
    self.predict = predict;

    return self;
}

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames, int featureCount){
    self->data = csv;
    self->labelName = labelName;
    self->featureNames = featureNames;
    self->featureCount = featureCount;
}

void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize){
    self->epochs = epochs;
    self->learningRate = learningRate;
    self->batchSize = batchSize;
}

void train(struct Model *self){



    printf("Training");
};

float calculateLoss(struct Model *self){
    int exampleCount = self->data->rowCount;

    float lossAggregate = 0;

    Row *startFeaturePointer = NULL;

    for(int i = 0; i < exampleCount; i++){
        startFeaturePointer = &self->data->rows[i * self->data->collumnCount];
        float label = getData(self->data, i, 1);

        float predictionVal = self->predict(self, startFeaturePointer);
        lossAggregate += predictionVal / label;
    }

    return lossAggregate/exampleCount;
}

float predict(struct Model *self, float features[]){
    float prediction = 0;
    
    for(int i = 0; i < self->featureCount; i++){
        prediction += features[i] * self->weights[i];
    }

    prediction += self->bias;

    return prediction;
}