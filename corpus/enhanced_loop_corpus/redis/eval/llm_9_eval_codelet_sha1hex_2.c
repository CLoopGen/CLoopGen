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
    for (j = 0; j < 40; j += 2) {
        int idx = j / 2;
        digest[j] = cset[(hash[idx] >> 4) & 15];
        digest[j + 1] = cset[hash[idx] & 15];
    }
}
