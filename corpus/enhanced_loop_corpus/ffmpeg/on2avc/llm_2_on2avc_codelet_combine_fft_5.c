#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int *array = &tmp;
    int index = 0;
    for (half = len2; array[index] > 1; half <<= 1, tmp >>= 1) {
        index = (index + 1) % 1; // Simulate indirect access pattern (trivially strided by 1)
    }
}
