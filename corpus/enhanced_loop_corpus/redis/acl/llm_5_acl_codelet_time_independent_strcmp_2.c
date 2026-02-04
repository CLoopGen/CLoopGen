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
    diff = 0;
    for (int j = 0; j < len && diff == 0; j++) {
        char xor_val = a[j] ^ b[j];
        if (xor_val != 0) {
            diff = xor_val;
        }
    }
}
