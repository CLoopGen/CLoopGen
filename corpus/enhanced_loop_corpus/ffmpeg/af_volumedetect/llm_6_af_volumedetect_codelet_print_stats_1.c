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
    uint64_t temp_sum = 0;
    for (i = 0; i < 65536; i++)
        temp_sum += vd->histogram[i];
    nb_samples += temp_sum;
}
