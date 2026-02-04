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

jpc_ppxstab_t *tab;
int inspt;
int i;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB to target ~0.01s runtime
    const int num_elements = 100000;

    tab = (jpc_ppxstab_t *)calloc(1, sizeof(jpc_ppxstab_t));
    tab->numents = num_elements;
    tab->maxents = num_elements + 10;
    tab->ents = (jpc_ppxstabent_t **)calloc(tab->maxents, sizeof(jpc_ppxstabent_t *));

    unsigned char *bulk_data = (unsigned char *)malloc(data_size);
    for (int idx = 0; idx < num_elements; ++idx) {
        jpc_ppxstabent_t *ent = (jpc_ppxstabent_t *)malloc(sizeof(jpc_ppxstabent_t));
        ent->ind = (uint_fast16_t)(idx & 0xFFFF);
        ent->len = (uint_fast32_t)(data_size / num_elements);
        ent->data = bulk_data + (idx * ent->len);
        tab->ents[idx] = ent;
    }

    inspt = num_elements / 2; // Ensure inspt < numents so loop runs

    // Ensure there's space for the shift: we'll preserve valid bounds during loop
}