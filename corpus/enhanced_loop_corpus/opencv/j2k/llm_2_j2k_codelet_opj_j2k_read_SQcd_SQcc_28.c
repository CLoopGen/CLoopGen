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

extern OPJ_UINT32 l_band_no;
extern opj_tccp_t *l_tccp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 idx = 1;
    for (l_band_no = 0; l_band_no < (3 * 33 - 3); l_band_no++) {
        idx = 1 + l_band_no;
        l_tccp->stepsizes[idx].expn = ((OPJ_INT32)(l_tccp->stepsizes[0].expn) - (OPJ_INT32)((idx - 1) / 3) > 0) ? (OPJ_INT32)(l_tccp->stepsizes[0].expn) - (OPJ_INT32)((idx - 1) / 3) : 0;
        l_tccp->stepsizes[idx].mant = l_tccp->stepsizes[0].mant;
    }
}
