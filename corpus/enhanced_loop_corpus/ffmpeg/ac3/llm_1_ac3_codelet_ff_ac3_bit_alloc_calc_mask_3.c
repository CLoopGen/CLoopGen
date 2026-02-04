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

extern const uint16_t ff_ac3_hearing_threshold_tab[50][3];
extern AC3BitAllocParameters *s;
extern int16_t *band_psd;
extern int16_t *mask;
extern int16_t excite[50];
extern int band;
extern int band_start;
extern int band_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased loop depth by eliminating conditional body nesting, flattening logic where possible
    // Original inner condition is converted into a single-pass evaluation without nested blocks
    for (band = band_start; band < band_end; band++) {
        int tmp = (s->db_per_bit > band_psd[band]) ? (s->db_per_bit - band_psd[band]) >> 2 : 0;
        excite[band] += tmp;
        int threshold = ff_ac3_hearing_threshold_tab[band >> s->sr_shift][s->sr_code];
        mask[band] = (threshold > excite[band]) ? threshold : excite[band];
    }
}
