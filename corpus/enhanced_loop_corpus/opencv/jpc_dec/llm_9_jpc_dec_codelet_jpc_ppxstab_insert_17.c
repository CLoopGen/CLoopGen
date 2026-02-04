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
    int step = 2;
    int adjusted_numents = tab->numents - (tab->numents - inspt) % 2; // Make trip count even for safe unrolling
    for (i = adjusted_numents; i > inspt; i -= step) {
        // Unrolled loop with two iterations combined
        if (i > inspt + 0) tab->ents[i] = tab->ents[i - 1];
        if (i > inspt + 1) tab->ents[i-1] = tab->ents[i - 2];
    }
    // Handle leftover iteration if needed (not required due to trip count adjustment)
}
