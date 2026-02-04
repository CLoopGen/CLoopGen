#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t *dummy_array = (int8_t*)calloc(size2, sizeof(int8_t));
    if (!dummy_array) return;
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j += 2) {  // Strided access: step of 2
            dummy_array[j] += 1;
        }
        for (j = i + 2; j < size2; j += 2) {  // Second pass with offset stride
            dummy_array[j] -= 1;
        }
    }
    free(dummy_array);
}
