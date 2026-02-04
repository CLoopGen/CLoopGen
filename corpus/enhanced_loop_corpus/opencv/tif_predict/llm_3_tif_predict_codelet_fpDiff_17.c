#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access pattern via a local array accessed in strided manner
    int buffer[16] = {0}; // Small local buffer to simulate data access
    for (count = cc; count > stride; count -= stride) {
        switch (stride) {
            default:
                {
                    tmsize_t i;
                    for (i = stride - 4; i > 0; i--) {
                        // Consecutive write with modulo indexing: creates strided logical access over fixed buffer
                        size_t idx = (i * 5) % 16; // Strided access pattern on buffer
                        buffer[idx] += 1;
                    }
                }
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                // Direct sequential access to buffer to reflect different memory behavior
                for (tmsize_t j = 0; j < 16; j += stride ? stride : 1) {
                    volatile int val = buffer[j];
                }
                break;
        }
    }
}
