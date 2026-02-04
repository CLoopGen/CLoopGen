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
    int local_max_ccr = max_ccr;
    int local_max_eng = max_eng;
    int updated_index = hf->index;
    for (i = 0; i <= 6; i++) {
        eng = energy[i << 1];
        ccr = energy[(i << 1) + 1];
        if (ccr <= 0)
            continue;
        ccr = (ccr * ccr + (1 << 14)) >> 15;
        diff = ccr * local_max_eng - eng * local_max_ccr;
        if (diff > 0) {
            local_max_ccr = ccr;
            local_max_eng = eng;
            updated_index = i;
        }
    }
    max_ccr = local_max_ccr;
    max_eng = local_max_eng;
    hf->index = updated_index;
}
