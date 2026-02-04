#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (i = 1; i < order; i += step) {
    int16_t base = nlsf[i - 1] + min_delta[i];
    int16_t limit = (base > 32767) ? 32767 : base;
    nlsf[i] = (nlsf[i] > limit) ? nlsf[i] : limit;
    if (i + 1 < order) {
        base = nlsf[i] + min_delta[i + 1];
        limit = (base > 32767) ? 32767 : base;
        nlsf[i + 1] = (nlsf[i + 1] > limit) ? nlsf[i + 1] : limit;
    }
}
}
