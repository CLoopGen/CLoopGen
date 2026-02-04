#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < kems_algs_len; j++) {
        for (unsigned int i = 0; i <= j; i++) {
            if (i < kems_algs_len) {
                kems_doit[i]--;
            }
        }
    }
}
