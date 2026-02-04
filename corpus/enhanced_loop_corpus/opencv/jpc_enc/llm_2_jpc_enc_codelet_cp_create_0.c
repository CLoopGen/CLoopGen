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
    uint_fast16_t idx;
    for (idx = 0; idx < tccp->maxrlvls; ++idx) {
        tccp->prcwidthexpns[idx] = prcwidthexpn;
        tccp->prcheightexpns[idx] = prcheightexpn;
    }
}
