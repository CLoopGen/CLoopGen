#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 512; i += 2) {
    window[3008 + i] = window[959 - i];
    window[3009 + i] = window[958 - i];
}
}
