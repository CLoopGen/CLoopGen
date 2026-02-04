#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint_fast8_t prgord;
    uint_fast8_t rlvlnostart;
    uint_fast8_t rlvlnoend;
    uint_fast16_t compnostart;
    uint_fast16_t compnoend;
    uint_fast16_t lyrnoend;
} jpc_pocpchg_t;

typedef jpc_pocpchg_t jpc_pchg_t;

typedef struct {
    int numpchgs;
    int maxpchgs;
    jpc_pchg_t **pchgs;
} jpc_pchglist_t;

jpc_pchglist_t *pchglist;
int pchgno;
int i;

void init_vars() {
    const int total_elements = 131072; // ~131k elements to target ~0.01 sec runtime
    pchgno = total_elements / 2; // Start midway to ensure loop runs forward

    pchglist = (jpc_pchglist_t*)malloc(sizeof(jpc_pchglist_t));
    pchglist->numpchgs = total_elements;
    pchglist->maxpchgs = total_elements;
    pchglist->pchgs = (jpc_pchg_t**)malloc(total_elements * sizeof(jpc_pchg_t*));

    for (int idx = 0; idx < total_elements; ++idx) {
        pchglist->pchgs[idx] = (jpc_pchg_t*)malloc(sizeof(jpc_pchg_t));
        pchglist->pchgs[idx]->prgord = idx % 256;
        pchglist->pchgs[idx]->rlvlnostart = (idx + 1) % 256;
        pchglist->pchgs[idx]->rlvlnoend = (idx + 2) % 256;
        pchglist->pchgs[idx]->compnostart = (idx + 3) % 65536;
        pchglist->pchgs[idx]->compnoend = (idx + 4) % 65536;
        pchglist->pchgs[idx]->lyrnoend = (idx + 5) % 65536;
    }
}