#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (s = 0; s < keylen; s++) {
        for (step = 1; step <= 3 && (s + step) < keylen; step++) {
            if (key[s + step] == '{') {
                s += step;
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
