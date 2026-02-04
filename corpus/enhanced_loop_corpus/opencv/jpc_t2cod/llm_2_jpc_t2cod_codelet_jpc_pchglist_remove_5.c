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



void loop() {
    int start = pchgno + 1;
    int end = pchglist->numpchgs;
    jpc_pchg_t **src = pchglist->pchgs + start;
    jpc_pchg_t **dst = pchglist->pchgs + start - 1;
    for (int idx = 0; idx < end - start; ++idx) {
        dst[idx] = src[idx];
    }
}
