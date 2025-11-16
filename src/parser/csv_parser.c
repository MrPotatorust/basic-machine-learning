#include "../model/includes.h"

#include "csv_parser.h"

int parse(char *filePath)
{

    FILE *fptr;

    fptr = fopen(filePath, "r");

    if (fptr == NULL)
    {
        return PARSE_FILE_ERROR;
    }

    return PARSE_SUCCESS;
}