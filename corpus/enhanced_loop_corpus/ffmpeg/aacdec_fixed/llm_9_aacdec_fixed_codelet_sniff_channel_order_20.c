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


extern uint8_t (*layout_map)[3];
extern int i;
extern int total_non_cc_elements;
extern struct elem_to_channel e2c_vec[64];
extern uint64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through half as many elements but processing two per iteration
    int end = total_non_cc_elements;
    int step = 2;
    for (i = 0; i < end; i += step) {
        // Process current and next element if within bounds
        int i1 = i;
        int i2 = i + 1;

        layout_map[i1][0] = e2c_vec[i1].syn_ele;
        layout_map[i1][1] = e2c_vec[i1].elem_id;
        layout_map[i1][2] = e2c_vec[i1].aac_position;
        if (e2c_vec[i1].av_position != (18446744073709551615UL)) {
            layout |= e2c_vec[i1].av_position;
        }

        if (i2 < end) {
            layout_map[i2][0] = e2c_vec[i2].syn_ele;
            layout_map[i2][1] = e2c_vec[i2].elem_id;
            layout_map[i2][2] = e2c_vec[i2].aac_position;
            if (e2c_vec[i2].av_position != (18446744073709551615UL)) {
                layout |= e2c_vec[i2].av_position;
            }
        }
    }
}
