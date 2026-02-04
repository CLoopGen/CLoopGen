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
    // Variant 1: Consecutive memory access with pointer arithmetic for better locality
    int16_t *excite_ptr = &excite[band_start];
    int16_t *mask_ptr = &mask[band_start];
    int16_t *psd_ptr = &band_psd[band_start];
    const uint16_t (*threshold)[3] = ff_ac3_hearing_threshold_tab;
    int shift = s->sr_shift;
    int sr_code = s->sr_code;
    int db_per_bit = s->db_per_bit;
    int len = band_end - band_start;

    for (int i = 0; i < len; i++) {
        int tmp = db_per_bit - psd_ptr[i];
        if (tmp > 0) {
            excite_ptr[i] += tmp >> 2;
        }
        int idx = (band_start + i) >> shift;
        mask_ptr[i] = (threshold[idx][sr_code] > excite_ptr[i]) ? threshold[idx][sr_code] : excite_ptr[i];
    }
}
