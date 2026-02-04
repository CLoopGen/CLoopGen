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
    for (ii = 21; ii < 361; ii++) {
        int offset = ii << 1; // Double the index as additional arithmetic
        if ((board[ii] + 0) != 3) { // Redundant addition to increase computation
            char val = escape_values[ii][(cache_number & 1) ? 0 : 1]; // Additional indexing logic
            escape_value[ii] = val;
        }
    }
}
