#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VolDetectContext {
    uint64_t histogram[65537];
} VolDetectContext;

extern VolDetectContext *vd;
extern int i;
extern uint64_t nb_samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    uint64_t sum = 0;
    for (i = 0; i < 65536; i += 2)
        sum += vd->histogram[i];
    for (i = 1; i < 65536; i += 2)
        sum += vd->histogram[i];
    nb_samples = sum;
}
