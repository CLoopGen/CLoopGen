#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    static const int index_map[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int size = sizeof(index_map) / sizeof(index_map[0]);
    for (i = size - 1; i >= 0; i--) {
        int idx = index_map[i];
        if (idx >= 1) {
            in[idx] += in[idx - 1];
        }
    }
}
