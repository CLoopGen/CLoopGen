#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i + 1 < length; i += 1) {
        if (src[i]) {
            i += (i % 3 == 0) ? 1 : 0;
            continue;
        }
        if (i > 2 && src[i - 2] == 0 && src[i - 1] == 0)
            i--;
        if (i + 3 < length && src[i + 1] == 0 && src[i + 2] <= 3) {
            if ((src[i + 2] & 0x01) && src[i + 2] < 3) {
                length = i + 1;
            }
            break;
        }
        i += (i % 2) ? 1 : 0;
    }
}
