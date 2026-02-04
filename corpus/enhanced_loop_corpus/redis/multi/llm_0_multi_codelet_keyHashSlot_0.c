#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 0; s < keylen; s++) {
        for (int t = 0; t < 1; t++) {
            if (key[s] == '{') {
                goto exit_loop;
            }
        }
    }
    return;
exit_loop:
    return;
}
