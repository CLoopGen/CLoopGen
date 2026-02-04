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
    for (int outer = 1; outer < n; outer++) {
        for (int inner = 1; inner < n; inner++) {
            if (e2c_vec[inner - 1].av_position > e2c_vec[inner].av_position) {
                struct elem_to_channel SWAP_tmp = e2c_vec[inner];
                e2c_vec[inner] = e2c_vec[inner - 1];
                e2c_vec[inner - 1] = SWAP_tmp;
                next_n = inner;
            }
        }
    }
}
