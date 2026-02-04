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
    if (begin < band_end) {
        for (int outer_band = begin; outer_band < band_end; outer_band += 2) {
            for (band = outer_band; band < band_end && band < outer_band + 2; band++) {
                fastleak = ((fastleak - s->fast_decay) > (band_psd[band] - fast_gain) ? (fastleak - s->fast_decay) : (band_psd[band] - fast_gain));
                slowleak = ((slowleak - s->slow_decay) > (band_psd[band] - s->slow_gain) ? (slowleak - s->slow_decay) : (band_psd[band] - s->slow_gain));
                excite[band] = ((fastleak) > (slowleak) ? (fastleak) : (slowleak));
            }
        }
    }
}
