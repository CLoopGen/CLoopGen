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
    int outer_start = (19 + 2);
    int outer_end = (19 + 1) * (19 + 1);
    int mid = (outer_start + outer_end) / 2;
    
    for (ii = outer_start; ii < mid; ii++)
        if ((board[ii] != 3))
            escape_values[ii][cache_number] = escape_value[ii];

    for (ii = mid; ii < outer_end; ii++)
        if ((board[ii] != 3))
            escape_values[ii][cache_number] = escape_value[ii];
}
