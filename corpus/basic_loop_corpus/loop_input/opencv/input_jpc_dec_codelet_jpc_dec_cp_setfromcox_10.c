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
    uint_fast8_t parwidthval;
    uint_fast8_t parheightval;
} jpc_coxrlvl_t;

typedef struct {
    uint_fast8_t csty;
    uint_fast8_t numdlvls;
    uint_fast8_t cblkwidthval;
    uint_fast8_t cblkheightval;
    uint_fast8_t cblksty;
    uint_fast8_t qmfbid;
    int numrlvls;
    jpc_coxrlvl_t rlvls[33];
} jpc_coxcp_t;

jpc_dec_ccp_t *ccp;
jpc_coxcp_t *compparms;
int rlvlno;

void init_vars() {
    ccp = (jpc_dec_ccp_t*)calloc(1, sizeof(jpc_dec_ccp_t));
    compparms = (jpc_coxcp_t*)calloc(1, sizeof(jpc_coxcp_t));

    compparms->numrlvls = 33;

    for (int i = 0; i < 33; ++i) {
        compparms->rlvls[i].parwidthval = (uint_fast8_t)(i * 7 + 1);
        compparms->rlvls[i].parheightval = (uint_fast8_t)(i * 11 + 3);
    }

    ccp->numrlvls = 33;
}