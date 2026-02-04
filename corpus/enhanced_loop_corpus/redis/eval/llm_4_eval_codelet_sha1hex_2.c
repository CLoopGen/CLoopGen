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
    for (j = 0; j < 20; j++) {
        if ((hash[j] & 240) >> 4) {
            digest[j * 2] = cset[((hash[j] & 240) >> 4)];
        } else {
            digest[j * 2] = cset[0];
        }
        if (hash[j] & 15) {
            digest[j * 2 + 1] = cset[(hash[j] & 15)];
        } else {
            digest[j * 2 + 1] = cset[0];
        }
    }
}
