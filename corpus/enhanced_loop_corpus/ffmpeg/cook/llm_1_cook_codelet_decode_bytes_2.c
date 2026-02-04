#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *obuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (bytes <= 0) return;
    int n = bytes / 4;
    int mid = n / 2;
    for (i = 0; i < mid; i++) {
        obuf[i] = c ^ buf[i];
    }
    for (i = mid; i < n; i++) {
        obuf[i] = c ^ buf[i];
    }
}
