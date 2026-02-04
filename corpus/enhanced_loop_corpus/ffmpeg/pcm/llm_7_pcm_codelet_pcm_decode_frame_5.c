#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *s = samples;
    const uint8_t *g = src;
    int i;
    for (i = 0; i < n; i++) {
        s[i] = g[i] + 128;
    }
    samples += n;
    src += n;
    n = 0;
}
