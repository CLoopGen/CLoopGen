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
    int k = 0;
    for (i = 0; i < 4; i++) {
        float temp_sum = 0.0f;
        for (j = 0; j < pulses_nb_per_mode_tr[mode][i]; j++) {
            int abs_pos = (sig_pos[i][j] >= 0 ? sig_pos[i][j] : -sig_pos[i][j]) - 1;
            int pos = abs_pos * spacing + i;
            float val = (sig_pos[i][j] < 0) ? -1.0f : 1.0f;
            temp_sum += val;
            fixed_vector[pos] = temp_sum; // WAW dependency introduced: each write overwrites same location in sequence
        }
        if (temp_sum > 0.0f) {
            k++;
        }
    }
}
