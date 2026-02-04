#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum AVMatrixEncoding {
    AV_MATRIX_ENCODING_NONE,
    AV_MATRIX_ENCODING_DOLBY,
    AV_MATRIX_ENCODING_DPLII,
    AV_MATRIX_ENCODING_DPLIIX,
    AV_MATRIX_ENCODING_DPLIIZ,
    AV_MATRIX_ENCODING_DOLBYEX,
    AV_MATRIX_ENCODING_DOLBYHEADPHONE,
    AV_MATRIX_ENCODING_NB
};


typedef struct FilterParams {
    uint8_t order;
    uint8_t shift;
    int32_t state[8];
    int coeff_bits;
    int coeff_shift;
} FilterParams;

typedef struct ChannelParams {
    FilterParams filter_params[2];
    int32_t coeff[2][8];
    int16_t huff_offset;
    int32_t sign_huff_offset;
    uint8_t codebook;
    uint8_t huff_lsbs;
} ChannelParams;

typedef struct SubStream {
    uint8_t restart_seen;
    uint16_t noise_type;
    uint8_t min_channel;
    uint8_t max_channel;
    uint8_t max_matrix_channel;
    uint8_t ch_assign[8];
    uint64_t mask;
    enum AVMatrixEncoding matrix_encoding;
    ChannelParams channel_params[8];
    uint8_t noise_shift;
    uint32_t noisegen_seed;
    uint8_t data_check_present;
    uint8_t param_presence_flags;
    uint8_t num_primitive_matrices;
    uint8_t matrix_out_ch[8];
    uint8_t lsb_bypass[8];
    int32_t matrix_coeff[8][8] __attribute__((aligned(32)));
    uint8_t matrix_noise_shift[8];
    uint8_t quant_step_size[8];
    uint16_t blocksize;
    uint16_t blockpos;
    int8_t output_shift[8];
    int32_t lossless_check_data;
} SubStream;

extern SubStream *s;
extern unsigned int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = s->min_channel; ch <= s->max_channel; ch++) {
        ChannelParams *cp = &s->channel_params[ch];
        cp->filter_params[0].order = 0;
        cp->filter_params[1].order = 0;
        cp->filter_params[0].shift = cp->filter_params[0].order; // RAW: shift depends on order
        cp->filter_params[1].shift = cp->filter_params[1].order;
        cp->huff_offset = 0;
        cp->sign_huff_offset = -(1 << 23);
        cp->codebook = 0;
        cp->huff_lsbs = 24;

        // Introduce WAW dependency: write then overwrite huff_lsbs based on previous value
        cp->huff_lsbs = (cp->huff_lsbs > 8) ? cp->huff_lsbs - 8 : cp->huff_lsbs;
    }
}
