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
    for (i = 0; i < parts; i++) {
        res_end = &data[n >> pmax] + i * (n >> pmax);
        uint64_t sum = 0;
        int effective_k = kmax ? k : 0;
        sum += (1LL + effective_k) * (res_end - res);
        for (; res < res_end; res++) {
            sum += (*res) >> effective_k;
        }
        sums[k][i] = sum;
    }
}
}
