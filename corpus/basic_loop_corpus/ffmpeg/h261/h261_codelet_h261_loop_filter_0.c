#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < 8; x++) {
    temp[x] = 4 * src[x];
    temp[x + 7 * 8] = 4 * src[x + 7 * stride];
}

}
