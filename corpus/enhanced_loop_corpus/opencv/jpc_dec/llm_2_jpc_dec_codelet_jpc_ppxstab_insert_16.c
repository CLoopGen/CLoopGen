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
extern jpc_ppxstabent_t *ent;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    jpc_ppxstabent_t **ents_start = tab->ents;
    jpc_ppxstabent_t **ents_end = tab->ents + tab->numents;
    jpc_ppxstabent_t **p = ents_start;
    for (i = 0; p < ents_end; ++p, ++i) {
        if ((*p)->ind > ent->ind) {
            break;
        }
    }
}
