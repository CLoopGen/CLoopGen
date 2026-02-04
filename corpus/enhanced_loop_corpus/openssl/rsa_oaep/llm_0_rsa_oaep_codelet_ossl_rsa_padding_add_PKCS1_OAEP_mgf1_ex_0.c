#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char *db;
extern unsigned char *dbmask;
extern int dbmask_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < dbmask_len; j++) {
    for (i = 0; i <= j; i++)
        db[i] ^= dbmask[i];
}
}
