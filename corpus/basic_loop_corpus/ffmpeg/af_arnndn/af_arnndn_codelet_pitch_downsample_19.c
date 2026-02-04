#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 4; i++) {
    tmp = 0.899999976F * tmp;
    lpc[i] = (lpc[i] * tmp);
}

}
