#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint_fast8_t prgord;
    uint_fast8_t rlvlnostart;
    uint_fast8_t rlvlnoend;
    uint_fast8_t compnostart;
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
    const int data_size = 128 * (1 << 20); // 128 MB target
    const size_t base_pchgs_count = data_size / sizeof(jpc_pchg_t*);
    pchglist = malloc(sizeof(jpc_pchglist_t));
    pchglist->maxpchgs = base_pchgs_count + 10;
    pchglist->numpchgs = base_pchgs_count;
    pchgno = base_pchgs_count / 2; // ensures loop runs over half the array

    pchglist->pchgs = calloc(pchglist->maxpchgs, sizeof(jpc_pchg_t*));
    for (size_t idx = 0; idx < pchglist->maxpchgs; ++idx) {
        pchglist->pchgs[idx] = malloc(sizeof(jpc_pchg_t));
        pchglist->pchgs[idx]->prgord = idx % 256;
        pchglist->pchgs[idx]->rlvlnostart = idx % 256;
        pchglist->pchgs[idx]->rlvlnoend = (idx + 1) % 256;
        pchglist->pchgs[idx]->compnostart = idx % 65536;
        pchglist->pchgs[idx]->compnoend = (idx + 10) % 65536;
        pchglist->pchgs[idx]->lyrnoend = (idx + 5) % 65536;
    }
}