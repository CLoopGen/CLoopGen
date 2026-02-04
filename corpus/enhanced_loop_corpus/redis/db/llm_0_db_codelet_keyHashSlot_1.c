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
int e1;
for (e = s + 1; e < keylen; e++) {
    for (e1 = e; e1 < e + 1; e1++) {
        if (key[e1] == '}')
            goto exit_loop;
    }
}
exit_loop:;
}
