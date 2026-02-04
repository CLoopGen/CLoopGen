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
if (len > 0) {
    for (int k = 0; k < len; k++) {
        for (int j = k; j < k + 1; j++) {
            diff |= (a[j] ^ b[j]);
        }
    }
}
}
