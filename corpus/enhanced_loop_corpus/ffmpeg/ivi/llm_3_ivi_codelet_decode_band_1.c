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

extern IVIBandDesc *band;
extern int i;
extern int idx1;
extern int idx2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i;
    int idx1, idx2;
    uint8_t *corr_ptr = band->corr;
    RVMapDesc *rv_map = band->rv_map;
    uint8_t *runtab = rv_map->runtab;
    int8_t *valtab = rv_map->valtab;

    // Precompute all index pairs and store them in reverse order (indirect access pattern)
    int indices[244];  // 122 * 2 max
    int num_pairs = band->num_corr;

    for (i = 0; i < num_pairs; i++) {
        indices[i * 2]     = corr_ptr[(num_pairs - 1 - i) * 2];
        indices[i * 2 + 1] = corr_ptr[(num_pairs - 1 - i) * 2 + 1];
    }

    // Process swaps using the precomputed indirect access pattern
    for (i = 0; i < num_pairs; i++) {
        idx1 = indices[i * 2];
        idx2 = indices[i * 2 + 1];

        // Strided memory access: simulate non-unit stride by accessing spaced elements
        const int stride = 3; // arbitrary stride for variation
        int s_idx1 = (idx1 * stride) % 256;
        int s_idx2 = (idx2 * stride) % 256;

        uint8_t temp_run = runtab[s_idx2];
        runtab[s_idx2] = runtab[s_idx1];
        runtab[s_idx1] = temp_run;

        int16_t temp_val = valtab[s_idx2];
        valtab[s_idx2] = valtab[s_idx1];
        valtab[s_idx1] = temp_val;

        // Update eob and esc symbols based on original indices (not strided)
        if (idx1 == rv_map->eob_sym || idx2 == rv_map->eob_sym)
            rv_map->eob_sym ^= idx1 ^ idx2;
        if (idx1 == rv_map->esc_sym || idx2 == rv_map->esc_sym)
            rv_map->esc_sym ^= idx1 ^ idx2;
    }
}
