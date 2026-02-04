#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct IVIHuffDesc {
    int32_t num_rows;
    uint8_t xbits[16];
} IVIHuffDesc;

typedef struct IVIHuffTab {
    int32_t tab_sel;
    VLC *tab;
    IVIHuffDesc cust_desc;
    VLC cust_tab;
} IVIHuffTab;

typedef struct RVMapDesc {
    uint8_t eob_sym;
    uint8_t esc_sym;
    uint8_t runtab[256];
    int8_t valtab[256];
} RVMapDesc;

typedef struct IVIMbInfo {
    int16_t xpos;
    int16_t ypos;
    uint32_t buf_offs;
    uint8_t type;
    uint8_t cbp;
    int8_t q_delta;
    int8_t mv_x;
    int8_t mv_y;
    int8_t b_mv_x;
    int8_t b_mv_y;
} IVIMbInfo;

typedef struct IVITile {
    int xpos;
    int ypos;
    int width;
    int height;
    int mb_size;
    int is_empty;
    int data_size;
    int num_MBs;
    IVIMbInfo *mbs;
    IVIMbInfo *ref_mbs;
} IVITile;

typedef void (InvTransformPtr)(const int32_t *, int16_t *, ptrdiff_t, const uint8_t *);

typedef void (DCTransformPtr)(const int32_t *, int16_t *, ptrdiff_t, int);

typedef struct IVIBandDesc {
    int plane;
    int band_num;
    int width;
    int height;
    int aheight;
    const uint8_t *data_ptr;
    int data_size;
    int16_t *buf;
    int16_t *ref_buf;
    int16_t *b_ref_buf;
    int16_t *bufs[4];
    ptrdiff_t pitch;
    int is_empty;
    int mb_size;
    int blk_size;
    int is_halfpel;
    int inherit_mv;
    int inherit_qdelta;
    int qdelta_present;
    int quant_mat;
    int glob_quant;
    const uint8_t *scan;
    int scan_size;
    IVIHuffTab blk_vlc;
    int num_corr;
    uint8_t corr[122];
    int rvmap_sel;
    RVMapDesc *rv_map;
    int num_tiles;
    IVITile *tiles;
    InvTransformPtr *inv_transform;
    int transform_size;
    DCTransformPtr *dc_transform;
    int is_2d_trans;
    int32_t checksum;
    int checksum_present;
    int bufsize;
    const uint16_t *intra_base;
    const uint16_t *inter_base;
    const uint8_t *intra_scale;
    const uint8_t *inter_scale;
} IVIBandDesc;

IVIBandDesc *band;
int i;
int idx1;
int idx2;

static uint8_t static_runtab[256];
static int8_t static_valtab[256];
static uint8_t static_corr[122];
static RVMapDesc static_rv_map;

void init_vars() {
    for (int j = 0; j < 256; j++) {
        static_runtab[j] = (uint8_t)j;
        static_valtab[j] = (int8_t)(j - 128);
    }
    for (int j = 0; j < 122; j++) {
        static_corr[j] = (uint8_t)((j * 73 + 41) % 256);
    }

    static_rv_map.eob_sym = 255;
    static_rv_map.esc_sym = 254;
    for (int j = 0; j < 256; j++) {
        static_rv_map.runtab[j] = static_runtab[j];
        static_rv_map.valtab[j] = static_valtab[j];
    }

    band = (IVIBandDesc*)calloc(1, sizeof(IVIBandDesc));
    band->num_corr = 122;
    band->rv_map = &static_rv_map;
    for (int j = 0; j < 122; j++) {
        band->corr[j] = static_corr[j];
    }
}