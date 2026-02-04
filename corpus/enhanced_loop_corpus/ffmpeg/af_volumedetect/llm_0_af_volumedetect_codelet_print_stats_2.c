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
    for (int outer = 0; outer < 2; outer++) {
        for (i = outer * 32768; i < (outer + 1) * 32768 && i < 65536; i++) {
            nb_samples_shift += vd->histogram[i] >> shift;
            power += (i - 32768) * (i - 32768) * (vd->histogram[i] >> shift);
        }
    }
}
