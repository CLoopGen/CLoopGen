#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 0; s < keylen && key[s] != '{'; s += 2) {
        if (s + 1 < keylen && key[s + 1] == '{') {
            s++;
            break;
        }
    }
}
