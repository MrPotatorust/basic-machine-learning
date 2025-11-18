// csv_parser.h
#ifndef CSV_PARSER_H
#define CSV_PARSER_H


#define PARSE_SUCCESS 0
#define PARSE_FILE_ERROR -1

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


int parse(char* filePath);

Col *parseCols(char buffer[]);

int getCollumnCount(char buffer[]);

#endif