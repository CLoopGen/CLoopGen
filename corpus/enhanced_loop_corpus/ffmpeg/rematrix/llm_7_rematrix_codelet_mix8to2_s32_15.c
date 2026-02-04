#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t **out;
extern  int32_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        int64_t t_prev = 0;
        for (int j = 0; j < 2 && (i + j) < len; j++) {
            int idx = i + j;
            int64_t t = in[2][idx] * (int64_t)coeffp[0 * 8 + 2] + in[3][idx] * (int64_t)coeffp[0 * 8 + 3];
            int64_t combined_t = t + t_prev;
            out[0][idx] = (((combined_t + in[0][idx] * (int64_t)coeffp[0 * 8 + 0] + 
                            in[4][idx] * (int64_t)coeffp[0 * 8 + 4] + 
                            in[6][idx] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
            out[1][idx] = (((combined_t + in[1][idx] * (int64_t)coeffp[1 * 8 + 1] + 
                            in[5][idx] * (int64_t)coeffp[1 * 8 + 5] + 
                            in[7][idx] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
            t_prev = t;
        }
    }
}
