#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < kems_algs_len; i += 2) {
        if (i < kems_algs_len) {
            kems_doit[i]--;
        }
    }
}
