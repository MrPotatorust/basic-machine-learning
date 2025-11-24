#include "model/includes.h"

#include "parser/csv_parser.h"
#include "model/model.h"

int main(int argc, char *argv[])
{
    CSV *csv = parse("./dataset/normalized_tips.csv");

    if(csv == NULL){
        return 1;
    }

    struct Model model = model_Constructor();

    model.loadData(&model, csv, "tip", ["test"]);

    printf("Parsed file successfuly \n");
    return 0;
}