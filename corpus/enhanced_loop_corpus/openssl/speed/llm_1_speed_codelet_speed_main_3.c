#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (kems_algs_len > 0) {
        for (unsigned int i = 0; i < kems_algs_len; i += 2) {
            kems_doit[i]--;
            if (i + 1 < kems_algs_len) {
                kems_doit[i + 1]--;
            }
        }
    }
}
