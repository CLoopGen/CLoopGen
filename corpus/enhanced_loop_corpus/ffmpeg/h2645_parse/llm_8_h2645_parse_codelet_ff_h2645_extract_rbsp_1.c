#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 3 < length; i += 4) {
        if (src[i] || src[i + 1]) {
            if (!src[i]) i--;
            continue;
        }
        if (i > 1 && src[i - 2] == 0)
            i -= 2;
        if (i + 4 < length && src[i + 2] == 0 && src[i + 3] <= 3) {
            if (src[i + 3] != 3 && src[i + 3] != 0) {
                length = i;
            }
            break;
        }
        if (i + 5 < length && src[i + 4] == 0) {
            i++;
        }
    }
}
