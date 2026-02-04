#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulating gather access)
    // Precompute valid indices and access through an index array
    char *base = message;
    size_t count = 0;
    size_t temp_len = 0;
    while (base[temp_len] != '\x00') temp_len++;

    // Allocate small index buffer on stack (assume max reasonable size)
    size_t indices[512];
    for (size_t i = 0; i < temp_len && i < 512; i++) {
        indices[count] = i;
        count++;
    }

    // Access characters indirectly using the index array
    for (size_t j = 0; j < count; j++) {
        size_t idx = indices[j];
        if (base[idx] == '\n')
            base[idx] = ' ';
    }
}
