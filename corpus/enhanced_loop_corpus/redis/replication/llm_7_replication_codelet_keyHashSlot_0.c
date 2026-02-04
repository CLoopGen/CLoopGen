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
    for (int i = 0; i < keylen && !found; i++) {
        local_s = i;
        if (key[i] == '{') {
            found = 1;
        }
    }
    s = local_s;
}
