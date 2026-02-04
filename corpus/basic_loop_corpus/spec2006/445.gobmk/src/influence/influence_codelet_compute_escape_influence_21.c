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
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++)
    if ((board[ii] != 3))
        escape_value[ii] = escape_values[ii][cache_number];

}
