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

extern jpc_pchglist_t *pchglist;
extern int pchgno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int limit = pchglist->numpchgs - (pchglist->numpchgs - (pchgno + 1)) % step;
    for (i = pchgno + 1; i < limit; i += step) {
        // Unroll by processing two elements per iteration where possible
        pchglist->pchgs[i - 1] = pchglist->pchgs[i];
        if (i + 1 < pchglist->numpchgs) {
            pchglist->pchgs[i] = pchglist->pchgs[i + 1];
        }
    }
    // Handle any remaining element if trip count is odd
    if (i == pchglist->numpchgs - 1) {
        pchglist->pchgs[i - 1] = pchglist->pchgs[i];
    }
}
