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

jpc_dec_cp_t *cp;
jpc_dec_ccp_t *ccp;
int compno;

static jpc_dec_ccp_t* ccps = NULL;
static jpc_pchglist_t pchglist;
static jpc_pchg_t** pchgs_arr = NULL;

void init_vars() {
    const int numcomps = 65536;
    cp = (jpc_dec_cp_t*)calloc(1, sizeof(jpc_dec_cp_t));
    ccps = (jpc_dec_ccp_t*)calloc(numcomps, sizeof(jpc_dec_ccp_t));
    cp->numcomps = numcomps;
    cp->ccps = ccps;
    cp->pchglist = &pchglist;
    cp->flags = 0;
    cp->prgord = 0;
    cp->numlyrs = 0;
    cp->mctid = 0;
    cp->csty = 0;

    pchglist.numpchgs = 0;
    pchglist.maxpchgs = 0;
    pchglist.pchgs = NULL;

    for (int i = 0; i < numcomps; ++i) {
        jpc_dec_ccp_t* ccp_ptr = &ccps[i];
        ccp_ptr->flags = 0;
        ccp_ptr->csty = 0;
        ccp_ptr->numrlvls = 0;
        ccp_ptr->cblkwidthexpn = 0;
        ccp_ptr->cblkheightexpn = 0;
        ccp_ptr->qmfbid = 0;
        ccp_ptr->qsty = 0;
        ccp_ptr->numstepsizes = 0;
        for (int j = 0; j < 100; ++j) {
            ccp_ptr->stepsizes[j] = 0;
        }
        ccp_ptr->numguardbits = 0;
        ccp_ptr->roishift = 0;
        ccp_ptr->cblkctx = 0;
        for (int j = 0; j < 33; ++j) {
            ccp_ptr->prcwidthexpns[j] = 0;
            ccp_ptr->prcheightexpns[j] = 0;
        }
    }

    compno = 0;
    ccp = cp->ccps;
}