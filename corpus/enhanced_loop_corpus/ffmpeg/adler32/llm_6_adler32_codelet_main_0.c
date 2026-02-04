#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t data[7001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[7001];
    for (i = 0; i < 7001; i++) {
        temp[i] = ((i * i) >> 3) + 123 * i;
    }
    for (i = 0; i < 7001; i++) {
        data[i] = temp[i];
    }
}
