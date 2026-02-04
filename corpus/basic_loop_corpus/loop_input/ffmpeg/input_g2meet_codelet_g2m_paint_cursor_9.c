#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct ElsDecCtx {
    const uint8_t *in_buf;
    unsigned int x;
    size_t data_size;
    int j;
    int t;
    int diff;
    int err;
} ElsDecCtx;

typedef struct ElsRungNode {
    uint8_t rung;
    uint16_t next_index;
} ElsRungNode;

typedef struct ElsUnsignedRung {
    uint8_t prefix_rung[11];
    ElsRungNode *rem_rung_list;
    size_t rung_list_size;
    uint16_t avail_index;
} ElsUnsignedRung;

struct ePICPixListElem {
    struct ePICPixListElem *next;
    uint32_t pixel;
    uint8_t rung;
};

typedef struct ePICPixHashElem {
    uint32_t pix_id;
    struct ePICPixListElem *list;
} ePICPixHashElem;

typedef struct ePICPixHash {
    ePICPixHashElem *bucket[256];
    int bucket_size[256];
    int bucket_fill[256];
} ePICPixHash;

typedef struct ePICContext {
    ElsDecCtx els_ctx;
    int next_run_pos;
    ElsUnsignedRung unsigned_rung;
    uint8_t W_flag_rung;
    uint8_t N_flag_rung;
    uint8_t W_ctx_rung[256];
    uint8_t N_ctx_rung[512];
    uint8_t nw_pred_rung[256];
    uint8_t ne_pred_rung[256];
    uint8_t prev_row_rung[14];
    uint8_t runlen_zeroes[14];
    uint8_t runlen_one;
    int stack_pos;
    uint32_t stack[1024];
    ePICPixHash hash;
} ePICContext;

typedef void (*op_fill_func)(uint8_t *, uint8_t, ptrdiff_t, int);

typedef struct BlockDSPContext {
    void (*clear_block)(int16_t *);
    void (*clear_blocks)(int16_t *);
    op_fill_func fill_block_tab[2];
} BlockDSPContext;

enum idct_permutation_type {
    FF_IDCT_PERM_NONE,
    FF_IDCT_PERM_LIBMPEG2,
    FF_IDCT_PERM_SIMPLE,
    FF_IDCT_PERM_TRANSPOSE,
    FF_IDCT_PERM_PARTTRANS,
    FF_IDCT_PERM_SSE2
};

typedef struct IDCTDSPContext {
    void (*put_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*put_signed_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*add_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*idct)(int16_t *);
    void (*idct_put)(uint8_t *, ptrdiff_t, int16_t *);
    void (*idct_add)(uint8_t *, ptrdiff_t, int16_t *);
    uint8_t idct_permutation[64];
    enum idct_permutation_type perm_type;
    int mpeg4_studio_profile;
} IDCTDSPContext;

typedef struct ScanTable {
    const uint8_t *scantable;
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct JPGContext {
    BlockDSPContext bdsp;
    IDCTDSPContext idsp;
    ScanTable scantable;
    VLC dc_vlc[2];
    VLC ac_vlc[2];
    int prev_dc[3];
    int16_t block[6][64] __attribute__((aligned(32)));
    uint8_t *buf;
} JPGContext;

typedef struct G2MContext {
    ePICContext ec;
    JPGContext jc;
    int version;
    int compression;
    int width;
    int height;
    int bpp;
    int orig_width;
    int orig_height;
    int tile_width;
    int tile_height;
    int tiles_x;
    int tiles_y;
    int tile_x;
    int tile_y;
    int got_header;
    uint8_t *framebuf;
    int framebuf_stride;
    unsigned int framebuf_allocated;
    uint8_t *synth_tile;
    uint8_t *jpeg_tile;
    uint8_t *epic_buf;
    uint8_t *epic_buf_base;
    int tile_stride;
    int epic_buf_stride;
    int old_tile_w;
    int old_tile_h;
    int swapuv;
    uint8_t *kempf_buf;
    uint8_t *kempf_flags;
    uint8_t *cursor;
    int cursor_stride;
    int cursor_fmt;
    int cursor_w;
    int cursor_h;
    int cursor_x;
    int cursor_y;
    int cursor_hot_x;
    int cursor_hot_y;
} G2MContext;

G2MContext *c;
uint8_t *dst;
int stride;
int i;
int j;
int w;
int h;
uint8_t *cursor;

static uint8_t *simulated_framebuf = NULL;
static uint8_t *simulated_cursor_data = NULL;

void init_vars() {
    w = 1024;
    h = 768;
    stride = w * 3;
    c = (G2MContext*)calloc(1, sizeof(G2MContext));
    if (!c) exit(1);

    simulated_framebuf = (uint8_t*)calloc(h, stride);
    if (!simulated_framebuf) exit(1);
    dst = simulated_framebuf;

    c->cursor_w = w;
    c->cursor_h = h;
    c->cursor_stride = w * 4;
    simulated_cursor_data = (uint8_t*)calloc(h, c->cursor_stride);
    if (!simulated_cursor_data) exit(1);
    c->cursor = simulated_cursor_data;
    cursor = c->cursor;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int idx_c = y * c->cursor_stride + x * 4;
            cursor[idx_c + 0] = 128;
            cursor[idx_c + 1] = (x * 7 + y * 3) % 256;
            cursor[idx_c + 2] = (x * 5 + y * 5) % 256;
            cursor[idx_c + 3] = (x * 3 + y * 7) % 256;
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int idx_d = y * stride + x * 3;
            dst[idx_d + 0] = (x * 11 + y * 13) % 256;
            dst[idx_d + 1] = (x * 13 + y * 17) % 256;
            dst[idx_d + 2] = (x * 17 + y * 19) % 256;
        }
    }
}