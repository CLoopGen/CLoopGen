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
for (int step = 0; bin + step < band_end; step++) {
    int idx = bin + step;
    int max = ((v) > (psd[idx]) ? (v) : (psd[idx]));
    int adr = ((max - ((v + psd[idx] + 1) >> 1)) > (255) ? (255) : (max - ((v + psd[idx] + 1) >> 1)));
    v = max + ff_ac3_log_add_tab[adr];
    bin = idx + 1;
}
}
