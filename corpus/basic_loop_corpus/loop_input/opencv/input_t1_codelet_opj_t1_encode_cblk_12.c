#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char OPJ_BYTE;
typedef uint32_t OPJ_UINT32;
typedef double OPJ_FLOAT64;
typedef int32_t OPJ_INT32;
typedef unsigned int OPJ_BITFIELD;

typedef struct opj_tcd_layer {
    OPJ_UINT32 numpasses;
    OPJ_UINT32 len;
    OPJ_FLOAT64 disto;
    OPJ_BYTE *data;
} opj_tcd_layer_t;

typedef struct opj_tcd_pass {
    OPJ_UINT32 rate;
    OPJ_FLOAT64 distortiondec;
    OPJ_UINT32 len;
    OPJ_BITFIELD term : 1;
} opj_tcd_pass_t;

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

opj_tcd_cblk_enc_t *cblk;
OPJ_UINT32 passno;
OPJ_UINT32 last_pass_rate;

static opj_tcd_pass_t *g_passes = NULL;
static opj_tcd_cblk_enc_t g_cblk;

void init_vars() {
    const OPJ_UINT32 total_data_size = 64 * 1024 * 1024;
    const OPJ_UINT32 estimated_passes = 8 * 1024 * 1024;

    g_passes = (opj_tcd_pass_t*)calloc(estimated_passes, sizeof(opj_tcd_pass_t));
    if (!g_passes) exit(1);

    for (OPJ_UINT32 i = 0; i < estimated_passes; ++i) {
        g_passes[i].rate = 1000 + i % 50000;
        g_passes[i].distortiondec = 1.0 / (1.0 + i);
        g_passes[i].len = 100 + i % 1000;
        g_passes[i].term = (i % 2);
    }

    g_cblk.data = (OPJ_BYTE*)malloc(total_data_size);
    if (!g_cblk.data) exit(1);

    g_cblk.layers = NULL;
    g_cblk.passes = g_passes;
    g_cblk.x0 = 0;
    g_cblk.y0 = 0;
    g_cblk.x1 = 256;
    g_cblk.y1 = 256;
    g_cblk.numbps = 12;
    g_cblk.numlenbits = 3;
    g_cblk.data_size = total_data_size;
    g_cblk.numpasses = estimated_passes;
    g_cblk.numpassesinlayers = estimated_passes - (estimated_passes / 4);
    g_cblk.totalpasses = estimated_passes;

    cblk = &g_cblk;
    passno = 0;
    last_pass_rate = 500000;
}