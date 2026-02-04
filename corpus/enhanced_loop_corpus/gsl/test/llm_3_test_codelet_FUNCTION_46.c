#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480,
                        512, 544, 576, 608, 640, 672, 704, 736, 768, 800, 832, 864, 896, 928,
                        960, 992, 1024};
    size_t arr[1027];
    size_t num_accesses = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_accesses; i++) {
        arr[indices[i]] = indices[i];
    }
}
