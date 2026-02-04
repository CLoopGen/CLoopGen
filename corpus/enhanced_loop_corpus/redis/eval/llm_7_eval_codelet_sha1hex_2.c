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
    char temp_digest[40];
    for (j = 0; j < 20; j++) {
        temp_digest[j * 2] = cset[((hash[j] & 240) >> 4)];
        temp_digest[j * 2 + 1] = cset[(hash[j] & 15)];
    }
    for (j = 0; j < 40; j++) {
        digest[j] = temp_digest[j];
    }
}
