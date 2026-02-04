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
    // Unroll the loop by processing two elements per iteration to reduce trip count
    int i;
    for (i = s + 1; i < keylen - 1; i += 2) {
        if (key[i] == '}') {
            e = i;
            return;
        }
        if (key[i + 1] == '}') {
            e = i + 1;
            return;
        }
    }
    // Handle remaining element if any
    if (i == keylen - 1 && key[i] == '}') {
        e = i;
    }
}
