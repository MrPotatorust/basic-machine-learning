// csv_parser.h
#ifndef CSV_PARSER_H
#define CSV_PARSER_H


#define PARSE_SUCCESS 0
#define PARSE_FILE_ERROR -1

#define COL_NAME 24



typedef struct Col {
    char name[COL_NAME];
};

int parse(char* filePath);

#endif