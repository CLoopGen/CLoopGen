#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int *surround_size;
extern char mn[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int limit = 400;
    for (pos = start; pos < limit; pos += 2)
        if ((board[pos] != 3) && mn[pos] == 1)
            (*surround_size)++;
}
