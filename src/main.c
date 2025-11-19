#include "model/includes.h"

#include "parser/csv_parser.h"

int main(int argc, char *argv[])
{
    int parseReturnCode = parse("./dataset/normalized_tips.csv");

    printf("Return code: %i \n", parseReturnCode);
    return 0;
}