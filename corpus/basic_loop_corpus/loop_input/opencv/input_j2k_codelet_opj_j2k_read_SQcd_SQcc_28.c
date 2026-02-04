#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

typedef struct opj_stepsize {
    OPJ_INT32 expn;
    OPJ_INT32 mant;
} opj_stepsize_t;

typedef struct opj_tccp {
    OPJ_UINT32 csty;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 cblksty;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 qntsty;
    opj_stepsize_t stepsizes[97];
    OPJ_UINT32 numgbits;
    OPJ_INT32 roishift;
    OPJ_UINT32 prcw[33];
    OPJ_UINT32 prch[33];
    OPJ_INT32 m_dc_level_shift;
} opj_tccp_t;

OPJ_UINT32 l_band_no;
opj_tccp_t *l_tccp;

void init_vars() {
    l_tccp = (opj_tccp_t*)calloc(1, sizeof(opj_tccp_t));
    if (!l_tccp) {
        exit(1);
    }

    l_tccp->stepsizes[0].expn = 15;
    l_tccp->stepsizes[0].mant = 123;
    l_tccp->numresolutions = 33;
    l_tccp->csty = 1;
    l_tccp->cblkw = 6;
    l_tccp->cblkh = 6;
    l_tccp->cblksty = 0;
    l_tccp->qmfbid = 1;
    l_tccp->qntsty = 0;
    l_tccp->numgbits = 2;
    l_tccp->roishift = 0;
    l_tccp->m_dc_level_shift = 0;

    for (int i = 0; i < 33; ++i) {
        l_tccp->prcw[i] = 1;
        l_tccp->prch[i] = 1;
    }
}