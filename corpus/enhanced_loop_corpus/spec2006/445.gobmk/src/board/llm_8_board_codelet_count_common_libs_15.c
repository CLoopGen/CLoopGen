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
for (k = 0; k < liberties1 && k < 200; k++) {
    int pos = libs1[k];
    int offset_north = pos + 20;
    int offset_west = pos - 1;
    int offset_south = pos - 20;
    int offset_east = pos + 1;
    
    if (((board[offset_north] == board[str2]) && string_number[offset_north] == string_number[str2]) ||
        ((board[offset_west] == board[str2]) && string_number[offset_west] == string_number[str2]) ||
        ((board[offset_south] == board[str2]) && string_number[offset_south] == string_number[str2]) ||
        ((board[offset_east] == board[str2]) && string_number[offset_east] == string_number[str2])) {
        commonlibs++;
    }
}
}
