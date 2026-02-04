#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char primitive[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    char *indices[4096];
    for (int i = 0; i < 4096; i++) {
        indices[i] = &primitive[i];
    }
    int idx = 0;
    for (p = indices[idx]; idx < 4096 && (*p == ' ' || *p == '\t'); idx++, p = indices[idx])
        ;
    // Clamp p to valid range if all were whitespace
    if (idx >= 4096)
        p = primitive + 4096;
}
