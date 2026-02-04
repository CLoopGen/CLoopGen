#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VolDetectContext {
    uint64_t histogram[65537];
} VolDetectContext;

extern VolDetectContext *vd;
extern int i;
extern int shift;
extern uint64_t power;
extern uint64_t nb_samples_shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 65536; i++) {
        uint64_t hist_shifted = vd->histogram[i] >> shift;
        if (hist_shifted == 0) continue;
        nb_samples_shift += hist_shifted;
        int64_t diff = i - 32768;
        power += diff * diff * hist_shifted;
    }
}
