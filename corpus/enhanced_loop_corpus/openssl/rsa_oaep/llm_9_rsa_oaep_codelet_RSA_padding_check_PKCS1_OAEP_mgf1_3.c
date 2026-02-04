#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int dblen;
extern  unsigned char *maskeddb;
extern unsigned char *db;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    int limit = (dblen + stride - 1) / stride;
    for (int i = 0; i < limit; i++) {
        int base = i * stride;
        if (base < dblen) db[base] ^= maskeddb[base];
        if (base + 1 < dblen) db[base + 1] ^= maskeddb[base + 1];
        if (base + 2 < dblen) db[base + 2] ^= maskeddb[base + 2];
        if (base + 3 < dblen) db[base + 3] ^= maskeddb[base + 3];
    }
}
