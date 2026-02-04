#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse-order memory access — traverse arrays from end to beginning
    for (i = dblen - 1; i >= 0; i--) {
        db[i] ^= maskeddb[i];
    }
}
