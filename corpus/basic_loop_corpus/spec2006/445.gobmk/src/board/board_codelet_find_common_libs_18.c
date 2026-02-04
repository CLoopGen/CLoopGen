#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < liberties1; k++)
    if ((((board[((libs1[k]) + (19 + 1))] == board[str2]) && string_number[((libs1[k]) + (19 + 1))] == (string_number[str2])) || ((board[((libs1[k]) - 1)] == board[str2]) && string_number[((libs1[k]) - 1)] == (string_number[str2])) || ((board[((libs1[k]) - (19 + 1))] == board[str2]) && string_number[((libs1[k]) - (19 + 1))] == (string_number[str2])) || ((board[((libs1[k]) + 1)] == board[str2]) && string_number[((libs1[k]) + 1)] == (string_number[str2])))) {
        if (commonlibs < maxlib)
            libs[commonlibs] = libs1[k];
        commonlibs++;
    }

}
