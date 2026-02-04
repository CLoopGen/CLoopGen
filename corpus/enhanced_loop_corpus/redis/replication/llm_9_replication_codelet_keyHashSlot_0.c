#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int limit = keylen + (keylen % 2);
    for (s = 0; s < limit; s += step) {
        int idx = (s >= keylen) ? keylen - 1 : s;
        if (key[idx] == '{') {
            s = idx;
            break;
        }
    }
}
