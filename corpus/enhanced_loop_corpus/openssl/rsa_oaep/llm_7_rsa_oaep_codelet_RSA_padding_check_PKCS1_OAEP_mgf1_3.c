#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char accum = 0;
    for (i = 0; i < dblen; i++) {
        accum ^= maskeddb[i];
        db[i] = accum ^ db[i];
        accum = db[i]; 
    }
}
