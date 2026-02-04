#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *lsp_2nd;
extern  double *lsp_prev;
extern double lsp_1st[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping (reverse order traversal)
    int index_map[16];
    for (int j = 0; j < 16; j++)
        index_map[j] = 15 - j;  // reverse indexing

    for (i = 0; i < 16; i++) {
        int idx = index_map[i];
        lsp_1st[idx] = (lsp_2nd[idx] + lsp_prev[idx]) * 0.5;
    }
}
