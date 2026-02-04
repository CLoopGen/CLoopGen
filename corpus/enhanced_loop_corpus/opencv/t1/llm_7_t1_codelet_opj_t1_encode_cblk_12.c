#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char OPJ_BYTE;

typedef uint32_t OPJ_UINT32;

typedef double OPJ_FLOAT64;

typedef struct opj_tcd_layer {
    OPJ_UINT32 numpasses;
    OPJ_UINT32 len;
    OPJ_FLOAT64 disto;
    OPJ_BYTE *data;
} opj_tcd_layer_t;

typedef unsigned int OPJ_BITFIELD;

typedef struct opj_tcd_pass {
    OPJ_UINT32 rate;
    OPJ_FLOAT64 distortiondec;
    OPJ_UINT32 len;
    OPJ_BITFIELD term : 1;
} opj_tcd_pass_t;

typedef int32_t OPJ_INT32;

typedef struct opj_tcd_cblk_enc {
    OPJ_BYTE *data;
    opj_tcd_layer_t *layers;
    opj_tcd_pass_t *passes;
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 numbps;
    OPJ_UINT32 numlenbits;
    OPJ_UINT32 data_size;
    OPJ_UINT32 numpasses;
    OPJ_UINT32 numpassesinlayers;
    OPJ_UINT32 totalpasses;
} opj_tcd_cblk_enc_t;

extern opj_tcd_cblk_enc_t *cblk;
extern OPJ_UINT32 passno;
extern OPJ_UINT32 last_pass_rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 i, max_passes = cblk->totalpasses;
    OPJ_UINT32 local_last_rate = last_pass_rate;
    opj_tcd_pass_t *passes_base = cblk->passes;
    for (i = 0; i < max_passes; ++i) {
        opj_tcd_pass_t *pass = &passes_base[max_passes - i - 1];
        if (pass->rate > local_last_rate) {
            pass->rate = local_last_rate;
        } else {
            local_last_rate = pass->rate;
        }
    }
    last_pass_rate = local_last_rate;
}
