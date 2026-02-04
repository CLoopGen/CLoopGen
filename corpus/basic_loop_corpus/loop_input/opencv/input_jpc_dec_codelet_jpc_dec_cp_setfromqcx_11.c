#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    uint_fast8_t qntsty;
    int numstepsizes;
    uint_fast16_t *stepsizes;
    uint_fast8_t numguard;
} jpc_qcxcp_t;

jpc_dec_ccp_t *ccp;
jpc_qcxcp_t *compparms;
int bandno;

static uint_fast16_t *generated_stepsizes;
static jpc_dec_ccp_t static_ccp;
static jpc_qcxcp_t static_compparms;

void init_vars() {
    ccp = &static_ccp;
    compparms = &static_compparms;

    ccp->numstepsizes = 100;
    compparms->numstepsizes = 100;

    generated_stepsizes = (uint_fast16_t *)malloc(compparms->numstepsizes * sizeof(uint_fast16_t));
    if (!generated_stepsizes) {
        exit(1);
    }

    for (int i = 0; i < compparms->numstepsizes; ++i) {
        generated_stepsizes[i] = (uint_fast16_t)(i * 17 + 1);
    }

    compparms->stepsizes = generated_stepsizes;
    compparms->qntsty = 1;
    compparms->numguard = 3;

    for (int i = 0; i < 100; ++i) {
        ccp->stepsizes[i] = 0;
    }

    ccp->flags = 0;
    ccp->csty = 1;
    ccp->numrlvls = 5;
    ccp->cblkwidthexpn = 2;
    ccp->cblkheightexpn = 2;
    ccp->qmfbid = 1;
    ccp->qsty = 0;
    ccp->numguardbits = 2;
    ccp->roishift = 0;
    ccp->cblkctx = 0;
    for (int i = 0; i < 33; ++i) {
        ccp->prcwidthexpns[i] = 3;
        ccp->prcheightexpns[i] = 3;
    }
}