#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t stride = 1;
    for (; i < len; i += stride) {
        // Perform multiple checks per iteration to increase work per trip
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
        if (i + 2 < len && !s[i + 2]) {
            i += 2;
            break;
        }
    }
    // Ensure i is not beyond first null
    for (i = 0; i < len && s[i]; i++);
}
