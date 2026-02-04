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
int i, j;
for (i = 0; i < 1; i++) {
    for (j = 0; j < 20; j++) {
        digest[j * 2] = cset[((hash[j] & 240) >> 4)];
        digest[j * 2 + 1] = cset[(hash[j] & 15)];
    }
}
}
