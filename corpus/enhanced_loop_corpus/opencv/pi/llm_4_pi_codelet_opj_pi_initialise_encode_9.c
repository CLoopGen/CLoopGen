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

typedef uint16_t OPJ_UINT16;

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

extern OPJ_UINT32 numcomps;
extern OPJ_UINT32 compno;
extern OPJ_UINT32 resno;
extern OPJ_UINT32 **l_tmp_ptr;
extern  opj_tccp_t *l_tccp;
extern opj_pi_comp_t *l_current_comp;
extern opj_image_comp_t *l_img_comp;
extern OPJ_UINT32 *l_encoding_value_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (compno = 0; compno < numcomps; ++compno) {
    opj_pi_resolution_t *l_res = l_current_comp->resolutions;
    l_encoding_value_ptr = l_tmp_ptr[compno];
    l_current_comp->dx = l_img_comp->dx;
    l_current_comp->dy = l_img_comp->dy;
    for (resno = 0; resno < l_current_comp->numresolutions; resno++) {
        if (*(l_encoding_value_ptr) > 1 && *(l_encoding_value_ptr + 1) > 1) {
            l_res->pdx = *(l_encoding_value_ptr++);
            l_res->pdy = *(l_encoding_value_ptr++);
            l_res->pw = *(l_encoding_value_ptr++);
            l_res->ph = *(l_encoding_value_ptr++);
            ++l_res;
        } else {
            l_res->pdx = 1;
            l_res->pdy = 1;
            l_res->pw = 0;
            l_res->ph = 0;
            l_encoding_value_ptr += 4;
            ++l_res;
        }
    }
    ++l_current_comp;
    ++l_img_comp;
    ++l_tccp;
}
}
