#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (i = 0; i < dblen; i += 8) {
        for (int j = 0; j < 8 && (i + j) < dblen; j++) {
            temp[j] = maskeddb[i + j];
        }
        for (int j = 0; j < 8 && (i + j) < dblen; j++) {
            db[i + j] ^= temp[j];
        }
    }
}
