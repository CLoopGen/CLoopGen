#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    int quant0;
    int quant1;
    float bitr;
    float bitrate;
    int bit_ctr;
    int bit_ctr_n;
    int bit_ctr_emulationprevention;
    int b8_mode_0_use[5][2];
    int mode_use_transform_8x8[5][15];
    int mode_use_transform_4x4[5][15];
    int intra_chroma_mode[4];
    int *mode_use_Bframe;
    int *bit_use_mode_Bframe;
    int bit_ctr_I;
    int bit_ctr_P;
    int bit_ctr_B;
    float bitrate_I;
    float bitrate_P;
    float bitrate_B;
    int mode_use[5][15];
    int bit_use_mode[5][15];
    int bit_use_stuffingBits[5];
    int bit_use_mb_type[5];
    int bit_use_header[5];
    int tmp_bit_use_cbp[5];
    int bit_use_coeffY[5];
    int bit_use_coeffC[5];
    int bit_use_delta_quant[5];
    int em_prev_bits_frm;
    int em_prev_bits_fld;
    int *em_prev_bits;
    int bit_ctr_parametersets;
    int bit_ctr_parametersets_n;
} StatParameters;

StatParameters *stats;
int last_mode_chroma_use[4];
int i;

void init_vars() {
    // Allocate and initialize stats structure
    stats = (StatParameters*)malloc(sizeof(StatParameters));
    if (!stats) return;

    stats->quant0 = 0;
    stats->quant1 = 0;
    stats->bitr = 0.0f;
    stats->bitrate = 0.0f;
    stats->bit_ctr = 0;
    stats->bit_ctr_n = 0;
    stats->bit_ctr_emulationprevention = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            stats->b8_mode_0_use[i][j] = 0;
        }
        for (int j = 0; j < 15; j++) {
            stats->mode_use_transform_8x8[i][j] = 0;
            stats->mode_use_transform_4x4[i][j] = 0;
            stats->mode_use[i][j] = 0;
            stats->bit_use_mode[i][j] = 0;
        }
        stats->bit_use_stuffingBits[i] = 0;
        stats->bit_use_mb_type[i] = 0;
        stats->bit_use_header[i] = 0;
        stats->tmp_bit_use_cbp[i] = 0;
        stats->bit_use_coeffY[i] = 0;
        stats->bit_use_coeffC[i] = 0;
        stats->bit_use_delta_quant[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        stats->intra_chroma_mode[i] = i + 1;
    }

    // Allocate auxiliary arrays
    stats->mode_use_Bframe = (int*)calloc(15, sizeof(int));
    stats->bit_use_mode_Bframe = (int*)calloc(15, sizeof(int));
    stats->em_prev_bits = (int*)calloc(2, sizeof(int));

    stats->bit_ctr_I = 0;
    stats->bit_ctr_P = 0;
    stats->bit_ctr_B = 0;
    stats->bitrate_I = 0.0f;
    stats->bitrate_P = 0.0f;
    stats->bitrate_B = 0.0f;
    stats->em_prev_bits_frm = 0;
    stats->em_prev_bits_fld = 0;
    stats->bit_ctr_parametersets = 0;
    stats->bit_ctr_parametersets_n = 0;

    // Initialize last_mode_chroma_use to safe values
    for (int i = 0; i < 4; i++) {
        last_mode_chroma_use[i] = 0;
    }

    i = 0;
}