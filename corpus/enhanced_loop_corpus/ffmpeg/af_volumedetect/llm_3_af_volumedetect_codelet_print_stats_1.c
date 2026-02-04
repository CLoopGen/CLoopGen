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
    // Variant 2: Indirect memory access using an index array (simulating irregular access)
    uint64_t sum = 0;
    int indices[65536];
    for (i = 0; i < 65536; i++)
        indices[i] = i; // Populate index array in order (could be randomized or reordered in real use cases)
    for (i = 0; i < 65536; i++)
        sum += vd->histogram[indices[i]];
    nb_samples = sum;
}
