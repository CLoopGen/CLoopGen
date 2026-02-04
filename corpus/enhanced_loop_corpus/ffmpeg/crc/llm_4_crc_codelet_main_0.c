#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t buf[1999];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(buf); i++) {
        if ((i & 1) == 0) {
            buf[i] = i + i * i;
        } else {
            buf[i] = 0;
        }
    }
}
