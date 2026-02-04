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
    int bit_slice;
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

int bit_use[5][2] = {{0}};

int i = 0;
int j = 0;

StatParameters *stats;

void init_vars() {
    stats = (StatParameters *)calloc(1, sizeof(StatParameters));
    
    if (!stats) return;

    stats->quant0 = 1;
    stats->quant1 = 2;
    stats->bitr = 1.5f;
    stats->bitrate = 2.0f;
    stats->bit_ctr = 100;
    stats->bit_ctr_n = 90;
    stats->bit_slice = 5;
    stats->bit_ctr_emulationprevention = 3;

    for (int j_idx = 0; j_idx < 5; j_idx++) {
        for (int i_idx = 0; i_idx < 2; i_idx++) {
            stats->b8_mode_0_use[j_idx][i_idx] = (j_idx + i_idx) % 10;
        }
    }

    for (int j_idx = 0; j_idx < 5; j_idx++) {
        for (int i_idx = 0; i_idx < 15; i_idx++) {
            stats->mode_use_transform_8x8[j_idx][i_idx] = (j_idx * 15 + i_idx) % 7;
            stats->mode_use_transform_4x4[j_idx][i_idx] = (j_idx * 15 + i_idx) % 5;
            stats->mode_use[j_idx][i_idx] = (j_idx * 15 + i_idx) % 3;
            stats->bit_use_mode[j_idx][i_idx] = (j_idx * 15 + i_idx) % 20 + 1;
        }
    }

    for (int i_idx = 0; i_idx < 4; i_idx++) {
        stats->intra_chroma_mode[i_idx] = i_idx % 3;
    }

    stats->mode_use_Bframe = (int *)calloc(100, sizeof(int));
    stats->bit_use_mode_Bframe = (int *)calloc(100, sizeof(int));
    for (int i_idx = 0; i_idx < 100; i_idx++) {
        stats->mode_use_Bframe[i_idx] = i_idx % 4;
        stats->bit_use_mode_Bframe[i_idx] = (i_idx % 15) + 1;
    }

    stats->bit_ctr_I = 500;
    stats->bit_ctr_P = 400;
    stats->bit_ctr_B = 300;
    stats->bitrate_I = 1.0f;
    stats->bitrate_P = 1.5f;
    stats->bitrate_B = 0.8f;

    for (int j_idx = 0; j_idx < 5; j_idx++) {
        stats->bit_use_stuffingBits[j_idx] = (j_idx + 1) * 10;
        stats->bit_use_mb_type[j_idx] = (j_idx + 1) * 15;
        stats->bit_use_header[j_idx] = (j_idx + 1) * 5;
        stats->tmp_bit_use_cbp[j_idx] = (j_idx + 1) * 12;
        stats->bit_use_coeffY[j_idx] = (j_idx + 1) * 8;
        stats->bit_use_coeffC[j_idx] = (j_idx + 1) * 6;
        stats->bit_use_delta_quant[j_idx] = (j_idx + 1) * 3;
    }

    stats->em_prev_bits_frm = 1000;
    stats->em_prev_bits_fld = 900;
    stats->em_prev_bits = (int *)calloc(2, sizeof(int));
    stats->em_prev_bits[0] = 1000;
    stats->em_prev_bits[1] = 900;

    stats->bit_ctr_parametersets = 200;
    stats->bit_ctr_parametersets_n = 180;
}