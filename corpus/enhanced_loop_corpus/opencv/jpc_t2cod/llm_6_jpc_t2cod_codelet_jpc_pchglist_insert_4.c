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
    int offset = pchglist->numpchgs - pchgno;
    for (i = pchglist->numpchgs; i > pchgno; --i) {
        pchglist->pchgs[i] = pchglist->pchgs[i - 1];
        // Introduce a loop-carried dependency via cumulative offset adjustment (WAW on offset)
        offset = offset - 1;
    }
}
