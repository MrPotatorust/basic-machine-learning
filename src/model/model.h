#include "../parser/csv_parser.h"

#ifndef MODEL_H
#define MODEL_H

struct Model {
    float *weights;
    float bias;
    int weightCount;


    char *labelName;
    char **featureNames;
    int featureCount;
    CSV *data;

    float loss;
    int lossExamples;
    float learningRate;
    float batchSize;
    int epochs;


    void (*train)(struct Model *self);
    void (*loadData)(struct Model *self, CSV *csv, char *labelName, char **featureNames, int featureCount);
    void (*setTrainingConfig)(struct Model *self, int epochs, float learningRate, float batchSize);
    float (*getLoss)(struct Model *self);
    float (*predict)(struct Model *self, float features[]);
};

void loadData(struct Model *self, CSV *csv, char *labelName, char **featureNames, int featureCount);
void setTrainingConfig(struct Model *self, int epochs, float learningRate, float batchSize);
void train(struct Model *self);
//? Right now the loss is calculated on all examples and calculates MAE
float getLoss(struct Model *self);
//! Here you have to pass the same features as the model was trained with
float predict(struct Model *self, float *features);

struct Model model_Constructor();


#endif