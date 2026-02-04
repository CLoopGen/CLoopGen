#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

typedef unsigned char OPJ_BYTE;

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

typedef int OPJ_BOOL;

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

union {
    opj_tcd_cblk_enc_t *enc;
    opj_tcd_cblk_dec_t *dec;
    void *blocks;
};


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

typedef float OPJ_FLOAT32;

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

typedef size_t OPJ_SIZE_T;

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

extern OPJ_UINT32 compno;
extern opj_tcd_tilecomp_t *l_tile_comp;
extern opj_tccp_t *l_tccp;
extern opj_image_comp_t *l_img_comp;
extern opj_tcd_tile_t *l_tile;
extern OPJ_SIZE_T l_nb_elem;
extern OPJ_SIZE_T i;
extern OPJ_INT32 *l_current_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (compno = 0; compno < l_tile->numcomps; compno++) {
        l_current_ptr = l_tile_comp->data;
        OPJ_SIZE_T width = (OPJ_SIZE_T)(l_tile_comp->x1 - l_tile_comp->x0);
        OPJ_SIZE_T height = (OPJ_SIZE_T)(l_tile_comp->y1 - l_tile_comp->y0);
        l_nb_elem = width * height;

        if (l_tccp->qmfbid == 1) {
            for (OPJ_SIZE_T y = 0; y < height; ++y) {
                for (OPJ_SIZE_T x = 0; x < width; ++x) {
                    OPJ_SIZE_T idx = y * width + x;
                    l_current_ptr[idx] -= l_tccp->m_dc_level_shift;
                }
            }
        } else {
            OPJ_FLOAT32* float_ptr = (OPJ_FLOAT32*)l_tile_comp->data;
            for (i = 0; i < l_nb_elem; ++i) {
                float_ptr[i] = (OPJ_FLOAT32)(l_tile_comp->data[i] - l_tccp->m_dc_level_shift);
            }
        }
        ++l_img_comp;
        ++l_tccp;
        ++l_tile_comp;
    }
}
