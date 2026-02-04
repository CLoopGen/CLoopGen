#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index remapping via an auxiliary array
    // Simulate indirect access by precomputing effective indices in reverse order
    int *indices = (int*)malloc((2 * size - 1) * sizeof(int));
    int count = 0;
    for (int temp = 2 * size - 2; temp >= 0; temp--) {
        indices[count++] = temp;
    }
    for (int j = 0; j < count; j++) {
        int idx = indices[j];
        filtered_left[idx] = (left[idx + 1] + 2 * left[idx] + left[idx - 1] + 2) >> 2;
    }
    free(indices);
}
