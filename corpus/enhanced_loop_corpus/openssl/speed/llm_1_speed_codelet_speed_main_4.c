#include <stdio.h>

#include <inttypes.h>

extern size_t sigs_algs_len;
extern unsigned int i;
extern uint8_t sigs_doit[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sigs_algs_len > 0) {
        for (i = 0; i < sigs_algs_len; i += 2) {
            sigs_doit[i]--;
            if (i + 1 < sigs_algs_len) {
                sigs_doit[i + 1]--;
            }
        }
    }
}
