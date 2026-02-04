#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HFParam {
    int index;
    int gain;
} HFParam;

extern HFParam *hf;
extern int ccr;
extern int eng;
extern int max_ccr;
extern int max_eng;
extern int diff;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[7] = {0, 2, 4, 6, 8, 10, 12}; // Strided access pattern with stride 2
    for (i = 0; i < 7; i++) {
        int base_idx = indices[i];
        eng = energy[base_idx];
        ccr = energy[base_idx + 1];
        if (ccr <= 0)
            continue;
        ccr = (ccr * ccr + (1 << 14)) >> 15;
        diff = ccr * max_eng - eng * max_ccr;
        if (diff > 0) {
            max_ccr = ccr;
            max_eng = eng;
            hf->index = i;
        }
    }
}
