#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct elem_to_channel {
    uint64_t av_position;
    uint8_t syn_ele;
    uint8_t elem_id;
    uint8_t aac_position;
};

uint8_t (*layout_map)[3];
int i;
int total_non_cc_elements;
struct elem_to_channel e2c_vec[64];
uint64_t layout;

void init_vars() {
    // Set total_non_cc_elements to 64 since e2c_vec has fixed size 64
    total_non_cc_elements = 64;

    // Allocate layout_map as a 2D array of [64][3]
    layout_map = (uint8_t(*)[3])calloc(64, sizeof(uint8_t[3]));

    // Initialize layout to 0
    layout = 0;

    // Initialize e2c_vec with sample data
    for (int idx = 0; idx < 64; idx++) {
        e2c_vec[idx].syn_ele = (uint8_t)(idx % 256);
        e2c_vec[idx].elem_id = (uint8_t)((idx * 3) % 256);
        e2c_vec[idx].aac_position = (uint8_t)((idx * 7) % 256);
        e2c_vec[idx].av_position = (idx % 10 == 0) ? (18446744073709551615UL) : (1ULL << (idx % 64));
    }

    // Initialize loop counter
    i = 0;
}