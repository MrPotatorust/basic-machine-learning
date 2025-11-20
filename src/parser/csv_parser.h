// csv_parser.h
#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#define COL_NAME 24
#define BUFFER_SIZE 256

enum dataType {
    INT,
    FLOAT
};

typedef struct Col {
    char name[COL_NAME];
    enum dataType type;
} Col;

// typedef struct Row {
//     float data[];
// } Row;

typedef struct CSV
{
    Col *collumns;
    float *rows;
} CSV;


CSV *parse(char *filePath);
Col *parseCols(char buffer[]);
int getCollumnCount(char buffer[]);
int getRowCount(FILE *filePointer);

#endif