#include "includes.h"
#include "model.h"

struct Model model_Constructor(){
    struct Model server;

    server.train = train;
    server.loadData = loadData;
    server.setTrainingConfig = setTrainingConfig;

    return server;
}

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames){
    self->data = csv;
    self->labelName = labelName;
    self->featureNames = featureNames;
}

void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize){
    self->epochs = epochs;
    self->learningRate = learningRate;
    self->batchSize = batchSize;
}

void train(struct Model *self){
};