#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint_fast16_t ind;
    uint_fast32_t len;
    unsigned char *data;
} jpc_ppxstabent_t;

typedef struct {
    int numents;
    int maxents;
    jpc_ppxstabent_t **ents;
} jpc_ppxstab_t;

extern jpc_ppxstab_t *tab;
extern int inspt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    // Adjust loop bounds to ensure we don't go out of bounds when accessing i-2
    int start = tab->numents;
    int end = inspt;
    // Align start to even index if necessary
    if ((start - end) % 2 != 0) {
        if (start > end) {
            tab->ents[start] = tab->ents[start - 1];
            start--;
        }
    }
    for (i = start; i > end; i -= 2) {
        tab->ents[i] = tab->ents[i - 1];
        tab->ents[i - 1] = tab->ents[i - 2];
    }
}
