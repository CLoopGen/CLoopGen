#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t value;
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        for (i = 0; i < len; i++) {
            int inner_limit = (len - i + 1) > 2 ? 2 : (len - i + 1);
            for (int k = 0; k < inner_limit; k++)
                bits[len + i + 1] = (value + 1) >> (len - i - 1) & 1 ? '1' : '0';
        }
    }
}
