#include "model/includes.h"

#include "parser/csv_parser.h"
#include "model/model.h"

int main(int argc, char *argv[])
{
    CSV *csv = parse("./dataset/normalized_tips.csv");

    if (csv == NULL)
    {
        return 1;
    }
    printf("Parsed file successfuly \n");

    struct Model model = model_Constructor();

    // char *featureNames[] = {"total_bill", "sex", "smoker", "day", "time", "size"};
    char *featureNames[] = {"total_bill"};
    int featureCount = 1;
    char *labelName = "tip";

    model.loadData(&model, csv, labelName, featureNames, featureCount);

    int epochs = 12;
    float learningRate = 0.1;
    int batchSize = 20;

    model.setTrainingConfig(&model, epochs, learningRate, batchSize);

    model.train(&model);
    // float features[] ={2.1};
    // float prediction = model.predict(&model, features);
    // printf("Prediction %f \n", prediction);

    return 0;
}