#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 0;
    for (i = 0; i < kems_algs_len; i++) {
        temp = kems_doit[i];
        kems_doit[i] = temp - 1;
    }
}
