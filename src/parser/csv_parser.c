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

    // Get the collumn names, for now the 
    //! DataType is hardCoded to float
    fgets(buffer, sizeof(buffer), filePointer);
    
    int collumnCount = getCollumnCount(buffer);

    Col *collumns = parseCols(buffer);


    float *data = malloc(sizeof(float)); 
    int rowCount = 0;

    while ((fgets(buffer, sizeof(buffer), filePointer)) > 0){
        data = realloc

        rowCount++;
    }


    fclose(filePointer);

    return PARSE_SUCCESS;
};

Col *parseCols(char buffer[]){
    
    Col *collumns = malloc(sizeof(Col));
    int i = 0;

    if(collumns == NULL){
        return NULL;
    }


    char* token = strtok(buffer, ",");

    while(token != NULL){
        Col collumn;

        collumn.type = INT;
        strcpy(collumn.name, token);
        collumns[i] = collumn;
        collumns = realloc(collumns, (i+2) * sizeof(Col));

        if (collumns == NULL){
            return NULL;
        }
        token = strtok(NULL, ",");
        i++;
    }

    return collumns;
}; 


// Gets the collumn count by counting commas
int getCollumnCount(char buffer[]){
    int count = 1;

    while (*buffer != '\0')
    {
        if (*buffer == ','){
            count++;
        }
        buffer++;
    }
    
    return count;
    
}

int getData(int row, int col, float data[], int colCount){
    
}