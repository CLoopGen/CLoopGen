#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char *db;
extern unsigned char *dbmask;
extern int dbmask_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dbmask_len * 2; i++) {
        int idx = i % dbmask_len;
        db[idx] ^= dbmask[idx];
    }
}
