#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *digest;
extern unsigned char hash[20];
extern char *cset;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer, j;
for (outer = 0; outer < 10; outer++) {
    for (j = 0; j < 2; j++) {
        int idx = outer * 2 + j;
        if (idx < 20) {
            digest[idx * 2] = cset[((hash[idx] & 240) >> 4)];
            digest[idx * 2 + 1] = cset[(hash[idx] & 15)];
        }
    }
}
}
