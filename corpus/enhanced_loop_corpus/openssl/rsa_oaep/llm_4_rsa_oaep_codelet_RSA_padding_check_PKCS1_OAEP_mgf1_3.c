#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (dblen <= 0) return;
    for (i = 0; i < dblen; i++) {
        db[i] ^= maskeddb[i];
    }
}
