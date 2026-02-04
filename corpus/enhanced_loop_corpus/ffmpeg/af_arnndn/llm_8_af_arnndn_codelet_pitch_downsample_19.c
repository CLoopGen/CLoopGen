#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 8; i++) {
    tmp = 0.899999976F * tmp;
    lpc[i % 4] = (lpc[i % 4] * tmp) + 0.1F;
    tmp = 0.95F * tmp + 0.01F;
}
}
