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
    uint64_t sum1 = 0, sum2 = 0;
    for (i = 0; i < 65536; i += 2) {
        sum1 += vd->histogram[i];
        if (i + 1 < 65536) {
            sum2 += vd->histogram[i + 1];
        }
    }
    nb_samples += sum1 + sum2;
}
