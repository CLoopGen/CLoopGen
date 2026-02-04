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
    res = &data[pred_order];
    int block_size = n >> pmax;
    for (i = 0; i < parts; i++) {
        uint64_t sum = 0;
        int count = 0;
        int current_index = (pred_order + i * block_size);
        int limit = current_index + block_size;
        if (kmax) {
            sum = (1LL + k) * block_size;
            for (int idx = current_index; idx < limit && idx < n; idx++) {
                sum += data[idx] >> k;
                count++;
            }
        } else {
            for (int idx = current_index; idx < limit && idx < n; idx++) {
                sum += data[idx];
                count++;
            }
        }
        sums[k][i] = sum;
    }
}
}
