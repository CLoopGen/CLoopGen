#include <stdio.h>

#include <inttypes.h>

extern char **row;
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle boundary
    int limit = (6 + 1) / 2;
    for (i = 0; i < limit; i++) {
        int idx = i * 2;
        if (idx < 6) irow[idx] = row[idx];
        idx++;
        if (idx < 6) irow[idx] = row[idx];
    }
}
