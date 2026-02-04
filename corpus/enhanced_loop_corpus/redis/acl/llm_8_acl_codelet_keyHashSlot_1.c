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
    for (e = s + 1; e < keylen && e < s + 32; e++) {
        if (key[e] == '}' && (e % 2) == 0)
            break;
    }
}
