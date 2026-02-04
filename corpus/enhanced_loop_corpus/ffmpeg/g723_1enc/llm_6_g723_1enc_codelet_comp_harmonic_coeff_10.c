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
    int temp_eng, temp_ccr;
    for (i = 0; i <= 6; i++) {
        temp_eng = energy[i << 1];
        temp_ccr = energy[(i << 1) + 1];
        if (temp_ccr <= 0)
            continue;
        temp_ccr = (temp_ccr * temp_ccr + (1 << 14)) >> 15;
        diff = temp_ccr * max_eng - temp_eng * max_ccr;
        if (diff > 0) {
            max_ccr = temp_ccr;
            max_eng = temp_eng;
            hf->index = i;
        }
    }
}
