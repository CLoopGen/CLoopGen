#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char hash[32];
extern char hex[64];
extern char *cset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 64; j += 2) {
    int i = j / 2;
    hex[j] = cset[(hash[i] & 240) >> 4];
    hex[j + 1] = cset[hash[i] & 15];
}
}
