#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

TIFFDirEntry *dir;
uint16 dircount;
TIFFDirEntry *dp;
uint32 space;
uint16 n;

const int tiffDataWidth[] = {1, 1, 2, 4, 8, 1, 1, 2, 4, 8, 4, 8, 1, 1, 2, 4, 8};

#define DIRCOUNT 65536

void init_vars() {
    TIFFDirEntry *entries = (TIFFDirEntry*)malloc(DIRCOUNT * sizeof(TIFFDirEntry));
    if (!entries) exit(1);

    for (uint32 i = 0; i < DIRCOUNT; i++) {
        entries[i].tdir_tag = (uint16)(i & 0xFFFF);
        entries[i].tdir_type = (uint16)((i % 17) & 0xFFFF);
        entries[i].tdir_count = (i % 1000) + 1;
        entries[i].tdir_offset = i * 2;
    }

    dir = entries;
    dircount = (uint16)DIRCOUNT;
    dp = NULL;
    space = 0;
    n = 0;
}