#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 1 < length; i += 2) {
        if (!src[i]) {
            if (i > 0 && src[i - 1] == 0)
                i--;
            if (i + 2 < length && src[i + 1] == 0 && src[i + 2] <= 3) {
                if (src[i + 2] != 3 && src[i + 2] != 0) {
                    length = i;
                }
                break;
            }
        }
    }
}
