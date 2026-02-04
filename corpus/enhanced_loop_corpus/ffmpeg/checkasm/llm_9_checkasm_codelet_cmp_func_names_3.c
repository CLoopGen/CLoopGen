#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 1024 && a[i] && b[i]; i++) {
        ascii_diff = (unsigned char)a[i] - (unsigned char)b[i];
        if (ascii_diff != 0) {
            a += i;
            b += i;
            return;
        }
    }
    // Fallback in case of long or equal strings within bound
    ascii_diff = (unsigned char)*a - (unsigned char)*b;
}
