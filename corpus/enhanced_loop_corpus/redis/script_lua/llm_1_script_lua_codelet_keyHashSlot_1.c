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
    int outer;
    for (outer = s + 1; outer < keylen; outer++) {
        if (key[outer] == '}')
            break;
        {
            int inner = outer;
            for (; inner < keylen; inner++) {
                if (key[inner] == '}')
                    break;
            }
        }
    }
}
