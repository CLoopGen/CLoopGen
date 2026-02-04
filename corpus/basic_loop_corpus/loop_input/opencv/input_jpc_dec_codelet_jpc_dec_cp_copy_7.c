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
jpc_dec_cp_t *newcp;
jpc_dec_ccp_t *newccp;
jpc_dec_ccp_t *ccp;
int compno;

void init_vars() {
    const int numcomps = 50000;

    jpc_dec_ccp_t *ccps1 = (jpc_dec_ccp_t*)calloc(numcomps, sizeof(jpc_dec_ccp_t));
    jpc_dec_ccp_t *ccps2 = (jpc_dec_ccp_t*)calloc(numcomps, sizeof(jpc_dec_ccp_t));

    cp = (jpc_dec_cp_t*)malloc(sizeof(jpc_dec_cp_t));
    newcp = (jpc_dec_cp_t*)malloc(sizeof(jpc_dec_cp_t));

    cp->numcomps = numcomps;
    cp->ccps = ccps1;
    newcp->ccps = ccps2;

    for (int i = 0; i < numcomps; ++i) {
        ccps1[i].flags = i * 37;
        ccps1[i].csty = i % 256;
        ccps1[i].numrlvls = (i % 32) + 1;
        ccps1[i].cblkwidthexpn = 3;
        ccps1[i].cblkheightexpn = 3;
        ccps1[i].qmfbid = i % 2;
        ccps1[i].qsty = i % 4;
        ccps1[i].numstepsizes = 5;
        for (int j = 0; j < 100; ++j) {
            ccps1[i].stepsizes[j] = (j + i) % 65536;
        }
        ccps1[i].numguardbits = i % 8;
        ccps1[i].roishift = i % 4;
        ccps1[i].cblkctx = i % 8;
        for (int j = 0; j < 33; ++j) {
            ccps1[i].prcwidthexpns[j] = (i + j) % 256;
            ccps1[i].prcheightexpns[j] = (i - j + 256) % 256;
        }
    }

    cp->pchglist = NULL;
    cp->prgord = 0;
    cp->numlyrs = 1;
    cp->mctid = 0;
    cp->csty = 0;

    newcp->pchglist = NULL;
    newcp->prgord = 0;
    newcp->numlyrs = 1;
    newcp->mctid = 0;
    newcp->csty = 0;
    newcp->numcomps = numcomps;
}