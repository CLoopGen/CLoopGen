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
    // Variant 1: Strided memory access with increased stride for cache-friendly pattern
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int stride = 4;
    for (ii = start; ii < end; ii += stride) {
        int idx = ii;
        if ((board[idx] != 3))
            escape_value[idx] = escape_values[idx][cache_number];
        // Process remaining elements in stride group if within bounds
        idx = ii + 1;
        if (idx < end && (board[idx] != 3))
            escape_value[idx] = escape_values[idx][cache_number];
        idx = ii + 2;
        if (idx < end && (board[idx] != 3))
            escape_value[idx] = escape_values[idx][cache_number];
        idx = ii + 3;
        if (idx < end && (board[idx] != 3))
            escape_value[idx] = escape_values[idx][cache_number];
    }
}
