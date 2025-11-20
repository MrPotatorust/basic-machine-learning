// csv_parser.h
#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#define COL_NAME 24
#define BUFFER_SIZE 256


#define COL_FREE_FAIL 1
#define ROW_FREE_FAIL 2

enum dataType {
    INT,
    FLOAT
};

typedef struct Col {
    char name[COL_NAME];
    enum dataType type;
} Col;

typedef float Row;

typedef struct CSV
{
    Col *collumns;
    Row *rows;

    int collumnCount;
    int rowCount; 

} CSV;


CSV *parse(char *filePath);
Col *parseCols(char buffer[], int collumnCount);
int getCollumnCount(char buffer[]);
int getRowCount(FILE *filePointer);
int freeCSV(CSV *csv);
int freeCols(CSV *csv);
int freeRows(CSV *csv);
// int getData();

#endif