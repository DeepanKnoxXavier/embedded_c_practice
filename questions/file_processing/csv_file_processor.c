
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//
// Explain what this macro does.
//
// Your explanation (mandatory):
//
//
//
//

#define PARAMETER_DATATYPE_STRING(x)                                                \
    ( x == 0 ) ? ("BOOL") : ( ( x == 1 ) ? ("UINT") : ( x == 2 ? "INT" : ( x == 3 ) ? "FLOAT" : "INVALID" ) ) 

//
// What is thie FILE pointer do?
// What is the actual datatype of FILE pointer?
// Explore the source code and find out.
//
//

FILE* file;

char line[1024];

//
// What is an enum in C ?
//
// Your answer (mandatory):
//
//
//
//

typedef enum
{
    BOOL = 0,
    UINT = 1,
    INT = 2,
    FLOAT = 3,
}parameter_datatype;

//
// What can you infer from this struct?
// What is the pupose of this structure?
//
// Your answer & explanation:
//
//
//
//

struct parameter_record
{
    int device_number;
    int register_number;
    char parameter_name[256];
    int start_bit;
    int bitfield_length;
    parameter_datatype datatype;
};

//
// What does this function do?
// Your answer and explanation (mandatory):
//
//
//
//

void print_parameter_record(struct parameter_record* record)
{
    printf("\n\nParameter name: %s\n", record->parameter_name);
    printf("Device number: %d\n", record->device_number);
    printf("Register number: %d\n", record->register_number);
    printf("Start bit: %d\n", record->start_bit);
    printf("Bitfield length: %d\n", record->bitfield_length);
    printf("Parameter datatype: %s\n\n\n", PARAMETER_DATATYPE_STRING(record->datatype));
}

//
// How does this parsing function work?
// What is the use of the strtok function over here?
// Explain the use of standard library functions like atoi ove here.
//
// Your answer and explanation (mandatory)
//
//
//
//
//

void parse_parameter_record(struct parameter_record* record, char* line)
{
    char* ptr;

    ptr = strtok(line, ",");

    ptr = strtok(NULL, ",");
    record->device_number = atoi(ptr);
    
    ptr = strtok(NULL, ",");
    record->register_number = atoi(ptr);

    ptr = strtok(NULL, ",");
    memcpy(record->parameter_name, ptr, strlen(ptr));

    ptr = strtok(NULL, ",");
    record->start_bit = atoi(ptr);

    ptr = strtok(NULL, ",");
    record->bitfield_length = atoi(ptr);

    ptr = strtok(NULL, ",");

    if( strcmp(ptr, "bool") == 0 )
    {
        record->datatype = BOOL;
    }
    else if( strcmp(ptr, "uint") == 0 )
    {
        record->datatype = UINT;
    }
    else if( strcmp(ptr, "int") == 0 )
    {
        record->datatype = INT;
    }
    else if( strcmp(ptr, "float") == 0 )
    {
        record->datatype = FLOAT;
    }
}

struct parameter_record record[256];

//
// Explain the use of the file operation functions such as
// fgets, fopen and fclose over here.
//
// Your answer and explanation:
//
//
//
//

int main(void)
{
    file = fopen("test.csv", "r");

    fgets(line, 1024, file);
   
    int index = 0;

    while( fgets(line, 1024, file) ) 
    {
        parse_parameter_record( &record[index], line );
        print_parameter_record(&record[index]);
        index++;
    }

    fclose(file);

    return 0;
}