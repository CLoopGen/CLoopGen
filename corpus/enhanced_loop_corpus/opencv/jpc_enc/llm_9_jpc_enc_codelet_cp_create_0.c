#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint_fast8_t csty;
    uint_fast8_t maxrlvls;
    uint_fast16_t cblkwidthexpn;
    uint_fast16_t cblkheightexpn;
    uint_fast8_t cblksty;
    uint_fast8_t qmfbid;
    uint_fast16_t prcwidthexpns[33];
    uint_fast16_t prcheightexpns[33];
    uint_fast8_t numgbits;
} jpc_enc_tccp_t;

extern jpc_enc_tccp_t *tccp;
extern uint_fast16_t rlvlno;
extern uint_fast16_t prcwidthexpn;
extern uint_fast16_t prcheightexpn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint_fast16_t j;
    uint_fast16_t limit = (tccp->maxrlvls > 1) ? tccp->maxrlvls - 1 : tccp->maxrlvls;
    for (j = 0; j < limit; ++j) {
        tccp->prcwidthexpns[j] = prcwidthexpn;
        tccp->prcheightexpns[j] = prcheightexpn;
        tccp->prcwidthexpns[j + 1] += prcwidthexpn >> 1;
        tccp->prcheightexpns[j + 1] += prcheightexpn >> 1;
    }
    if (tccp->maxrlvls == 0) {
        return;
    }
    tccp->prcwidthexpns[0] = prcwidthexpn;
    tccp->prcheightexpns[0] = prcheightexpn;
}
