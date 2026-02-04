#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HFParam {
    int index;
    int gain;
} HFParam;

HFParam *hf;
int ccr;
int eng;
int max_ccr;
int max_eng;
int diff;
int energy[15];
int i;

void init_vars() {
    hf = (HFParam*)malloc(sizeof(HFParam));
    if (!hf) exit(1);
    hf->index = 0;
    hf->gain = 0;

    max_ccr = 100;
    max_eng = 5000;

    for (int idx = 0; idx < 15; idx++) {
        energy[idx] = rand() % 2000;
    }
}