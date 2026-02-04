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
    int temp_diff = 0;
    for (int j = 0; j < len; j++) {
        temp_diff |= (a[j] ^ b[j]);
    }
    diff = temp_diff;
}
