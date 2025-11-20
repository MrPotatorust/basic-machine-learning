#include "../model/includes.h"

#include "csv_parser.h"

CSV *parse(char *filePath)
{

    FILE *filePointer;

    filePointer = fopen(filePath, "r");

    char buffer[BUFFER_SIZE];


    if (filePointer == NULL)
    {
        return NULL;
    }

    // Get the collumn names, for now the 
    //! DataType is hardCoded to float
    fgets(buffer, sizeof(buffer), filePointer);
    
    int collumnCount = getCollumnCount(buffer);
    
    int rowCount = getRowCount(filePointer);

    Col *collumns = parseCols(buffer, collumnCount);

    int i = 0;
    Row *rows = malloc(collumnCount * rowCount * sizeof(float)); 
    
    if(rows == NULL){
        return NULL;
    }
    
    while ((fgets(buffer, sizeof(buffer), filePointer)) > 0){        
        char* token = strtok(buffer, ",");

        while(token != NULL){

            rows[i] = atof(token);

            token = strtok(NULL, ",");
            i++;
        }

    }

    fclose(filePointer);


    CSV *csv = malloc(sizeof(CSV));
    
    csv->collumns = collumns;
    csv->rows = rows;
    csv->collumnCount = collumnCount;
    csv->rowCount = rowCount;

    return csv;
}

Col *parseCols(char buffer[], int collumnCount){
    
    Col *collumns = malloc(sizeof(Col));
    int i = 0;

    if(collumns == NULL){
        return NULL;
    }


    char* token = strtok(buffer, ",");

    while(token != NULL && i < collumnCount){
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
}


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

int getRowCount(FILE *filePointer){
    int rowCount = 0;
    long originalPos = ftell(filePointer);
    char buffer[BUFFER_SIZE];

    while(fgets(buffer, sizeof(buffer), filePointer)){
        rowCount++;
    }

    fseek(filePointer, originalPos, SEEK_SET);
    return rowCount;
}

// int getData(int row, int col, float data[], int colCount){

// }

int freeCSV(CSV *csv) {

    if(freeCols(csv) != 0){
        return COL_FREE_FAIL;
    }
    
    if(freeRows(csv) != 0){
        return ROW_FREE_FAIL;
    }

    free(csv);

    csv = NULL;

    return 0;
}

int freeCols(CSV *csv){

    for(int i = 0; i < csv->collumnCount; i++){
        free(&csv->collumns[i]);
    }

    return 0;
    
}

int freeRows(CSV *csv){
    
    for(int i = 0; i < csv->rowCount; i++){
        free(&csv->rows[i]);
    }

    return 0;
}