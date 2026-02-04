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

static opj_pi_resolution_t *resolutions_pool;
static OPJ_UINT32 **tmp_ptr_array;
static OPJ_UINT32 *encoding_data_pool;
static opj_tccp_t *tccp_array;
static opj_pi_comp_t *pi_comp_array;
static opj_image_comp_t *img_comp_array;

void init_vars() {
    size_t i, j;
    
    // Allocate tccp array
    tccp_array = (opj_tccp_t*)calloc(numcomps, sizeof(opj_tccp_t));
    l_tccp = tccp_array;
    
    // Allocate pi_comp array
    pi_comp_array = (opj_pi_comp_t*)calloc(numcomps, sizeof(opj_pi_comp_t));
    l_current_comp = pi_comp_array;
    
    // Allocate img_comp array
    img_comp_array = (opj_image_comp_t*)calloc(numcomps, sizeof(opj_image_comp_t));
    l_img_comp = img_comp_array;
    
    // Allocate resolutions pool and tmp ptr array
    resolutions_pool = (opj_pi_resolution_t*)calloc(numcomps * 33, sizeof(opj_pi_resolution_t));
    tmp_ptr_array = (OPJ_UINT32**)calloc(numcomps, sizeof(OPJ_UINT32*));
    encoding_data_pool = (OPJ_UINT32*)calloc(numcomps * 132, sizeof(OPJ_UINT32)); // 33 res * 4 values each
    
    l_tmp_ptr = tmp_ptr_array;
    
    OPJ_UINT32 *data_cursor = encoding_data_pool;
    opj_pi_resolution_t *res_cursor = resolutions_pool;
    
    for (i = 0; i < numcomps; ++i) {
        // Set reasonable values for image component
        img_comp_array[i].dx = 1 + (i % 4);
        img_comp_array[i].dy = 1 + ((i >> 2) % 4);
        img_comp_array[i].w = 512;
        img_comp_array[i].h = 512;
        img_comp_array[i].x0 = 0;
        img_comp_array[i].y0 = 0;
        img_comp_array[i].prec = 8;
        img_comp_array[i].bpp = 8;
        img_comp_array[i].sgnd = 0;
        img_comp_array[i].resno_decoded = 0;
        img_comp_array[i].factor = 0;
        img_comp_array[i].alpha = 1;
        
        // Allocate dummy data if needed
        img_comp_array[i].data = NULL;
        
        // Set TCCP parameters
        tccp_array[i].numresolutions = 33;
        tccp_array[i].csty = 0;
        tccp_array[i].cblkw = 6;
        tccp_array[i].cblkh = 6;
        tccp_array[i].cblksty = 0;
        tccp_array[i].qmfbid = 1;
        tccp_array[i].qntsty = 0;
        tccp_array[i].numgbits = 1;
        tccp_array[i].roishift = 0;
        tccp_array[i].m_dc_level_shift = 0;
        
        // Initialize prcw and prch
        for (j = 0; j < 33; ++j) {
            tccp_array[i].prcw[j] = 1;
            tccp_array[i].prch[j] = 1;
        }
        
        // Set number of resolutions
        pi_comp_array[i].numresolutions = 33;
        pi_comp_array[i].dx = img_comp_array[i].dx;
        pi_comp_array[i].dy = img_comp_array[i].dy;
        pi_comp_array[i].resolutions = res_cursor;
        
        // Initialize resolution values via encoded data
        tmp_ptr_array[i] = data_cursor;
        for (j = 0; j < 33; ++j) {
            *data_cursor++ = 1; // pdx
            *data_cursor++ = 1; // pdy
            *data_cursor++ = 256 >> j; // pw - decaying size
            *data_cursor++ = 256 >> j; // ph - decaying size
            res_cursor->pdx = 0;
            res_cursor->pdy = 0;
            res_cursor->pw = 0;
            res_cursor->ph = 0;
            res_cursor++;
        }
    }
}