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
    uint_fast16_t prev_ind = 0;
    for (i = 0; i < tab->numents; ++i) {
        uint_fast16_t current_ind = tab->ents[i]->ind;
        if (current_ind > ent->ind) {
            break;
        }
        prev_ind = current_ind;
    }
}
