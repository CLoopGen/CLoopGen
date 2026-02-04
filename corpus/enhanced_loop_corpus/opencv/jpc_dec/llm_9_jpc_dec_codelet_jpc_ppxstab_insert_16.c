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
    int step = 1;
    int double_step;
    for (i = 0; i < tab->numents; i += step) {
        double_step = i + step;
        if (double_step < tab->numents && tab->ents[double_step]->ind > ent->ind) {
            i = double_step;
            break;
        }
        if (tab->ents[i]->ind > ent->ind) {
            break;
        }
    }
}
