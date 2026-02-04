#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t double_len = len << 1;
    for (dst += len - 1; len > 0; src++, dst--, len--) {
        *dst = *src;
        if (len > 1) {
            *(dst - 1) = *(src + 1);
            src++; dst--; len--;
        }
    }
}
