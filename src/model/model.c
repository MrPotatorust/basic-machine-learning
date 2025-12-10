#include "includes.h"
#include "model.h"

struct Model model_Constructor(){
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
    self.calculateLoss = calculateLoss;
    self.predict = predict;
    self.resetWeights = resetWeights;

    return self;
}

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames, int featureCount){
    self->data = csv;
    self->labelName = labelName;
    self->featureNames = featureNames;
    self->featureCount = featureCount;

    self->resetWeights(self);
}

void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize){
    self->epochs = epochs;
    self->learningRate = learningRate;
    self->batchSize = batchSize;
}

void train(struct Model *self){

    self->loss = self->calculateLoss(self);
    
    

    printf("  ====================================================== \n");
    printf("|| Weight: %f || Bias: %f || Loss: %f || \n", self->weights[0], self->bias, self->loss);

};

float calculateLoss(struct Model *self){
    int exampleCount = self->data->rowCount;

    float lossAggregate = 0;

    
    for(int curCol = 0; curCol < exampleCount; curCol++){
        Row *startFeaturePointer = &self->data->rows[curCol * self->data->collumnCount];
        float label = getData(self->data, curCol, self->data->collumnCount+1);

        float predictionVal = self->predict(self, startFeaturePointer);
        lossAggregate += pow(label - predictionVal, 2);
    }


    return lossAggregate / exampleCount;
}

float predict(struct Model *self, float features[]){
    float prediction = 0;
    
    for(int curCol = 0; curCol < self->featureCount; curCol++){
        prediction += features[curCol] * self->weights[curCol];
    }

    prediction += self->bias;

    return prediction;
}


void resetWeights(struct Model *self){

    if(!self->featureCount){
        perror("No features are set");
        return;
    }

    float *weights = malloc(self->featureCount * sizeof(float));

    if(!weights){
        perror("Could not initialize memory for weights");
        return;
    }

    for(int i = 0; i < self->featureCount; i++){
        weights[i] = 0.0;
    }

    self->weights = weights;
}

float calculateWeightSlope(struct Model *self){

}