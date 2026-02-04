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

extern jpc_dec_ccp_t *ccp;
extern jpc_qcxcp_t *compparms;
extern int bandno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bandno = 0; bandno < compparms->numstepsizes && bandno < 100; ++bandno) {
        if (bandno % 2 == 0) {
            ccp->stepsizes[bandno] = compparms->stepsizes[bandno];
        } else {
            ccp->stepsizes[bandno] = compparms->stepsizes[bandno] + compparms->numguard;
        }
    }
}
