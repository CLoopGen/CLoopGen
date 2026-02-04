#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

TIFFDirEntry *dir;
double *v;
int i;
uint16 *vp;

void init_vars() {
    const uint32 data_size = 64 * 1024 * 1024; // ~128MB of input (adjustable for timing)
    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    v = (double *)aligned_alloc(32, data_size * sizeof(double));
    vp = (uint16 *)aligned_alloc(32, data_size * sizeof(uint16));

    dir->tdir_count = data_size;
    dir->tdir_tag = 0;
    dir->tdir_type = 0;
    dir->tdir_offset = 0;

    for (uint32 idx = 0; idx < data_size; idx++) {
        vp[idx] = (uint16)(idx & 0xFFFF);
    }

    for (uint32 idx = 0; idx < data_size; idx++) {
        v[idx] = 0.0;
    }
}