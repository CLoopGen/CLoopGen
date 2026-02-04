#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef uint16_t OPJ_UINT16;

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

typedef struct opj_pi_resolution {
    OPJ_UINT32 pdx;
    OPJ_UINT32 pdy;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
} opj_pi_resolution_t;

typedef struct opj_pi_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct opj_image_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 prec;
    OPJ_UINT32 bpp;
    OPJ_UINT32 sgnd;
    OPJ_UINT32 resno_decoded;
    OPJ_UINT32 factor;
    OPJ_INT32 *data;
    OPJ_UINT16 alpha;
} opj_image_comp_t;

OPJ_UINT32 numcomps = 64;
OPJ_UINT32 compno;
OPJ_UINT32 resno;
OPJ_UINT32 **l_tmp_ptr;
opj_tccp_t *l_tccp;
opj_pi_comp_t *l_current_comp;
opj_image_comp_t *l_img_comp;
OPJ_UINT32 *l_encoding_value_ptr;

void init_vars() {
    numcomps = 64; // Chosen to ensure sufficient data size

    // Allocate l_tmp_ptr as array of pointers to OPJ_UINT32
    l_tmp_ptr = (OPJ_UINT32**)calloc(numcomps, sizeof(OPJ_UINT32*));
    if (!l_tmp_ptr) exit(1);

    // Each component has up to 33 resolutions in typical case, but we use dynamic sizing
    OPJ_UINT32 max_resolutions = 33;
    OPJ_UINT32 total_values_per_comp = max_resolutions * 4; // 4 values per resolution: pdx,pdy,pw,ph
    OPJ_UINT32 total_data_size = numcomps * total_values_per_comp;

    // Allocate a large contiguous block for encoding values
    OPJ_UINT32 *encoding_data = (OPJ_UINT32*)calloc(total_data_size, sizeof(OPJ_UINT32));
    if (!encoding_data) exit(1);

    for (OPJ_UINT32 i = 0; i < numcomps; ++i) {
        l_tmp_ptr[i] = &encoding_data[i * total_values_per_comp];
        // Initialize some dummy values
        for (OPJ_UINT32 j = 0; j < total_values_per_comp; ++j) {
            encoding_data[i * total_values_per_comp + j] = (i + 1) * (j + 1);
        }
    }

    // Allocate l_tccp array
    l_tccp = (opj_tccp_t*)calloc(numcomps, sizeof(opj_tccp_t));
    if (!l_tccp) exit(1);
    for (OPJ_UINT32 i = 0; i < numcomps; ++i) {
        l_tccp[i].numresolutions = max_resolutions;
    }

    // Allocate l_current_comp array
    l_current_comp = (opj_pi_comp_t*)calloc(numcomps, sizeof(opj_pi_comp_t));
    if (!l_current_comp) exit(1);

    // Allocate l_img_comp array
    l_img_comp = (opj_image_comp_t*)calloc(numcomps, sizeof(opj_image_comp_t));
    if (!l_img_comp) exit(1);

    // Allocate resolutions for each component
    opj_pi_resolution_t *all_resolutions = (opj_pi_resolution_t*)calloc(numcomps * max_resolutions, sizeof(opj_pi_resolution_t));
    if (!all_resolutions) exit(1);

    for (OPJ_UINT32 i = 0; i < numcomps; ++i) {
        l_current_comp[i].numresolutions = max_resolutions;
        l_current_comp[i].resolutions = &all_resolutions[i * max_resolutions];
        l_current_comp[i].dx = i + 1;
        l_current_comp[i].dy = i + 1;

        l_img_comp[i].dx = i + 1;
        l_img_comp[i].dy = i + 1;
        l_img_comp[i].alpha = (OPJ_UINT16)(i % 32768);
    }
}