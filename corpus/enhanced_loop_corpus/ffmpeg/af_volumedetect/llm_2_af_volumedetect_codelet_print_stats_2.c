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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 65536; i += 2) {
        uint64_t val1 = vd->histogram[i] >> shift;
        nb_samples_shift += val1;
        power += (i - 32768) * (i - 32768) * val1;

        if (i + 1 < 65536) {
            uint64_t val2 = vd->histogram[i + 1] >> shift;
            nb_samples_shift += val2;
            power += (i + 1 - 32768) * (i + 1 - 32768) * val2;
        }
    }
}
