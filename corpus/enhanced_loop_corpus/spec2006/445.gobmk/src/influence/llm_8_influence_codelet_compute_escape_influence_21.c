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
    int limit = 400;
    for (ii = start; ii < limit; ii += 2) {
        if ((board[ii] != 3) && (board[ii + 1] != 3)) {
            escape_value[ii] = escape_values[ii][cache_number];
            escape_value[ii + 1] = escape_values[ii + 1][cache_number];
        } else if (board[ii] != 3) {
            escape_value[ii] = escape_values[ii][cache_number];
        }
    }
}
