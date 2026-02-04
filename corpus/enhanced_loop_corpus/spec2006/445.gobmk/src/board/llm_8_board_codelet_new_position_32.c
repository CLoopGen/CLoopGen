#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 21; pos < 400; pos += 2)
        if ((board[pos] != 3) && (board[pos + 1] != 3))
            string_number[pos] = -1;
}
