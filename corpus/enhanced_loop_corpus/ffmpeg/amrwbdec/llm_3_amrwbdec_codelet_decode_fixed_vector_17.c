#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum Mode {
    MODE_6k60 = 0,
    MODE_8k85,
    MODE_12k65,
    MODE_14k25,
    MODE_15k85,
    MODE_18k25,
    MODE_19k85,
    MODE_23k05,
    MODE_23k85,
    MODE_SID,
    SP_LOST = 14,
    NO_DATA
};


extern  uint8_t pulses_nb_per_mode_tr[][4];
extern float *fixed_vector;
extern  enum Mode mode;
extern int sig_pos[4][6];
extern int spacing;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Instead of random access, reorganize the loop to process all signal components with a fixed stride over modes
    // Process data in terms of spacing stride first, then offset within the pattern

    for (int s = 0; s < spacing; s++) {
        // For each stride phase s, collect contributions where (base_index + i) % spacing == s
        for (i = 0; i < 4; i++) {
            for (j = 0; j < pulses_nb_per_mode_tr[mode][i]; j++) {
                int abs_sig = sig_pos[i][j] >= 0 ? sig_pos[i][j] : -sig_pos[i][j];
                int base_index = (abs_sig - 1) * spacing;
                int pos = base_index + i;

                // Only process if this position falls into current stride phase
                if ((pos % spacing) == s) {
                    fixed_vector[pos] += sig_pos[i][j] < 0 ? -1.0f : 1.0f;
                }
            }
        }
    }
}
