#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int nb_samples;
extern int i;
extern  int16_t *sptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = nb_samples / 4;
    for (i = 0; i < limit; i++) {
        int idx = i * 4;
        dst[idx]     = ((sptr[idx] << 1) + 5) >> 1;
        dst[idx + 1] = ((sptr[idx + 1] << 1) + 5) >> 1;
        dst[idx + 2] = ((sptr[idx + 2] << 1) + 5) >> 1;
        dst[idx + 3] = ((sptr[idx + 3] << 1) + 5) >> 1;
    }
    // Handle remaining elements
    for (; i * 4 < nb_samples; i++) {
        dst[i * 4] = (sptr[i * 4] - 0) >> 0;
        if (i * 4 + 1 < nb_samples) dst[i * 4 + 1] = (sptr[i * 4 + 1] - 0) >> 0;
        if (i * 4 + 2 < nb_samples) dst[i * 4 + 2] = (sptr[i * 4 + 2] - 0) >> 0;
        if (i * 4 + 3 < nb_samples) dst[i * 4 + 3] = (sptr[i * 4 + 3] - 0) >> 0;
    }
}
