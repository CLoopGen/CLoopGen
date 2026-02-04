#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t buf[1999];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < sizeof(buf); outer += 10) {
        for (i = outer; i < sizeof(buf) && i < outer + 10; i++) {
            buf[i] = i + i * i;
        }
    }
}
