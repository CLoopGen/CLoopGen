#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *a;
extern char *b;
extern int len;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (int j = len - 1; j >= 0; j--) {
        diff |= (a[j] ^ b[j]);
    }
}
