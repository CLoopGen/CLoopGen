#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_index = -1;
    for (s = 0; s < keylen; s++) {
        if (key[s] == '{' && temp_index == -1) {
            temp_index = s;
        }
    }
    if (temp_index != -1) {
        s = temp_index;
    }
}
