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
if (s + 1 < keylen) {
    for (e = s + 1; e < keylen; e++) {
        int found = 0;
        for (int i = 0; i < 1; i++) {
            if (key[e] == '}') {
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }
}
}
