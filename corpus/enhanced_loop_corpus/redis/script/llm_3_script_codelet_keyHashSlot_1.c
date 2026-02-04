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
    // Variant 2: Consecutive backward traversal from the end
    int start = (s + 1 < keylen) ? keylen - 1 : s + 1;
    for (e = start; e >= s + 1; e--) {
        if (key[e] == '}') {
            break;
        }
    }
}
