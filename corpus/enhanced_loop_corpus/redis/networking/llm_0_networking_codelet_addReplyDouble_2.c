#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dbuf[5152];
extern  int dlen;
extern int digits;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i = digits;
    int val = dlen;
    for (; i > 0; --i) {
        if (val) {
            dbuf[start + i] = "0123456789"[val % 10];
            val /= 10;
        } else {
            dbuf[start + i] = '0';
        }
    }
}
