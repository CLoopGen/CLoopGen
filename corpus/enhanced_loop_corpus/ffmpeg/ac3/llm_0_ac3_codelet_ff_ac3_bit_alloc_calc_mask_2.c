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
    for (band = begin; band < band_end; band++) {
        int inner_temp_fast = fastleak;
        int inner_temp_slow = slowleak;
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            inner_temp_fast = ((inner_temp_fast - s->fast_decay) > (band_psd[band] - fast_gain) ? (inner_temp_fast - s->fast_decay) : (band_psd[band] - fast_gain));
            inner_temp_slow = ((inner_temp_slow - s->slow_decay) > (band_psd[band] - s->slow_gain) ? (inner_temp_slow - s->slow_decay) : (band_psd[band] - s->slow_gain));
        }
        fastleak = inner_temp_fast;
        slowleak = inner_temp_slow;
        excite[band] = ((fastleak) > (slowleak) ? (fastleak) : (slowleak));
    }
}
