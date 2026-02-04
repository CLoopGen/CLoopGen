#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    int local_d[16];
    int idx = 0;
    for (y = 0; y < 4; y++)
        for (x = 0; x < 4; x++) {
            int a_idx = x + y * a_linesize[0];
            int b_idx = x + y * b_linesize[0];
            local_d[idx] = a_data[0][a_idx] - b_data[0][b_idx];
            idx++;
        }
    for (int i = 0; i < 16; i++) {
        ret += local_d[i] * local_d[i];
    }
}
