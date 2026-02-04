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
    int temp_e = s + 1;
    for (e = s + 1; e < keylen; e++) {
        temp_e = e;
        if (key[temp_e] == '}') {
            e = temp_e;
            break;
        }
    }
    if (temp_e >= keylen) e = keylen - 1;
}
