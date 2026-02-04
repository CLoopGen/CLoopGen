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

static RVMapDesc g_rv_map;
static IVIBandDesc g_band;

IVIBandDesc *band = &g_band;

int i;
int idx1;
int idx2;

void init_vars() {
    for (int j = 0; j < 256; j++) {
        g_rv_map.runtab[j] = j;
        g_rv_map.valtab[j] = j - 128;
    }
    g_rv_map.eob_sym = 255;
    g_rv_map.esc_sym = 254;

    g_band.rv_map = &g_rv_map;
    g_band.num_corr = 61;
    for (int j = 0; j < 61; j++) {
        g_band.corr[j * 2] = rand() % 256;
        g_band.corr[j * 2 + 1] = rand() % 256;
    }

    g_band.buf = malloc(1024 * 1024 * sizeof(int16_t));
    g_band.ref_buf = malloc(1024 * 1024 * sizeof(int16_t));
    g_band.b_ref_buf = malloc(1024 * 1024 * sizeof(int16_t));
    g_band.bufs[0] = g_band.buf;
    g_band.bufs[1] = g_band.ref_buf;
    g_band.bufs[2] = g_band.b_ref_buf;
    g_band.bufs[3] = NULL;
    g_band.pitch = 1024;
    g_band.width = 512;
    g_band.height = 512;
    g_band.mb_size = 16;
    g_band.blk_size = 8;
    g_band.is_halfpel = 0;
    g_band.inherit_mv = 0;
    g_band.inherit_qdelta = 0;
    g_band.qdelta_present = 0;
    g_band.quant_mat = 0;
    g_band.glob_quant = 12;
    g_band.scan = NULL;
    g_band.scan_size = 0;
    g_band.plane = 0;
    g_band.band_num = 0;
    g_band.data_size = 0;
    g_band.is_empty = 0;
    g_band.transform_size = 0;
    g_band.is_2d_trans = 1;
    g_band.checksum = 0;
    g_band.checksum_present = 0;
    g_band.bufsize = 0;
    g_band.intra_base = NULL;
    g_band.inter_base = NULL;
    g_band.intra_scale = NULL;
    g_band.inter_scale = NULL;
    g_band.num_tiles = 0;
    g_band.tiles = NULL;
    g_band.inv_transform = NULL;
    g_band.dc_transform = NULL;
    g_band.blk_vlc.tab_sel = 0;
    g_band.blk_vlc.tab = NULL;
    g_band.blk_vlc.cust_desc.num_rows = 0;
    for (int j = 0; j < 16; j++) {
        g_band.blk_vlc.cust_desc.xbits[j] = 0;
    }
    g_band.blk_vlc.cust_tab.bits = 0;
    g_band.blk_vlc.cust_tab.table = NULL;
    g_band.blk_vlc.cust_tab.table_size = 0;
    g_band.blk_vlc.cust_tab.table_allocated = 0;
    g_band.rvmap_sel = 0;
}