#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    s = 0;
    for (int block = 0; block < keylen && s < keylen; block += 16) {
        for (int offset = 0; offset < 16 && s < keylen; offset++) {
            s = block + offset;
            if (key[s] == '{')
                return;
        }
    }
}
