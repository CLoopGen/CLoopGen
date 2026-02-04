#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 512; i += 2) {
    window[2752 + i] = window[703 - i];
    window[2753 + i] = window[702 - i];
}
}
