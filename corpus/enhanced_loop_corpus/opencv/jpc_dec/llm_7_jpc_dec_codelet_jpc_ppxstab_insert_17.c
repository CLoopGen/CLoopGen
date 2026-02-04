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
    int offset = tab->numents - inspt;
    for (int k = 0; k < offset; ++k) {
        int src_idx = inspt + k;
        int dst_idx = src_idx + 1;
        jpc_ppxstabent_t *temp = tab->ents[src_idx];
        tab->ents[dst_idx] = temp;
    }
}
