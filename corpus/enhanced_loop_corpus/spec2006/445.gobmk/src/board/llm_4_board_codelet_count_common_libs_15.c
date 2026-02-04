#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < liberties1; k++) {
    int pos = libs1[k];
    int same_color = board[pos] == board[str2];
    if (!same_color) continue;
    int found = 0;
    if ((board[pos + 20] == board[str2]) && string_number[pos + 20] == string_number[str2])
        found = 1;
    else if ((board[pos - 1] == board[str2]) && string_number[pos - 1] == string_number[str2])
        found = 1;
    else if ((board[pos - 20] == board[str2]) && string_number[pos - 20] == string_number[str2])
        found = 1;
    else if ((board[pos + 1] == board[str2]) && string_number[pos + 1] == string_number[str2])
        found = 1;
    if (found)
        commonlibs++;
}
}
