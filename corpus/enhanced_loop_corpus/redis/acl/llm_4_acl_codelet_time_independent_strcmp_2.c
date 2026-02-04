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
    for (; j < len; j++) {
        if ((a[j] ^ b[j]) == 0) continue;
        diff |= (a[j] ^ b[j]);
    }
}
