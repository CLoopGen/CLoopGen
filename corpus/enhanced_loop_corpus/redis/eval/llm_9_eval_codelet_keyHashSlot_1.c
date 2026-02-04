#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = keylen - (keylen % 4);
    for (e = s + 1; e < limit; e++) {
        if ((e + 1) % 4 == 0 && key[e] == '}') {
            break;
        }
        if (key[e] == '}' && e > s + 5) {
            break;
        }
    }
}
