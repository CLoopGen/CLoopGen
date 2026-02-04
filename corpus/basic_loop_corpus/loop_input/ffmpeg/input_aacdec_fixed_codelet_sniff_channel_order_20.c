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
    // Allocate layout_map to hold at least 64 entries to match e2c_vec and avoid out-of-bounds
    total_non_cc_elements = 64;
    layout_map = (uint8_t(*)[3])calloc(total_non_cc_elements, sizeof(uint8_t[3]));

    // Initialize e2c_vec with valid data
    for (int idx = 0; idx < total_non_cc_elements; idx++) {
        e2c_vec[idx].syn_ele = (uint8_t)(idx + 1);
        e2c_vec[idx].elem_id = (uint8_t)((idx * 7) % 255);
        e2c_vec[idx].aac_position = (uint8_t)((idx * 13) % 255);
        // Set av_position to non-ULLONG_MAX about half the time to trigger layout update
        e2c_vec[idx].av_position = (idx % 2 == 0) ? (1UL << (idx % 64)) : 18446744073709551615UL;
    }

    // Initialize layout to zero
    layout = 0;
}