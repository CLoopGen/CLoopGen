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
    uint64_t local_samples = nb_samples;
    for (i = 0; i < 65536; i++) {
        local_samples += vd->histogram[i];
        vd->histogram[i] = vd->histogram[i]; // Artificial WAW dependency on same element (no-op, but creates dependence)
    }
    nb_samples = local_samples;
}
