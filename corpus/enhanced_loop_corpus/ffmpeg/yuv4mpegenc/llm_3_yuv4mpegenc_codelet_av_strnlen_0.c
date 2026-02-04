#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++)
        indices[i] = i;

    char found = 0;
    for (i = 0; i < len && !found; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx])
            found = 1;
    }
    if (i > 0) i = indices[i - 1] + 1; // Adjust i to reflect original loop's final value
    free(indices);
}
