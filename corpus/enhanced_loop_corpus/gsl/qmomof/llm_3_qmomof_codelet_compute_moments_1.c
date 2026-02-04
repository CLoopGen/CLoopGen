#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided read from v with direct write to chebmo
    // Access v with a stride of 2 (simulating irregular access pattern) and map to consecutive odd indices in chebmo
    // Note: We assume v has sufficient elements (at least 24, accessed as v[2*i]) for realism in strided access
    for (i = 0; i < 12; i++) {
        chebmo[2 * i + 1] = v[2 * i];  // Strided read from v, writing to same location in chebmo
    }
}
