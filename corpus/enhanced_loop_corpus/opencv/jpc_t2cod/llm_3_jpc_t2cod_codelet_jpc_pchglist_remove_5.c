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
    int stride = 2;
    int n = pchglist->numpchgs;
    int offset = pchgno + 1;

    // Strided access: process elements in a strided pattern instead of dense
    for (int i = offset; i < n; i += stride) {
        if (i + 1 < n) {
            pchglist->pchgs[i - 1] = pchglist->pchgs[i];
        }
        if (i + 2 < n && i + 1 >= offset) {
            pchglist->pchgs[i] = pchglist->pchgs[i + 1];
        }
    }

    // Final pass for any remaining consecutive element if stride leaves gaps
    for (int i = offset + (stride - 1); i < n; ++i) {
        pchglist->pchgs[i - 1] = pchglist->pchgs[i];
    }
}
