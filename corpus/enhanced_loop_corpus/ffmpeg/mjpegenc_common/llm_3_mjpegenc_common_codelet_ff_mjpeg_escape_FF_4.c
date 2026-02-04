#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with computed indices)
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < size; j++) {
        indices[j] = j; // Simulate indirect addressing (could be shuffled or reordered in real use cases)
    }
    for (i = 0; i < size; i++) {
        int idx = indices[i]; // Use indirection
        if (buf[idx] == 255)
            ff_count++;
    }
    free(indices);
}
