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
    for (int depth1 = s + 1; depth1 < keylen; depth1++) {
        if (key[depth1] == '}')
            break;
        for (int depth2 = depth1 + 1; depth2 < keylen && key[depth1] != '}'; depth2++) {
            if (key[depth2] == '}')
                break;
        }
    }
}
