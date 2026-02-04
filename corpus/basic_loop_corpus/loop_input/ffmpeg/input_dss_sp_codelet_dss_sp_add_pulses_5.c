#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct DssSpSubframe {
    int16_t gain;
    int32_t combined_pulse_pos;
    int16_t pulse_pos[7];
    int16_t pulse_val[7];
};

uint16_t dss_sp_fixed_cb_gain[64];
int16_t dss_sp_pulse_val[8];

int32_t *vector_buf;
struct DssSpSubframe *sf;
int i;

void init_vars() {
    // Allocate and initialize dss_sp_fixed_cb_gain
    for (int idx = 0; idx < 64; idx++) {
        dss_sp_fixed_cb_gain[idx] = (uint16_t)(idx * 500);
    }

    // Initialize dss_sp_pulse_val
    for (int idx = 0; idx < 8; idx++) {
        dss_sp_pulse_val[idx] = (int16_t)(idx * 1000);
    }

    // Allocate vector_buf with size ~16MB to ensure loop runtime around 0.01s
    // Use 4M int32_t elements (4 bytes each -> 16MB)
    const size_t vector_buf_size = 4 * 1024 * 1024;
    vector_buf = (int32_t*)calloc(vector_buf_size, sizeof(int32_t));
    if (!vector_buf) exit(1);

    // Allocate and initialize sf
    sf = (struct DssSpSubframe*)malloc(sizeof(struct DssSpSubframe));
    if (!sf) exit(1);

    sf->gain = 32; // within [0,63] valid index for dss_sp_fixed_cb_gain

    // Initialize pulse_pos within bounds of vector_buf_size
    for (int j = 0; j < 7; j++) {
        sf->pulse_pos[j] = (j * 1999) % vector_buf_size; // ensure in-bounds
    }

    // Initialize pulse_val: indices into dss_sp_pulse_val[0..7]
    for (int j = 0; j < 7; j++) {
        sf->pulse_val[j] = (j + 1) % 8; // valid indices 1..7
    }
}