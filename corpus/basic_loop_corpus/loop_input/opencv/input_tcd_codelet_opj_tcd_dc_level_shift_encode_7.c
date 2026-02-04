#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef unsigned char OPJ_BYTE;
typedef double OPJ_FLOAT64;
typedef float OPJ_FLOAT32;
typedef unsigned int OPJ_BITFIELD;
typedef size_t OPJ_SIZE_T;
typedef int OPJ_BOOL;

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

typedef struct opj_tcd_seg {
    OPJ_UINT32 len;
    OPJ_UINT32 numpasses;
    OPJ_UINT32 real_num_passes;
    OPJ_UINT32 maxpasses;
    OPJ_UINT32 numnewpasses;
    OPJ_UINT32 newlen;
} opj_tcd_seg_t;

typedef struct opj_tcd_seg_data_chunk {
    OPJ_BYTE *data;
    OPJ_UINT32 len;
} opj_tcd_seg_data_chunk_t;

typedef struct opj_tcd_cblk_dec {
    opj_tcd_seg_t *segs;
    opj_tcd_seg_data_chunk_t *chunks;
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 Mb;
    OPJ_UINT32 numbps;
    OPJ_UINT32 numlenbits;
    OPJ_UINT32 numnewpasses;
    OPJ_UINT32 numsegs;
    OPJ_UINT32 real_num_segs;
    OPJ_UINT32 m_current_max_segs;
    OPJ_UINT32 numchunks;
    OPJ_UINT32 numchunksalloc;
    OPJ_INT32 *decoded_data;
    OPJ_BOOL corrupted;
} opj_tcd_cblk_dec_t;

typedef struct opj_tgt_node {
    struct opj_tgt_node *parent;
    OPJ_INT32 value;
    OPJ_INT32 low;
    OPJ_UINT32 known;
} opj_tgt_node_t;

typedef struct opj_tgt_tree {
    OPJ_UINT32 numleafsh;
    OPJ_UINT32 numleafsv;
    OPJ_UINT32 numnodes;
    opj_tgt_node_t *nodes;
    OPJ_UINT32 nodes_size;
} opj_tgt_tree_t;

