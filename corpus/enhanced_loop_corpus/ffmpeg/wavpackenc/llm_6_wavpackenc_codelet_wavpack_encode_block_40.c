#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int i;
extern int nb_samples;
extern int32_t lor;
extern int32_t diff;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int32_t local_lor = 0;
    int32_t local_diff = 0;
    for (i = 0; i < nb_samples; i++) {
        int32_t sl = samples_l[i];
        int32_t sr = samples_r[i];
        local_lor |= sl | sr;
        local_diff |= sl - sr;
        if (local_lor && local_diff) {
            lor = local_lor;
            diff = local_diff;
            break;
        }
    }
    // Propagate local accumulators to global only if loop completed or broken
    if (!(lor && diff)) {
        lor = local_lor;
        diff = local_diff;
    }
}
