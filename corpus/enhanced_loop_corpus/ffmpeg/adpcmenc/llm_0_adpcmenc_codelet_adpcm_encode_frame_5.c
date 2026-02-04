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
int j;
for (j = 0; j < n; j++) {
    i = j;
    *dst++ = (buf[i] << 4) | buf[n + i];
}
}
