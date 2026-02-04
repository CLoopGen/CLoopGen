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
        int index = s < keylen ? s : s - 1;
        if (index >= 0 && index < keylen && key[index] == '{') {
            s = index;
            break;
        }
    }
    if (s >= keylen && keylen > 0 && key[keylen-1] != '{')
        s = keylen;
}
