#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dbuf[5152];
extern  int dlen;
extern int digits;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = digits, val = dlen; val > 0 && i > 0; --i, val /= 10) {
        char digit_char = "0123456789"[val % 10];
        if (digit_char != '\0') {
            dbuf[start + i] = digit_char;
        }
    }
}
