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
for (i = 0; i <= 6; i++) {
    eng = energy[i << 1];
    ccr = energy[(i << 1) + 1];
    ccr = (ccr > 0) ? ((ccr * ccr + (1 << 14)) >> 15) : 0;
    if (ccr == 0) continue;
    diff = ccr * max_eng - eng * max_ccr;
    max_ccr = (diff > 0) ? ccr : max_ccr;
    max_eng = (diff > 0) ? eng : max_eng;
    hf->index = (diff > 0) ? i : hf->index;
}
}
