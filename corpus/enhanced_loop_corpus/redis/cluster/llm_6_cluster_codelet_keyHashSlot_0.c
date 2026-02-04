#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_s = 0;
    for (s = 0; s < keylen; s++) {
        temp_s = s;
        if (key[temp_s] == '{') {
            s = temp_s;
            break;
        }
    }
    if (temp_s == keylen - 1) s = keylen;
}
