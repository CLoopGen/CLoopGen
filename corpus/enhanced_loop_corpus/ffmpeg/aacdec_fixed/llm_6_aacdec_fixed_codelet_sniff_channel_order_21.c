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



void loop(){
    for (i = 1; i < n; i++) {
        uint64_t prev_av = e2c_vec[i - 1].av_position;
        uint64_t curr_av = e2c_vec[i].av_position;
        if (prev_av > curr_av) {
            struct elem_to_channel temp = e2c_vec[i];
            e2c_vec[i] = e2c_vec[i - 1];
            e2c_vec[i - 1] = temp;
            next_n = i;
        }
    }
}
