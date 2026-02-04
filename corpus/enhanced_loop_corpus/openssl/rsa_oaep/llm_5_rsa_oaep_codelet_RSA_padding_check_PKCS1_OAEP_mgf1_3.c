#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dblen; i++) {
        if ((i & 1) == 0) {
            db[i] ^= maskeddb[i];
        } else {
            db[i] ^= maskeddb[i] ^ 0xFF;
        }
    }
}
