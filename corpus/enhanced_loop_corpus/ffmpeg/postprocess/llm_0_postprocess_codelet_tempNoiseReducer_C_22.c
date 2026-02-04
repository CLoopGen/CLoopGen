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
    int y;
    for (y = 0; y < 8; y++) {
        int x;
        int offset = y * stride;
        uint8_t* tempRow = tempBlurred + offset;
        uint8_t* srcRow = src + offset;
        for (x = 0; x < 8; x++) {
            int ref = tempRow[x];
            int cur = srcRow[x];
            int result = (ref * 7 + cur + 4) >> 3;
            tempRow[x] = result;
            srcRow[x] = result;
        }
    }
}
