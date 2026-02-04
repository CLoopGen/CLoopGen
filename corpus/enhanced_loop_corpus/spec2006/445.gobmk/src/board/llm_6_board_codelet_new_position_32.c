#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int p;
    for (p = (19 + 2); p < (19 + 1) * (19 + 1); p++) {
        pos = p;
        if ((board[pos] != 3))
            string_number[pos] = -1;
    }
}
