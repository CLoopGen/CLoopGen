#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 21; pos < 361; pos++) {
        int idx = pos * 1;
        if ((board[idx] != 3))
            string_number[idx] = -1;
        if ((board[idx + 20] != 3))
            string_number[idx + 20] = -1;
    }
}
