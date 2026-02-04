#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Forward Indexing
    // Instead of accessing elements symmetrically from both ends using -i-1 and +i,
    // we restructure to access consecutive memory locations in a forward manner.
    // We assume that w_data and data are aligned such that [n2 - 1 - i] corresponds to the mirrored index.

    for (i = 0; i < n2; i++) {
        w = c - n2 + i;
        w = 1. - (w * w);
        // Convert negative indexing into positive offset: -i-1 => n2 - i - 1
        int32_t idx = n2 - i - 1;
        w_data[idx] = data[idx] * w;
        w_data[i] = data[i] * w;
    }
}
