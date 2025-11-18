#include "../model/includes.h"

#include "csv_parser.h"

int parse(char *filePath)
{

    FILE *filePointer;

    filePointer = fopen(filePath, "r");

    char buffer[BUFFER_SIZE];


    if (filePointer == NULL)
    {
        return PARSE_FILE_ERROR;
    }

    // Get the collumn names

    fgets(buffer, sizeof(buffer), filePointer);
    parseCols(buffer);
    return 0;

    while ((fgets(buffer, sizeof(buffer), filePointer)) > 0){
      
      
        // Print the read data
    }


    fclose(filePointer);

    return PARSE_SUCCESS;
};

Col **parseCols(char buffer[]){
    // printf("%s", buffer);
    // Col collumns[]; 
    Col *collumns = malloc(sizeof(Col));

    int i;

    char* token = strtok(buffer, ",");

    while(token != NULL){
        printf("%s \n", token);
        collumns = realloc
        token = strtok(NULL, ",");
        i++;
    }
}; 