typedef struct opj_tcd_precinct {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 cw;
    OPJ_UINT32 ch;
    union {
        opj_tcd_cblk_enc_t *enc;
        opj_tcd_cblk_dec_t *dec;
        void *blocks;
    } cblks;
    OPJ_UINT32 block_size;
    opj_tgt_tree_t *incltree;
    opj_tgt_tree_t *imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_tcd_band {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 bandno;
    opj_tcd_precinct_t *precincts;
    OPJ_UINT32 precincts_data_size;
    OPJ_INT32 numbps;
    OPJ_FLOAT32 stepsize;
} opj_tcd_band_t;

typedef struct opj_tcd_resolution {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
    OPJ_UINT32 numbands;
    opj_tcd_band_t bands[3];
    OPJ_UINT32 win_x0;
    OPJ_UINT32 win_y0;
    OPJ_UINT32 win_x1;
    OPJ_UINT32 win_y1;
} opj_tcd_resolution_t;

typedef struct opj_tcd_tilecomp {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 compno;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    opj_tcd_resolution_t *resolutions;
    OPJ_UINT32 resolutions_size;
    OPJ_INT32 *data;
    OPJ_BOOL ownsData;
    size_t data_size_needed;
    size_t data_size;
    OPJ_INT32 *data_win;
    OPJ_UINT32 win_x0;
    OPJ_UINT32 win_y0;
    OPJ_UINT32 win_x1;
    OPJ_UINT32 win_y1;
    OPJ_SIZE_T numpix;
} opj_tcd_tilecomp_t;

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

typedef struct opj_tcd_tile {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 numcomps;
    opj_tcd_tilecomp_t *comps;
    OPJ_SIZE_T numpix;
    OPJ_FLOAT64 distotile;
    OPJ_FLOAT64 distolayer[100];
    OPJ_UINT32 packno;
} opj_tcd_tile_t;

OPJ_UINT32 compno;
opj_tcd_tilecomp_t *l_tile_comp;
opj_tccp_t *l_tccp;
opj_image_comp_t *l_img_comp;
opj_tcd_tile_t *l_tile;
OPJ_SIZE_T l_nb_elem;
OPJ_SIZE_T i;
OPJ_INT32 *l_current_ptr;

static opj_tcd_tile_t g_tile;
static opj_tccp_t *g_tccp_array;
static opj_image_comp_t *g_img_comp_array;
static opj_tcd_tilecomp_t *g_tile_comp_array;
static OPJ_INT32 **g_tile_comp_data_ptrs;
static const size_t TARGET_DATA_SIZE = 64 * 1024 * 1024; // ~64MB for desired runtime

void init_vars() {
    const OPJ_UINT32 numcomps = 3;
    const OPJ_UINT32 base_dim = (OPJ_UINT32)sqrt((double)TARGET_DATA_SIZE / (numcomps * sizeof(OPJ_INT32)));
    
    g_tile.numcomps = numcomps;
    g_tile.x0 = 0;
    g_tile.y0 = 0;
    g_tile.x1 = base_dim * 3 / 2;
    g_tile.y1 = base_dim;
    g_tile.numpix = (OPJ_SIZE_T)(g_tile.x1 - g_tile.x0) * (g_tile.y1 - g_tile.y0);
    for (int j = 0; j < 100; ++j) {
        g_tile.distolayer[j] = 1.0;
    }
    g_tile.distotile = 100.0;
    g_tile.packno = 0;

    g_tccp_array = calloc(numcomps, sizeof(opj_tccp_t));
    g_img_comp_array = calloc(numcomps, sizeof(opj_image_comp_t));
    g_tile_comp_array = calloc(numcomps, sizeof(opj_tcd_tilecomp_t));
    g_tile_comp_data_ptrs = calloc(numcomps, sizeof(OPJ_INT32*));

    for (OPJ_UINT32 c = 0; c < numcomps; ++c) {
        opj_tccp_t *tccp = &g_tccp_array[c];
        opj_image_comp_t *img_comp = &g_img_comp_array[c];
        opj_tcd_tilecomp_t *tile_comp = &g_tile_comp_array[c];

        tccp->qmfbid = (c % 2 == 0) ? 1 : 0;
        tccp->m_dc_level_shift = 128 + c * 10;
        for (int s = 0; s < 97; ++s) {
            tccp->stepsizes[s].expn = 5 + s % 10;
            tccp->stepsizes[s].mant = 1234 + s;
        }
        for (int p = 0; p < 33; ++p) {
            tccp->prcw[p] = 1 << (p % 8);
            tccp->prch[p] = 1 << (p % 8);
        }

        img_comp->dx = 1 + c;
        img_comp->dy = 1 + c;
        img_comp->w = base_dim + c * 100;
        img_comp->h = base_dim;
        img_comp->x0 = 0;
        img_comp->y0 = 0;
        img_comp->prec = 16;
        img_comp->bpp = 16;
        img_comp->sgnd = 0;
        img_comp->resno_decoded = 1;
        img_comp->factor = 0;
        img_comp->alpha = 0;

        tile_comp->x0 = 0;
        tile_comp->y0 = 0;
        tile_comp->x1 = img_comp->w;
        tile_comp->y1 = img_comp->h;
        tile_comp->compno = c;
        tile_comp->numresolutions = 5;
        tile_comp->minimum_num_resolutions = 1;
        tile_comp->resolutions_size = tile_comp->numresolutions * sizeof(opj_tcd_resolution_t);
        tile_comp->resolutions = calloc(tile_comp->numresolutions, sizeof(opj_tcd_resolution_t));
        for (OPJ_UINT32 r = 0; r < tile_comp->numresolutions; ++r) {
            opj_tcd_resolution_t *res = &tile_comp->resolutions[r];
            res->x0 = tile_comp->x0 >> r;
            res->y0 = tile_comp->y0 >> r;
            res->x1 = (tile_comp->x1 + (1 << r) - 1) >> r;
            res->y1 = (tile_comp->y1 + (1 << r) - 1) >> r;
            if (res->x0 >= res->x1 || res->y0 >= res->y1) {
                res->x0 = res->y0 = res->x1 = res->y1 = 0;
            }
            res->pw = 1U << (r + 1);
            res->ph = 1U << (r + 1);
            res->numbands = 3;
            for (int b = 0; b < 3; ++b) {
                res->bands[b].x0 = res->x0;
                res->bands[b].y0 = res->y0;
                res->bands[b].x1 = res->x1;
                res->bands[b].y1 = res->y1;
                res->bands[b].bandno = b;
                res->bands[b].numbps = 10;
                res->bands[b].stepsize = 1.0f + b;
            }
        }

        tile_comp->numpix = (OPJ_SIZE_T)(tile_comp->x1 - tile_comp->x0) * (tile_comp->y1 - tile_comp->y0);
        tile_comp->data_size_needed = tile_comp->numpix * sizeof(OPJ_INT32);
        tile_comp->data_size = tile_comp->data_size_needed;
        tile_comp->data = calloc(1, tile_comp->data_size);
        if (!tile_comp->data) abort();
        g_tile_comp_data_ptrs[c] = tile_comp->data;
        tile_comp->ownsData = 1;
        tile_comp->data_win = NULL;
        tile_comp->win_x0 = 0;
        tile_comp->win_y0 = 0;
        tile_comp->win_x1 = tile_comp->x1;
        tile_comp->win_y1 = tile_comp->y1;

        for (OPJ_SIZE_T idx = 0; idx < tile_comp->numpix; ++idx) {
            tile_comp->data[idx] = 256 + c * 50 + (idx % 100);
        }
    }

    g_tile.comps = g_tile_comp_array;

    l_tile = &g_tile;
    l_tile_comp = g_tile_comp_array;
    l_tccp = g_tccp_array;
    l_img_comp = g_img_comp_array;
    l_nb_elem = 0;
    l_current_ptr = NULL;
    compno = 0;
    i = 0;
}