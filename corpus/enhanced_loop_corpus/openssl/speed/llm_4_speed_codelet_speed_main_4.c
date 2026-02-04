#include <stdio.h>

#include <inttypes.h>

extern size_t sigs_algs_len;
extern unsigned int i;
extern uint8_t sigs_doit[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sigs_algs_len == 0) return;
    for (i = 0; i < sigs_algs_len; i++) {
        sigs_doit[i]--;
    }
}
