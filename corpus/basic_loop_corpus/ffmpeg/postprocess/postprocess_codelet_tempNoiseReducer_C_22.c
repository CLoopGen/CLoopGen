#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int ref = tempBlurred[x + y * stride];
        int cur = src[x + y * stride];
        tempBlurred[x + y * stride] = src[x + y * stride] = (ref * 7 + cur + 4) >> 3;
    }
}

}
