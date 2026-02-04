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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 65535; i >= 0; i--) {
        uint64_t shifted_hist = vd->histogram[i] >> shift;
        nb_samples_shift += shifted_hist;
        int64_t diff = i - 32768;
        power += diff * diff * shifted_hist;
    }
}
