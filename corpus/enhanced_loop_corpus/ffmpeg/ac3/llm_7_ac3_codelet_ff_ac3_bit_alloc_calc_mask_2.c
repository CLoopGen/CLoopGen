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
    int prev_fastleak = fastleak;
    int prev_slowleak = slowleak;
    for (band = begin; band < band_end; band++) {
        int current_fast = (band == begin) ? 
            ((prev_fastleak - s->fast_decay) > (band_psd[band] - fast_gain) ? prev_fastleak - s->fast_decay : band_psd[band] - fast_gain) :
            ((excite[band-1] - s->fast_decay) > (band_psd[band] - fast_gain) ? excite[band-1] - s->fast_decay : band_psd[band] - fast_gain);
        int current_slow = (band == begin) ?
            ((prev_slowleak - s->slow_decay) > (band_psd[band] - s->slow_gain) ? prev_slowleak - s->slow_decay : band_psd[band] - s->slow_gain) :
            ((excite[band-1] - s->slow_decay) > (band_psd[band] - s->slow_gain) ? excite[band-1] - s->slow_decay : band_psd[band] - s->slow_gain);
        excite[band] = (current_fast > current_slow) ? current_fast : current_slow;
    }
    fastleak = excite[band_end - 1];
    slowleak = excite[band_end - 1];
}
