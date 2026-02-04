#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pmax;
extern int kmax;
extern  uint32_t *data;
extern int n;
extern int pred_order;
extern uint64_t sums[32][256];
extern int i;
extern int k;
extern int parts;
extern  uint32_t *res;
extern  uint32_t *res_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= kmax; k++) {
    ptrdiff_t stride = (n >> pmax);
    for (i = 0; i < parts; i++) {
        res = &data[pred_order + i * stride];
        res_end = &data[pred_order + (i + 1) * stride];
        if (res_end > &data[n]) res_end = &data[n];
        if (kmax) {
            uint64_t sum = (1LL + k) * (res_end - res);
            for (uint32_t* ptr = res; ptr < res_end; ptr++) {
                sum += (*ptr) >> k;
            }
            sums[k][i] = sum;
        } else {
            uint64_t sum = 0;
            for (uint32_t* ptr = res; ptr < res_end; ptr++) {
                sum += *ptr;
            }
            sums[k][i] = sum;
        }
    }
}
}
