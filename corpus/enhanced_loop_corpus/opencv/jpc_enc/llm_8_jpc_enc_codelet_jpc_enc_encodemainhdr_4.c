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

typedef struct {
    uint_fast8_t csty;
    uint_fast8_t prg;
    uint_fast16_t numlyrs;
    uint_fast8_t mctrans;
    jpc_coxcp_t compparms;
} jpc_cod_t;

extern jpc_enc_tccp_t *tccp;
extern uint_fast16_t rlvlno;
extern jpc_cod_t *cod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint_fast16_t i;
    for (i = 0; i < tccp->maxrlvls && i < 33; ++i) {
        cod->compparms.rlvls[i].parwidthval = tccp->prcwidthexpns[i] + 1;
        cod->compparms.rlvls[i].parheightval = tccp->prcheightexpns[i] - 1;
        cod->compparms.rlvls[i].parwidthval *= 2;
        cod->compparms.rlvls[i].parheightval /= 2;
    }
}
