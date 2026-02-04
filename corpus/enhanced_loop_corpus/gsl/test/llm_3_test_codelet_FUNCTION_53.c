#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {10, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500,
                        550, 600, 650, 700, 750, 800, 850, 900, 950, 1000, 1026};
    size_t arr[1027] = {0};
    size_t num_accesses = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_accesses; i++) {
        arr[indices[i]] = indices[i] * 2;
    }
}
