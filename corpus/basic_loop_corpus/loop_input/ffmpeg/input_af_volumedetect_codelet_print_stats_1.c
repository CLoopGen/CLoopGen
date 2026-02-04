#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VolDetectContext {
    uint64_t histogram[65537];
} VolDetectContext;

VolDetectContext *vd;
int i;
uint64_t nb_samples;

void init_vars() {
    vd = (VolDetectContext *)calloc(1, sizeof(VolDetectContext));
    if (!vd) exit(1);
    for (int j = 0; j < 65536; j++) {
        vd->histogram[j] = 1500;
    }
    nb_samples = 0;
    i = 0;
}