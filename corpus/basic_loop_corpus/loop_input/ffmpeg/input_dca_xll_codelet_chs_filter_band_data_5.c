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

static int32_t *alloc_aligned_int32_array(size_t count) {
    int32_t *ptr;
    if (posix_memalign((void**)&ptr, 32, count * sizeof(int32_t)) != 0) {
        return NULL;
    }
    return ptr;
}

void init_vars() {
    c = (DCAXllChSet*)calloc(1, sizeof(DCAXllChSet));
    b = &c->bands[0];

    c->nchannels = 8;

    for (int ch = 0; ch < 8; ch++) {
        b->msb_sample_buffer[ch] = alloc_aligned_int32_array(16777216 / 8); // ~16.7M per channel to get total ~134MB
        if (!b->msb_sample_buffer[ch]) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
    }

    for (int ch = 0; ch < 8; ch++) {
        tmp[ch] = NULL;
    }

    i = 0;
}