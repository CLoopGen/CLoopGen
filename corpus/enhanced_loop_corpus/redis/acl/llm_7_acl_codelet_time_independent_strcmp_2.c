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
        diff |= (a[0] ^ b[0]);
        for (int j = 1; j < len; j++) {
            int current_xor = (a[j] ^ b[j]);
            diff |= current_xor ^ (a[j-1] ^ b[j-1]); 
        }
    }
}
