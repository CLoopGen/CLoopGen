#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DCAXllBand {
    int decor_enabled;
    int orig_order[8];
    int decor_coeff[4];
    int adapt_pred_order[8];
    int highest_pred_order;
    int fixed_pred_order[8];
    int adapt_refl_coeff[8][16];
    int dmix_embedded;
    int lsb_section_size;
    int nscalablelsbs[8];
    int bit_width_adjust[8];
    int32_t *msb_sample_buffer[8];
    int32_t *lsb_sample_buffer[8];
} DCAXllBand;

typedef struct DCAXllChSet {
    int nchannels;
    int residual_encode;
    int pcm_bit_res;
    int storage_bit_res;
    int freq;
    int primary_chset;
    int dmix_coeffs_present;
    int dmix_embedded;
    int dmix_type;
    int hier_chset;
    int hier_ofs;
    int dmix_coeff[128];
    int dmix_scale[16];
    int dmix_scale_inv[16];
    int ch_mask;
    int ch_remap[8];
    int nfreqbands;
    int nabits;
    DCAXllBand bands[2];
    int seg_common;
    int rice_code_flag[8];
    int bitalloc_hybrid_linear[8];
    int bitalloc_part_a[8];
    int bitalloc_part_b[8];
    int nsamples_part_a[8];
    int32_t deci_history[8][8] __attribute__((aligned(32)));
    unsigned int sample_size[3];
    int32_t *sample_buffer[3];
} DCAXllChSet;

DCAXllChSet *c;
DCAXllBand *b;
int i;
int32_t *tmp[8];

static int32_t **g_msb_buffers;
static int32_t **g_lsb_buffers;
static int32_t **g_tmp_buffers;
static DCAXllChSet g_chset;
static DCAXllBand g_band;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB per buffer (1M elements * 4 bytes)

    g_msb_buffers = calloc(8, sizeof(int32_t*));
    g_lsb_buffers = calloc(8, sizeof(int32_t*));
    g_tmp_buffers = calloc(8, sizeof(int32_t*));

    for (int j = 0; j < 8; j++) {
        g_msb_buffers[j] = aligned_alloc(32, data_size * sizeof(int32_t));
        g_lsb_buffers[j] = aligned_alloc(32, data_size * sizeof(int32_t));
        g_tmp_buffers[j]   = aligned_alloc(32, data_size * sizeof(int32_t));
    }

    c = &g_chset;
    b = &g_band;

    c->nchannels = 8;
    for (int j = 0; j < 8; j++) {
        c->bands[0].orig_order[j] = j;
        c->bands[1].orig_order[j] = (j + 4) % 8;
    }

    for (int j = 0; j < 8; j++) {
        b->orig_order[j] = j;
        b->msb_sample_buffer[j] = g_msb_buffers[j];
        b->lsb_sample_buffer[j] = g_lsb_buffers[j];
    }

    for (int j = 0; j < 8; j++) {
        tmp[j] = g_tmp_buffers[j];
    }

    i = 0;
}