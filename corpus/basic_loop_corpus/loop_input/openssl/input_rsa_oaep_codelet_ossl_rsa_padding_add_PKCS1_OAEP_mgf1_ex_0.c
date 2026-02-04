#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
unsigned char *db;
unsigned char *dbmask;
int dbmask_len;

static unsigned char db_storage[1024 * 128];     // 128KB data
static unsigned char dbmask_storage[1024 * 128]; // 128KB mask

void init_vars() {
    db = db_storage;
    dbmask = dbmask_storage;
    dbmask_len = sizeof(dbmask_storage);

    for (int j = 0; j < dbmask_len; j++) {
        db[j] = (unsigned char)(j & 0xFF);
        dbmask[j] = (unsigned char)((j + 31) & 0xFF);
    }
}