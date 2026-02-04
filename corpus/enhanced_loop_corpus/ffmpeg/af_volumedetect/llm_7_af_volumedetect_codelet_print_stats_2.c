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
    uint64_t local_power = power;
    uint64_t local_samples = nb_samples_shift;
    for (i = 0; i < 65536; i += 2) {
        uint64_t hist_i0 = vd->histogram[i] >> shift;
        uint64_t hist_i1 = vd->histogram[i + 1] >> shift;
        local_samples += hist_i0 + hist_i1;
        local_power += (i - 32768) * (i - 32768) * hist_i0;
        local_power += (i + 1 - 32768) * (i + 1 - 32768) * hist_i1;
    }
    nb_samples_shift = local_samples;
    power = local_power;
}
