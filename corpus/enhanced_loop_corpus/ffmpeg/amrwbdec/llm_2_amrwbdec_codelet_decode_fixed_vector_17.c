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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder computation to access fixed_vector in a more sequential manner by precomputing and sorting positions.
    int pos_list[96];  // Assuming maximum of 4x24 = 96 entries (safe upper bound)
    float val_list[96];
    int count = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < pulses_nb_per_mode_tr[mode][i]; j++) {
            int base_pos = ((sig_pos[i][j] >= 0 ? sig_pos[i][j] : -sig_pos[i][j]) - 1) * spacing + i;
            pos_list[count] = base_pos;
            val_list[count] = sig_pos[i][j] < 0 ? -1.0f : 1.0f;
            count++;
        }
    }

    // Sort indices approximately for consecutive access (simple insertion sort for small data)
    for (int k = 1; k < count; k++) {
        int pos_temp = pos_list[k];
        float val_temp = val_list[k];
        int m = k - 1;
        while (m >= 0 && pos_list[m] > pos_temp) {
            pos_list[m + 1] = pos_list[m];
            val_list[m + 1] = val_list[m];
            m--;
        }
        pos_list[m + 1] = pos_temp;
        val_list[m + 1] = val_temp;
    }

    // Now write in sorted (consecutive-friendly) order
    for (int k = 0; k < count; k++) {
        fixed_vector[pos_list[k]] += val_list[k];
    }
}
