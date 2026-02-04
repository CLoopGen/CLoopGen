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

typedef struct {
    int flags;
    uint_fast8_t csty;
    uint_fast8_t numrlvls;
    uint_fast8_t cblkwidthexpn;
    uint_fast8_t cblkheightexpn;
    uint_fast8_t qmfbid;
    uint_fast8_t qsty;
    uint_fast16_t numstepsizes;
    uint_fast16_t stepsizes[100];
    uint_fast8_t numguardbits;
    uint_fast8_t roishift;
    uint_fast8_t cblkctx;
    uint_fast8_t prcwidthexpns[33];
    uint_fast8_t prcheightexpns[33];
} jpc_dec_ccp_t;

typedef struct {
    int flags;
    jpc_pchglist_t *pchglist;
    uint_fast8_t prgord;
    uint_fast16_t numlyrs;
    uint_fast8_t mctid;
    uint_fast8_t csty;
    int numcomps;
    jpc_dec_ccp_t *ccps;
} jpc_dec_cp_t;

extern jpc_dec_cp_t *cp;
extern jpc_dec_ccp_t *ccp;
extern int compno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependency (WAW on compno) and reorder initializations to create artificial RAW dependencies.
    // We split the initialization into stages where some fields depend on prior iterations' values (though logically unnecessary).
    uint_fast16_t prev_numstepsizes = 0;
    for (compno = 0, ccp = cp->ccps; compno < cp->numcomps; ++compno, ++ccp) {
        ccp->flags = 0;
        ccp->numrlvls = (uint_fast8_t)(prev_numstepsizes & 0xFF);  // Artificial RAW dependency
        ccp->cblkwidthexpn = 0;
        ccp->cblkheightexpn = 0;
        ccp->qmfbid = 0;
        ccp->qsty = 0;
        ccp->numstepsizes = compno + 1;  // Now varies per component
        for (int i = 0; i < ccp->numstepsizes && i < 100; ++i) {
            ccp->stepsizes[i] = (uint_fast16_t)(i * 2);
        }
        ccp->numguardbits = 0;
        ccp->roishift = 0;
        ccp->cblkctx = 0;
        prev_numstepsizes = ccp->numstepsizes;  // WAW dependency carried across loop iterations
    }
}
