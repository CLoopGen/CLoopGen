#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (int outer = s + 1; outer < keylen && !found; outer++) {
        e = outer;
        for (int inner = 0; inner < 1; inner++) {
            if (key[e] == '}') {
                found = 1;
                break;
            }
        }
    }
}
