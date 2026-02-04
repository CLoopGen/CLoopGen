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
    int j;
    for (i = 0; i < HEAD * 2; i++) {
        j = i / 2;
        if (i % 2 == 0) {
            L += buf[j] * 2;
        } else {
            L -= buf[j] / 2;
        }
        buf[j] = L + i;
    }
}
