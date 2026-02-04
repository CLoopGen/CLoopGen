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

uint8_t pulses_nb_per_mode_tr[][4] = {
    {3, 4, 5, 6},
    {4, 5, 6, 7},
    {5, 6, 7, 8},
    {6, 7, 8, 9},
    {7, 8, 9, 10},
    {8, 9, 10, 11},
    {9, 10, 11, 12},
    {10, 11, 12, 13},
    {11, 12, 13, 14},
    {12, 13, 14, 15},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

float *fixed_vector;
enum Mode mode;
int sig_pos[4][6];
int spacing;
int i;
int j;

void init_vars() {
    mode = MODE_6k60;
    spacing = 128;

    for (int idx_i = 0; idx_i < 4; idx_i++) {
        for (int idx_j = 0; idx_j < 6; idx_j++) {
            sig_pos[idx_i][idx_j] = (idx_i * 6 + idx_j + 1) * ((idx_i + idx_j) % 3 == 0 ? -1 : 1);
        }
    }

    size_t vector_size = 16 * 1024 * 1024;
    fixed_vector = (float*)calloc(vector_size, sizeof(float));
}