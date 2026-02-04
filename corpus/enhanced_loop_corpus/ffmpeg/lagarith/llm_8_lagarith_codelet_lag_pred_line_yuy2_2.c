#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int L;
extern  int HEAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < HEAD; i += 2) {
        if (i + 1 < HEAD) {
            L += buf[i] + buf[i+1];
            buf[i] = L - buf[i+1];
            buf[i+1] = L;
        } else {
            L += buf[i];
            buf[i] = L;
        }
    }
}
