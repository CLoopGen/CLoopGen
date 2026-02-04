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
    int limit = tab->numents;
    for (i = 0; i < limit; ++i) {
        if (tab->ents[i] != NULL && tab->ents[i]->ind > ent->ind) {
            break;
        }
    }
}
