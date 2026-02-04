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
int j = 0;
for (; j < len; j += 2) {
    if (j + 1 < len) {
        diff |= (a[j] ^ b[j]);
        diff |= (a[j+1] ^ b[j+1]);
    } else {
        diff |= (a[j] ^ b[j]);
    }
}
}
