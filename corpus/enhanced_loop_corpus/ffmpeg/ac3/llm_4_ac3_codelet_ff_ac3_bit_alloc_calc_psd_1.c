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
    int sum = v + psd[bin] + 1;
    int mid = sum >> 1;
    int max = v;
    if (psd[bin] > v) {
        max = psd[bin];
    }
    int diff = max - mid;
    int adr = diff;
    if (diff > 255) {
        adr = 255;
    }
    v = max + ff_ac3_log_add_tab[adr];
}
}
