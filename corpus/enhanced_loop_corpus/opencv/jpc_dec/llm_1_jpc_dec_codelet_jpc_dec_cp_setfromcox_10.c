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

extern jpc_dec_ccp_t *ccp;
extern jpc_coxcp_t *compparms;
extern int rlvlno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (compparms->numrlvls > 0) {
        int temp_prcwidthexpns[33] = {0};
        int temp_prcheightexpns[33] = {0};
        for (rlvlno = 0; rlvlno < compparms->numrlvls; ++rlvlno) {
            temp_prcwidthexpns[rlvlno] = compparms->rlvls[rlvlno].parwidthval;
            temp_prcheightexpns[rlvlno] = compparms->rlvls[rlvlno].parheightval;
        }
        for (rlvlno = 0; rlvlno < compparms->numrlvls; ++rlvlno) {
            ccp->prcwidthexpns[rlvlno] = temp_prcwidthexpns[rlvlno];
            ccp->prcheightexpns[rlvlno] = temp_prcheightexpns[rlvlno];
        }
    }
}
