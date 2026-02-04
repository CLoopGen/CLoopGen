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
for (k = 0; k < liberties1; k++) {
    int cond1 = ((board[(libs1[k]) + 20] == board[str2]) && (string_number[(libs1[k]) + 20] == string_number[str2]));
    int cond2 = ((board[(libs1[k]) - 1] == board[str2]) && (string_number[(libs1[k]) - 1] == string_number[str2]));
    int cond3 = ((board[(libs1[k]) - 20] == board[str2]) && (string_number[(libs1[k]) - 20] == string_number[str2]));
    int cond4 = ((board[(libs1[k]) + 1] == board[str2]) && (string_number[(libs1[k]) + 1] == string_number[str2]));

    if (!(cond1 || cond2 || cond3 || cond4))
        continue;

    if (commonlibs < maxlib)
        libs[commonlibs] = libs1[k];
    commonlibs++;
}
}
