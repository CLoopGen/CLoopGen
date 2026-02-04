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
extern int last_mode_chroma_use[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the loop into nested loops
    // Here we use a 2x2 nested structure to iterate over 4 elements (0 to 3)
    for (int outer = 0; outer < 2; outer++)
        for (int inner = 0; inner < 2; inner++)
            last_mode_chroma_use[outer * 2 + inner] = stats->intra_chroma_mode[outer * 2 + inner];
}
