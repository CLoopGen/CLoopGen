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
    for (int i = s + 1; i < keylen; i++) {
        for (e = i; e <= i; e++) {
            if (key[e] == '}')
                break;
        }
    }
}
