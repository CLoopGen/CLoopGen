#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_pos = (19 + 2) - 1;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if ((board[pos] != 3)) {
            string_number[pos] = string_number[prev_pos] + (-1 - string_number[prev_pos]);
            prev_pos = pos;
        }
    }
}
