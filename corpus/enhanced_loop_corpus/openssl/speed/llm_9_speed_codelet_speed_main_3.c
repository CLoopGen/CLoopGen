#include <stdio.h>

#include <inttypes.h>

extern size_t kems_algs_len;
extern unsigned int i;
extern uint8_t kems_doit[111];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (kems_algs_len + 3) / 4; i++) {
        uint8_t idx = i * 4;
        if (idx < kems_algs_len) {
            kems_doit[idx]--;
        }
        if (idx + 1 < kems_algs_len) {
            kems_doit[idx + 1]--;
        }
        if (idx + 2 < kems_algs_len) {
            kems_doit[idx + 2]--;
        }
        if (idx + 3 < kems_algs_len) {
            kems_doit[idx + 3]--;
        }
    }
}
