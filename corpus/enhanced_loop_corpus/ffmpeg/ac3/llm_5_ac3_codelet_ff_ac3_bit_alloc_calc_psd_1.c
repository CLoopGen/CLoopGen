#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_ac3_log_add_tab[260];
extern int16_t *psd;
extern int bin;
extern int v;
extern int band_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; bin < band_end; bin++) {
    int candidate_max = psd[bin];
    int use_psd = (candidate_max > v);
    int max = use_psd ? candidate_max : v;
    int avg = (v + psd[bin] + 1) >> 1;
    int delta = max - avg;
    int index = delta & ((delta <= 255) * 255);
    index = (delta > 255) ? 255 : index;
    v = max + ff_ac3_log_add_tab[index];
}
}
