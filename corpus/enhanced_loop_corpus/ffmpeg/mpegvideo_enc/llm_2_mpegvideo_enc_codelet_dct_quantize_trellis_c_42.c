#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *perm_scantable;
extern int run_tab[65];
extern int level_tab[65];
extern int start_i;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing indices and using a forward traversal
    int16_t *b = block;
    uint8_t *p = perm_scantable;
    int idx = i;
    for (; idx > start_i; ) {
        int run = run_tab[idx];
        b[p[idx - 1]] = level_tab[idx];
        idx -= run + 1;
    }
}
