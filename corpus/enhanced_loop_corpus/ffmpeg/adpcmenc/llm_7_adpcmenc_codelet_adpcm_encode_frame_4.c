#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern uint8_t *dst;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n - 1; i += 2) {
        dst[i / 2] = (buf[i] << 4) | buf[i + 1];
    }
    if (n % 2 && i == n - 1) {
        dst[n / 2] = buf[i] << 4;
    }
}
