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
    for (i = tab->numents; i > inspt; --i) {
        if (i % 2 == 0) {
            tab->ents[i] = tab->ents[i - 1];
        } else {
            tab->ents[i] = NULL;
        }
    }
}
