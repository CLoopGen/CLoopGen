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
    for (i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            int idx = i * 256 + j;
            if (idx >= 65536) break;
            nb_samples_shift += vd->histogram[idx] >> shift;
            power += (idx - 32768) * (idx - 32768) * (vd->histogram[idx] >> shift);
        }
    }
}
