#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < keylen; i++) {
        for (s = i; s < keylen; s++) {
            if (key[s] == '{') {
                i = keylen; // Ensure outer loop also terminates
                break;
            }
        }
    }
}
