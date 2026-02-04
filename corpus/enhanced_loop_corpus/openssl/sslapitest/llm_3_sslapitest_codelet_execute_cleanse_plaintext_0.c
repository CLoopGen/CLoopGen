#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120};
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < sizeof(cbuf); i++) {
        size_t idx = indices[(i / num_indices) % num_indices];
        size_t pos = (i + idx) % sizeof(cbuf);
        cbuf[pos] = i & 255;
    }
}
