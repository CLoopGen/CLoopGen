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

jpc_enc_tccp_t *tccp;
uint_fast16_t rlvlno;
uint_fast16_t prcwidthexpn;
uint_fast16_t prcheightexpn;

void init_vars() {
    tccp = (jpc_enc_tccp_t*)calloc(1, sizeof(jpc_enc_tccp_t));
    if (!tccp) exit(1);

    tccp->maxrlvls = 33;
    prcwidthexpn = 5;
    prcheightexpn = 5;
}