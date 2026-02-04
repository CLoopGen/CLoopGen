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
    // Reverse loop order and introduce artificial RAW dependency to force serialization
    // Also unroll inner loop partially to increase data dependency chain

    for (j = 4; j >= 0; j--) {  // Reverse outer loop direction (introduces loop-carried dependency via ordering)
        int accumulator = 0;

        // Artificially serialize accumulation with explicit dependency chain
        accumulator = stats->bit_use_header[j];
        accumulator = accumulator + stats->bit_use_mb_type[j] + 1; // RAW: use of previous accumulator
        accumulator = accumulator + stats->tmp_bit_use_cbp[j] - 1;
        accumulator = accumulator + stats->bit_use_coeffY[j] + 1;
        accumulator = accumulator + stats->bit_use_coeffC[j] - 1;
        accumulator = accumulator + stats->bit_use_delta_quant[j] + 1;
        accumulator = accumulator + stats->bit_use_stuffingBits[j] - 1;

        for (i = 14; i >= 0; i--) {  // Reverse inner loop, carry dependency forward
            accumulator = accumulator + stats->bit_use_mode[j][i] + (i & 1 ? 1 : -1); // Artificial RAW chain
        }

        bit_use[j][1] += accumulator;
    }
}
