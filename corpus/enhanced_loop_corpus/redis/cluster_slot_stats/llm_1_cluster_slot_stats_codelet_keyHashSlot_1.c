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
    int outer_e;
    for (outer_e = s + 1; outer_e < keylen; outer_e++) {
        for (e = outer_e; e < outer_e + 1; e++) {
            if (key[e] == '}')
                goto exit_loop;
        }
    }
exit_loop:;
}
