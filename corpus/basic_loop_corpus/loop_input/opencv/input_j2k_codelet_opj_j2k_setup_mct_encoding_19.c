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

OPJ_UINT32 i;
OPJ_UINT32 l_nb_elem;
OPJ_FLOAT32 *l_current_data;
opj_tccp_t *l_tccp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01s runtime estimate
    l_nb_elem = data_size / sizeof(OPJ_FLOAT32);

    l_current_data = (OPJ_FLOAT32*)calloc(l_nb_elem, sizeof(OPJ_FLOAT32));
    if (!l_current_data) exit(1);

    l_tccp = (opj_tccp_t*)calloc(l_nb_elem, sizeof(opj_tccp_t));
    if (!l_tccp) exit(1);

    for (OPJ_UINT32 idx = 0; idx < l_nb_elem; ++idx) {
        l_tccp[idx].m_dc_level_shift = 128 + idx % 32;
    }
}