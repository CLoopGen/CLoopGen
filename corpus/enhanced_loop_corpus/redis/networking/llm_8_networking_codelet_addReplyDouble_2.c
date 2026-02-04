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
    for (int i = digits, val = dlen; val > 0 && i > 0; --i) {
        int remainder = val % 10;
        dbuf[start + i] = "0123456789"[remainder];
        val /= 10;
    }
}
