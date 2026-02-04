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
