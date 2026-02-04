#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

JPGContext *c;
int i;

static uint8_t static_buf[1024 * 1024] __attribute__((aligned(32)));
static int16_t static_block_data[6][64] __attribute__((aligned(32)));
static uint8_t static_idct_permutation[64];
static uint8_t static_permutated[64];
static uint8_t static_raster_end[64];
static const uint8_t default_scantable[64] = { 0 };
static int16_t static_vlc_table[2][1024][2];

void init_vars(void) {
    c = malloc(sizeof(JPGContext));
    if (!c) exit(1);

    c->bdsp.clear_block = NULL;
    c->bdsp.clear_blocks = NULL;
    c->bdsp.fill_block_tab[0] = NULL;
    c->bdsp.fill_block_tab[1] = NULL;

    c->idsp.put_pixels_clamped = NULL;
    c->idsp.put_signed_pixels_clamped = NULL;
    c->idsp.add_pixels_clamped = NULL;
    c->idsp.idct = NULL;
    c->idsp.idct_put = NULL;
    c->idsp.idct_add = NULL;
    memcpy(c->idsp.idct_permutation, static_idct_permutation, 64);
    c->idsp.perm_type = FF_IDCT_PERM_NONE;
    c->idsp.mpeg4_studio_profile = 0;

    c->scantable.scantable = default_scantable;
    memcpy(c->scantable.permutated, static_permutated, 64);
    memcpy(c->scantable.raster_end, static_raster_end, 64);

    for (int idx = 0; idx < 2; idx++) {
        c->dc_vlc[idx].bits = 9;
        c->dc_vlc[idx].table = static_vlc_table[idx];
        c->dc_vlc[idx].table_size = 512;
        c->dc_vlc[idx].table_allocated = 512;

        c->ac_vlc[idx].bits = 9;
        c->ac_vlc[idx].table = static_vlc_table[idx];
        c->ac_vlc[idx].table_size = 512;
        c->ac_vlc[idx].table_allocated = 512;
    }

    for (int j = 0; j < 3; j++)
        c->prev_dc[j] = 0;

    for (int b = 0; b < 6; b++)
        memcpy(c->block[b], static_block_data[b], 64 * sizeof(int16_t));

    c->buf = static_buf;
}