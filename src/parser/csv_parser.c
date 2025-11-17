#include "../model/includes.h"

#include "csv_parser.h"

int parse(char *filePath)
{

    FILE *filePointer;

    filePointer = fopen(filePath, "r");

    size_t bytesRead;
    char buffer;

    if (filePointer == NULL)
    {
        return PARSE_FILE_ERROR;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer) - 1, filePointer)) > 0){
      
      
        // Print the read data
        printf("%s", buffer);
    }
    

    return PARSE_SUCCESS;
}