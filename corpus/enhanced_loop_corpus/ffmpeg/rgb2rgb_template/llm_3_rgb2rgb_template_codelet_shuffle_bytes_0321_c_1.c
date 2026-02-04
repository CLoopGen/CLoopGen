#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[15];
    int indices[] = {0, 2, 4, 6, 8, 10, 12, 14};
    for (; idx < 8; idx += 4) {
        register unsigned int v, g = v & 16711935;
        v &= 4278255360U;
        int mapped_idx = indices[idx];      // Indirect access via index array
        arr[mapped_idx] = 42;
        if (idx + 1 < 8) arr[indices[idx + 1]] = 43;
        if (idx + 2 < 8) arr[indices[idx + 2]] = 44;
        if (idx + 3 < 8) arr[indices[idx + 3]] = 45;
    }
}
