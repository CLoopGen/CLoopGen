#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern unsigned int sym;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_count[16] = {0};
    for (unsigned int i = 0; i < codes; i++) {
        unsigned int idx = lens[i];
        local_count[idx]++;
    }
    for (int j = 0; j < 16; j++) {
        count[j] += local_count[j];
    }
}
