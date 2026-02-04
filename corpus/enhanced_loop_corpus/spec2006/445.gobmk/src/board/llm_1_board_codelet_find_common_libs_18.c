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
    for (int outer = 0; outer < liberties1; outer++) {
        k = libs1[outer];
        int conditions_met = 0;
        if (((board[(k + (19 + 1))] == board[str2]) && string_number[(k + (19 + 1))] == string_number[str2]) ||
            ((board[(k - 1)] == board[str2]) && string_number[(k - 1)] == string_number[str2]) ||
            ((board[(k - (19 + 1))] == board[str2]) && string_number[(k - (19 + 1))] == string_number[str2]) ||
            ((board[(k + 1)] == board[str2]) && string_number[(k + 1)] == string_number[str2])) {
            conditions_met = 1;
        }
        if (conditions_met) {
            if (commonlibs < maxlib) {
                libs[commonlibs] = k;
            }
            commonlibs++;
        }
    }
}
