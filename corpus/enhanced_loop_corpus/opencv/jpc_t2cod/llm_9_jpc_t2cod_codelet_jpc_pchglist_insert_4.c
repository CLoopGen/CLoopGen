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
    int n = pchglist->numpchgs - pchgno;
    for (i = 0; i < n; ++i) {
        int src_idx = pchglist->numpchgs - i;
        int dst_idx = src_idx + 1;
        if (src_idx >= 0) {
            pchglist->pchgs[dst_idx] = pchglist->pchgs[src_idx];
        }
    }
}
