#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef float OPJ_FLOAT32;

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

extern OPJ_UINT32 i;
extern OPJ_UINT32 l_nb_elem;
extern OPJ_FLOAT32 *l_current_data;
extern opj_tccp_t *l_tccp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 limit = l_nb_elem;
    for (i = 0; i < limit; ++i) {
        if (l_tccp->m_dc_level_shift != 0) {
            *(l_current_data++) = (OPJ_FLOAT32)(l_tccp->m_dc_level_shift);
        }
        ++l_tccp;
    }
}
