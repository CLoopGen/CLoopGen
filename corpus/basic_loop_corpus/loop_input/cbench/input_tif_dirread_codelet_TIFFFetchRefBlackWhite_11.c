#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

TIFFDirEntry *dir;
char *cp;
float *fp;
uint32 i;

void init_vars() {
    const uint32 data_size = 64 * 1024 * 1024; // ~64M elements for float and uint32 arrays
    const uint32 count = data_size / sizeof(uint32);

    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    cp = (char *)malloc(data_size);
    fp = (float *)malloc(data_size);

    dir->tdir_count = count;

    uint32 *cp_uint32 = (uint32 *)(cp);
    for (uint32 j = 0; j < count; j++) {
        cp_uint32[j] = j + 1;
    }

    for (uint32 j = 0; j < count; j++) {
        fp[j] = 0.0f;
    }
}