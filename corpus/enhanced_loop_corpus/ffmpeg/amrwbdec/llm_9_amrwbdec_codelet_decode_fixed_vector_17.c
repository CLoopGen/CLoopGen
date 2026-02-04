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
    for (i = 0; i < 2; i++) {
        for (j = 0; j < pulses_nb_per_mode_tr[mode][i]; j += 2) {
            int pos1 = (((sig_pos[i][j]) >= 0 ? sig_pos[i][j] : -sig_pos[i][j]) - 1) * spacing + i;
            fixed_vector[pos1] += sig_pos[i][j] < 0 ? -1.0 : 1.0;

            if (j + 1 < pulses_nb_per_mode_tr[mode][i]) {
                int pos2 = (((sig_pos[i][j+1]) >= 0 ? sig_pos[i][j+1] : -sig_pos[i][j+1]) - 1) * spacing + i;
                fixed_vector[pos2] += sig_pos[i][j+1] < 0 ? -1.0 : 1.0;
            }
        }
    }
    for (i = 2; i < 4; i++) {
        for (j = 0; j < pulses_nb_per_mode_tr[mode][i]; j++) {
            int sig = sig_pos[i][j];
            int abs_sig = sig < 0 ? -sig : sig;
            int pos = (abs_sig - 1) * spacing + i;
            fixed_vector[pos] += sig < 0 ? -1.0 : 1.0;
        }
    }
}
