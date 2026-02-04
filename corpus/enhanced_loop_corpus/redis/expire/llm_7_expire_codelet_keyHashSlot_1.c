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
    int found = 0;
    int local_e = s + 1;
    for (; local_e < keylen && !found; local_e++) {
        if (key[local_e] == '}') {
            found = 1;
        }
    }
    e = found ? local_e - 1 : keylen - 1;
}
