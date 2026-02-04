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
    uint64_t temp_power = 0;
    uint64_t temp_samples = 0;
    for (i = 0; i < 65536; i++) {
        uint64_t shifted_hist = vd->histogram[i] >> shift;
        temp_samples += shifted_hist;
        temp_power += (i - 32768) * (i - 32768) * shifted_hist;
    }
    nb_samples_shift = temp_samples;
    power = temp_power;
}
