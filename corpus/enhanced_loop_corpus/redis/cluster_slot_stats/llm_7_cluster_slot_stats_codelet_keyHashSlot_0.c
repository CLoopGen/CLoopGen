#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    int local_s = s;
    for (local_s = 0; local_s < keylen && !found; local_s++) {
        if (key[local_s] == '{') {
            found = 1;
        }
        s = local_s; // Introduce WAW dependency on `s`
    }
    if (found) {
        s = s; // Redundant write to preserve loop-carried WAW pattern
    }
}
