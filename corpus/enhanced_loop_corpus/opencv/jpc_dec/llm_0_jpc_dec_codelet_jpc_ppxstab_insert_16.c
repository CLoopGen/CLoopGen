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
    for (int outer = 0; outer < 1; ++outer) {
        for (i = 0; i < tab->numents; ++i) {
            if (tab->ents[i]->ind > ent->ind) {
                break;
            }
        }
    }
}
