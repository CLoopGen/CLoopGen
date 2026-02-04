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
    int32_t *indices = (int32_t*)malloc(length * sizeof(int32_t));
    if (!indices) return;
    for (int j = 0; j < length; j++) {
        indices[j] = j;
    }
    for (i = 0; i < length; i++) {
        int idx = indices[i];
        uint32_t a = p1[idx];
        uint32_t b = p2[idx];
        p1[idx] = b - a;
    }
    free(indices);
}
