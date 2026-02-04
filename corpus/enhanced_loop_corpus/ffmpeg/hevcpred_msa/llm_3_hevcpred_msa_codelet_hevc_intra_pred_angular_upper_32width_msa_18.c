#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ref_tmp;
extern  uint8_t *src_left_tmp;
extern int32_t h_cnt;
extern int32_t inv_angle_val;
extern int32_t inv_angle_val_loop;
extern int32_t last;
extern int32_t offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        offset = (inv_angle_val_loop + 128) >> 8;
        // Modified to consecutive reverse access in src_left_tmp using a sliding window
        // Simulate local sequential buffer fill by accessing nearby elements consecutively
        ref_tmp[h_cnt] = src_left_tmp[offset + (h_cnt & 3)]; // Small stride based on loop index
        inv_angle_val_loop += inv_angle_val;
    }
}
