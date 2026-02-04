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
    int k;
    for (i = 0; i < 4; i++) {
        int pulse_count = pulses_nb_per_mode_tr[mode][i];
        for (j = 0; j < pulse_count; j++) {
            int abs_sig = sig_pos[i][j];
            int sign = 1;
            if (abs_sig < 0) {
                abs_sig = -abs_sig;
                sign = -1;
            }
            int pos = (abs_sig - 1) * spacing + i;
            fixed_vector[pos] += sign;
        }
    }
}
