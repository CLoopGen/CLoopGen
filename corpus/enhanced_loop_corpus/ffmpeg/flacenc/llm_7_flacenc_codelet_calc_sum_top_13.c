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
    uint32_t* base_res = &data[pred_order];
    ptrdiff_t segment_size = n >> pmax;
    for (i = 0; i < parts; i++) {
        res = base_res + i * segment_size;
        res_end = res + segment_size;
        uint64_t sum = 0;
        if (kmax) {
            sum = (1LL + k) * segment_size;
            for (ptrdiff_t j = 0; j < segment_size; j++) {
                sum += (res[j]) >> k;
            }
        } else {
            for (ptrdiff_t j = 0; j < segment_size; j++) {
                sum += res[j];
            }
        }
        sums[k][i] = sum;
    }
}
}
