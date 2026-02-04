#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(length * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < length; j++) {
        indices[j] = j;
    }
    // Simulate shuffled access pattern: reverse order
    for (i = 0; i < length; i++) {
        int idx = indices[length - 1 - i]; // reverse traversal
        uint32_t a = p1[idx];
        int32_t b = p2[idx];
        a -= b >> 1;
        p1[idx] = a;
        p2[idx] = a + b;
    }
    free(indices);
}
