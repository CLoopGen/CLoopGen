#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ctables[6][256];
extern uint8_t buf[16];
extern unsigned int pos;
extern unsigned int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Access buf with a fixed stride (e.g., every 2nd element) instead of sequential or symmetric indices
    // This changes spatial locality and may stress cache differently
    const unsigned int stride = 2;
    sum = 0.0;
    for (i = 0; i < ((48 + 7) / 8); i++) {
        uint8_t a = buf[(pos - i * stride) & (16 - 1)];
        uint8_t b = buf[(pos - (((48 + 7) / 8) * 2 - 1) * stride + i * stride) & (16 - 1)];
        sum += ctables[i][a] + ctables[i][b];
    }
}
