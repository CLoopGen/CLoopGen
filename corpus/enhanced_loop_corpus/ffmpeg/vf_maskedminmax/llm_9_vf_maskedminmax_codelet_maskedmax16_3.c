#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern  uint16_t *f1;
extern  uint16_t *f2;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (int x = 0; x < w; x++) {
        int sum_abs_diff = 0;
        int count = 0;
        for (int k = -1; k <= 1; k++) {
            int nx = x + k;
            if (nx >= 0 && nx < w) {
                int diff_f2 = src[nx] - f2[nx];
                int diff_f1 = src[nx] - f1[nx];
                int abs_f2 = diff_f2 >= 0 ? diff_f2 : -diff_f2;
                int abs_f1 = diff_f1 >= 0 ? diff_f1 : -diff_f1;
                sum_abs_diff += (abs_f2 > abs_f1) ? abs_f2 : abs_f1;
                count++;
            }
        }
        int avg = count > 0 ? sum_abs_diff / count : 0;
        dst[x] = avg > ((src[x] - f1[x]) >= 0 ? (src[x] - f1[x]) : (-(src[x] - f1[x]))) ? f2[x] : f1[x];
    }
}
