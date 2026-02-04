#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            p[idx] = (uint8_t)(w >> (8 * idx));
        }
    }
}
