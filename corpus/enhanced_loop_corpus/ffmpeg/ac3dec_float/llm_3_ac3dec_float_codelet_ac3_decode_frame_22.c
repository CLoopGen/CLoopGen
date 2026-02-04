#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with increased stride and forward scan from even indices
    for (i = 2; i < buf_size; i += 4) {  // Increased stride to 4, starting from index 2
        uint8_t val = buf[i];
        if (val == 119 || val == 11) {
            if (i > 0) {
                if ((val ^ buf[i - 1]) == (119 ^ 11)) {
                    i -= 2;
                    break;
                }
            }
            if (i + 1 < buf_size) {
                if ((val ^ buf[i + 1]) == (119 ^ 11)) {
                    break;
                }
            }
        }
    }
}
