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
for (; bin < band_end; bin += 2) {
    if (bin + 1 >= band_end) break;
    int max1 = ((v) > (psd[bin]) ? (v) : (psd[bin]));
    int adr1 = ((max1 - ((v + psd[bin] + 1) >> 1)) > 255 ? 255 : (max1 - ((v + psd[bin] + 1) >> 1)));
    int temp_v1 = max1 + ff_ac3_log_add_tab[adr1];

    int max2 = ((temp_v1) > (psd[bin + 1]) ? (temp_v1) : (psd[bin + 1]));
    int adr2 = ((max2 - ((temp_v1 + psd[bin + 1] + 1) >> 1)) > 255 ? 255 : (max2 - ((temp_v1 + psd[bin + 1] + 1) >> 1)));
    v = max2 + ff_ac3_log_add_tab[adr2];
}
}
