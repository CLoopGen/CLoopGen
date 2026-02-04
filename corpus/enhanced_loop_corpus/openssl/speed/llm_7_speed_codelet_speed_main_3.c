#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_value = kems_doit[0];
    for (i = 1; i < kems_algs_len; i++) {
        uint8_t current = kems_doit[i];
        kems_doit[i] = prev_value - 1;
        prev_value = current;
    }
    if (kems_algs_len > 0) {
        kems_doit[0]--;
    }
}
