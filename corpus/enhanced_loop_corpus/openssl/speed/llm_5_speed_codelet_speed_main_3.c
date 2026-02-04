#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < kems_algs_len; i++) {
        if (i % 2 == 0) {
            kems_doit[i]--;
        }
    }
}
