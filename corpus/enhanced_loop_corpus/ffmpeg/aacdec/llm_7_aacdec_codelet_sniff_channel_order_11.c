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


extern int i;
extern int n;
extern struct elem_to_channel e2c_vec[64];
extern int next_n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_next_n = next_n;
    for (i = 1; i < n; i++) {
        if (e2c_vec[i - 1].av_position > e2c_vec[i].av_position) {
            struct elem_to_channel tmp = e2c_vec[i - 1];
            e2c_vec[i - 1] = e2c_vec[i];
            e2c_vec[i] = tmp;
            local_next_n = i;
        }
    }
    next_n = local_next_n;
}
