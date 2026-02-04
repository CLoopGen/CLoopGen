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
    int neighbor_count = 0;
    int center = libs1[k];

    if ((board[center + 20] == board[str2]) && string_number[center + 20] == string_number[str2])
        neighbor_count++;
    if ((board[center - 1] == board[str2]) && string_number[center - 1] == string_number[str2])
        neighbor_count++;
    if ((board[center - 20] == board[str2]) && string_number[center - 20] == string_number[str2])
        neighbor_count++;
    if ((board[center + 1] == board[str2]) && string_number[center + 1] == string_number[str2])
        neighbor_count++;

    if (neighbor_count > 0)
        commonlibs++;
}
}
