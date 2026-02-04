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
int compno;
jpc_dec_ccp_t *ccp;

static jpc_dec_ccp_t *g_ccps = NULL;
static jpc_pchglist_t g_pchglist;

void init_vars() {
    const int numcomps = 50000;

    g_ccps = calloc(numcomps, sizeof(jpc_dec_ccp_t));
    if (!g_ccps) exit(1);

    for (int i = 0; i < numcomps; ++i) {
        jpc_dec_ccp_t *ccp_ptr = &g_ccps[i];
        ccp_ptr->flags = 0;
        ccp_ptr->csty = 1;
        ccp_ptr->numrlvls = 5;
        ccp_ptr->cblkwidthexpn = 2;
        ccp_ptr->cblkheightexpn = 2;
        ccp_ptr->qmfbid = 1;
        ccp_ptr->qsty = 2;
        ccp_ptr->numstepsizes = 4;
        for (int j = 0; j < 100; ++j) {
            ccp_ptr->stepsizes[j] = 1000 + j;
        }
        ccp_ptr->numguardbits = 2;
        ccp_ptr->roishift = 0;
        ccp_ptr->cblkctx = 0;
        for (int j = 0; j < 33; ++j) {
            ccp_ptr->prcwidthexpns[j] = 3;
            ccp_ptr->prcheightexpns[j] = 3;
        }
    }

    g_pchglist.numpchgs = 0;
    g_pchglist.maxpchgs = 0;
    g_pchglist.pchgs = NULL;

    cp = malloc(sizeof(jpc_dec_cp_t));
    if (!cp) exit(1);
    cp->flags = 0;
    cp->pchglist = &g_pchglist;
    cp->prgord = 0;
    cp->numlyrs = 8;
    cp->mctid = 0;
    cp->csty = 1;
    cp->numcomps = numcomps;
    cp->ccps = g_ccps;
}