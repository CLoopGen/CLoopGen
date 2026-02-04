#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern uint32_t uvalue;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    if (len > 0) {
        for (i = 0; i < len; i += 2) {
            bits[len + i + 1] = ((uvalue + 1) >> (len - i - 1)) & 1 ? '1' : '0';
            if (i + 1 < len) {
                bits[len + (i + 1) + 1] = ((uvalue + 1) >> (len - (i + 1) - 1)) & 1 ? '1' : '0';
            }
        }
    }
}
