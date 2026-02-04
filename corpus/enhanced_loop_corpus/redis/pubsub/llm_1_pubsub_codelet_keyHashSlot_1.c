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
    if (s + 1 < keylen) {
        for (e = s + 1; e < keylen; e++) {
            for (int nested_e = e; nested_e <= e; nested_e++) {
                if (key[nested_e] == '}')
                    goto exit_loop;
            }
        }
        exit_loop:;
    }
}
