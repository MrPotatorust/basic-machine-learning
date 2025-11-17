#include "model/includes.h"

#include "parser/csv_parser.h"

int main(int argc, char *argv[])
{

    int parseReturnCode = parse("./dataset/tips.csv");

    printf("%i \n", parseReturnCode);
    return 0;
}