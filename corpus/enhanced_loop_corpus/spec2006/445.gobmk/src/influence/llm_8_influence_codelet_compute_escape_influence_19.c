#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char escape_value[400];
extern int ii;
extern char escape_values[400][2];
extern int cache_number;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int end = 361;
    for (ii = start; ii < end; ii += 2) {
        if ((board[ii] != 3) && (ii % 3 != 0)) {
            escape_values[ii][cache_number] = escape_value[ii];
        }
    }
}
