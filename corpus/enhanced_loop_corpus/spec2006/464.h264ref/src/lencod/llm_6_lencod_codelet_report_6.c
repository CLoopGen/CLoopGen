#include <stdio.h>

#include <inttypes.h>

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

extern StatParameters *stats;
extern int bit_use[5][2];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_bit_use[5] = {0}; // Local accumulation to eliminate WAW dependencies

    for (j = 0; j < 5; j++) {
        // Introduce local reduction to remove loop-carried WAW on bit_use[j][1]
        temp_bit_use[j] += stats->bit_use_header[j];
        temp_bit_use[j] += stats->bit_use_mb_type[j];
        temp_bit_use[j] += stats->tmp_bit_use_cbp[j];
        temp_bit_use[j] += stats->bit_use_coeffY[j];
        temp_bit_use[j] += stats->bit_use_coeffC[j];
        temp_bit_use[j] += stats->bit_use_delta_quant[j];
        temp_bit_use[j] += stats->bit_use_stuffingBits[j];

        for (i = 0; i < 15; i++) {
            temp_bit_use[j] += stats->bit_use_mode[j][i]; // Accumulate mode bits
        }

        // Final write to shared array after all reads are done — eliminates WAW
        bit_use[j][1] += temp_bit_use[j];
    }
}
