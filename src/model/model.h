#include "../parser/csv_parser.h"

#ifndef MODEL_H
#define MODEL_H

struct Model {
    float *weights;
    float bias;
    int weightCount;


    char *labelName;
    char **featureNames;
    CSV *data;

    float loss;
    float learningRate;
    float batchSize;
    int epochs;


    void (*train)(struct Model *self);
    void (*loadData)(struct Model *self, CSV *csv, char *labelName, char **featureNames);
    void (*setTrainingConfig)(struct Model *self, int epochs, float learningRate, float batchSize);
};

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames);
void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize);

void train(struct Model *self);

struct Model model_Constructor();


#endif