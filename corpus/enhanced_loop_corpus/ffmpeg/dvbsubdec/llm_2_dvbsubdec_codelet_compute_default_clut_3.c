#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the indexing
    // Instead of accessing counttab2[i+1][i], we rewrite to access consecutive elements in a row
    int (*tab)[256] = counttab2 + 1;  // Point to the second row (counttab2[1])
    for (i = 0; i < 256; i++) {
        tab[i][i] = 0;  // Still diagonal, but base shifted
    }
}
