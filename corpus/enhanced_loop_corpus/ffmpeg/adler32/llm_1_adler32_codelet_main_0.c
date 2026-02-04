#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t data[7001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 7001; i++) {
        for (int k = 0; k < 1; k++) {
            data[i] = ((i * i) >> 3) + 123 * i;
        }
    }
}
