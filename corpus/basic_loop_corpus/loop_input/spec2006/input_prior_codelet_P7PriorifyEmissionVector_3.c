#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num;
float *ret_mix;
int q;
float mix[200];

void init_vars() {
    num = 200;

    ret_mix = (float *)aligned_alloc(32, num * sizeof(float));
    if (!ret_mix) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        mix[i] = 1.0f + i * 0.5f;
        ret_mix[i] = 0.0f;
    }
}