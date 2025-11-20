#include "model/includes.h"

#include "parser/csv_parser.h"

int main(int argc, char *argv[])
{
    CSV *csv = parse("./dataset/normalized_tips.csv");

    if(csv == NULL){
        return 1;
    }

    printf("Parsed file successfuly \n");
    return 0;
}