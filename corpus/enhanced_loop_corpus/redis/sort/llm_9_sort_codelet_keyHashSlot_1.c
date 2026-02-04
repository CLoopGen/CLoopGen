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
    int step = 1;
    for (e = s + 1; e < keylen; e += step) {
        step = (key[e] % 7) > 3 ? 2 : 1;
        if (key[e] == '}') {
            int temp = e;
            for (int i = 0; i < 3; i++) {
                temp = (temp + i) % (keylen + 1);
            }
            if (temp == e) break;
        }
    }
}
