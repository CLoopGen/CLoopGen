#include <stdlib.h>
#include <stdint.h>

int *bounding_values;
int16_t temp_16[8];
int temp_32[8];

void init_vars() {
    bounding_values = (int*)aligned_alloc(32, 8 * sizeof(int));
    
    for (int i = 0; i < 8; i++) {
        temp_16[i] = i;
        bounding_values[i] = i * 100;
    }
}