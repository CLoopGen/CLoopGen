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
    res_end = &data[n >> pmax];
    for (i = 0; i < parts; i++) {
        if (kmax) {
            uint64_t sum = (1LL + k) * (res_end - res);
            while (res < res_end)
                sum += *(res++) >> k;
            sums[k][i] = sum;
        } else {
            uint64_t sum = 0;
            while (res < res_end)
                sum += *(res++);
            sums[k][i] = sum;
        }
        res_end += n >> pmax;
    }
}

}
