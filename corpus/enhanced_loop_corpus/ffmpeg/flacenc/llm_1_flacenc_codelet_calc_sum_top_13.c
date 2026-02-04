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
    for (i = 0; i < parts; i++) {
        res = &data[pred_order + i * (n >> pmax)];
        res_end = res + (n >> pmax);
        uint64_t sum = 0;
        if (kmax) {
            sum = (1LL + k) * (res_end - res);
            for (int j = 0; j < (res_end - res); j++) {
                sum += (res[j] >> k);
            }
        } else {
            for (int j = 0; j < (res_end - res); j++) {
                sum += res[j];
            }
        }
        sums[k][i] = sum;
    }
}
}
