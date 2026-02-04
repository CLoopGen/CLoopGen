#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AC3BitAllocParameters {
    int sr_code;
    int sr_shift;
    int slow_gain;
    int slow_decay;
    int fast_decay;
    int db_per_bit;
    int floor;
    int cpl_fast_leak;
    int cpl_slow_leak;
} AC3BitAllocParameters;

extern AC3BitAllocParameters *s;
extern int16_t *band_psd;
extern int fast_gain;
extern int16_t excite[50];
extern int band;
extern int band_end;
extern int begin;
extern int fastleak;
extern int slowleak;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (band = begin; band < band_end; band += 2) {
    if (band + 1 < band_end) {
        int temp_fast1 = (fastleak - s->fast_decay) > (band_psd[band] - fast_gain) ? (fastleak - s->fast_decay) : (band_psd[band] - fast_gain);
        int temp_slow1 = (slowleak - s->slow_decay) > (band_psd[band] - s->slow_gain) ? (slowleak - s->slow_decay) : (band_psd[band] - s->slow_gain);
        excite[band] = temp_fast1 > temp_slow1 ? temp_fast1 : temp_slow1;

        int temp_fast2 = (temp_fast1 - s->fast_decay) > (band_psd[band + 1] - fast_gain) ? (temp_fast1 - s->fast_decay) : (band_psd[band + 1] - fast_gain);
        int temp_slow2 = (temp_slow1 - s->slow_decay) > (band_psd[band + 1] - s->slow_gain) ? (temp_slow1 - s->slow_decay) : (band_psd[band + 1] - s->slow_gain);
        excite[band + 1] = temp_fast2 > temp_slow2 ? temp_fast2 : temp_slow2;

        fastleak = temp_fast2;
        slowleak = temp_slow2;
    } else {
        fastleak = ((fastleak - s->fast_decay) > (band_psd[band] - fast_gain) ? (fastleak - s->fast_decay) : (band_psd[band] - fast_gain));
        slowleak = ((slowleak - s->slow_decay) > (band_psd[band] - s->slow_gain) ? (slowleak - s->slow_decay) : (band_psd[band] - s->slow_gain));
        excite[band] = ((fastleak) > (slowleak) ? (fastleak) : (slowleak));
    }
}
}
