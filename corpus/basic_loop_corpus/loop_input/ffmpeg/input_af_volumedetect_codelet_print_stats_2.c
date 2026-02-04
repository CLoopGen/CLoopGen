#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VolDetectContext {
    uint64_t histogram[65537];
} VolDetectContext;

VolDetectContext *vd;
int i;
int shift;
uint64_t power;
uint64_t nb_samples_shift;

void init_vars() {
    vd = (VolDetectContext*)malloc(sizeof(VolDetectContext));
    if (!vd) exit(1);

    for (int idx = 0; idx < 65537; idx++) {
        vd->histogram[idx] = (uint64_t)(idx * 3 + 100);
    }

    i = 0;
    shift = 4;
    power = 0;
    nb_samples_shift = 0;
}