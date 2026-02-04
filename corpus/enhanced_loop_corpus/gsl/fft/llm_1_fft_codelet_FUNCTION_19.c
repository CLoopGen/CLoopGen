#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *array = (char*)calloc(2 * m, sizeof(char));
    // Initialize consecutive write pattern
    for (i = 0; i < m; i++) {
        array[i] = (char)(i & 0xFF);
    }
    // Consecutive read access with offset interleaving
    for (i = 0; i < m; i++) {
        volatile char val1 = array[i];           // Forward sequential access
        volatile char val2 = array[m - 1 - i];   // Reverse sequential access
    }
    free(array);
}
