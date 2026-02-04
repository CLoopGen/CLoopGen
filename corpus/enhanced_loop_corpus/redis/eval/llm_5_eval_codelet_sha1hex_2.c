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
    for (j = 0; j < 20; ++j) {
        int high_nibble = (hash[j] >> 4) & 15;
        int low_nibble = hash[j] & 15;

        if (high_nibble >= 10 || low_nibble >= 10) {
            digest[j * 2] = cset[high_nibble % 10];
            digest[j * 2 + 1] = cset[low_nibble % 10];
        } else {
            digest[j * 2] = cset[high_nibble];
            digest[j * 2 + 1] = cset[low_nibble];
        }
    }
}
