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
    char temp_val;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii += 2) {
        if ((board[ii] != 3)) {
            temp_val = escape_value[ii];
            escape_values[ii][cache_number] = temp_val;
        }
        if (ii + 1 < (19 + 1) * (19 + 1) && (board[ii + 1] != 3)) {
            temp_val = escape_value[ii + 1];
            escape_values[ii + 1][cache_number] = temp_val;
        }
    }
}
