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
double *v;
int i;
float *vp;

void init_vars() {
    const uint32 data_size = 1 << 20; // 1M elements, ~8MB for double, ~4MB for float

    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    v = (double *)aligned_alloc(32, data_size * sizeof(double));
    vp = (float *)aligned_alloc(32, data_size * sizeof(float));

    dir->tdir_count = data_size;
    dir->tdir_tag = 0;
    dir->tdir_type = 0;
    dir->tdir_offset = 0;

    for (uint32 idx = 0; idx < data_size; idx++) {
        vp[idx] = (float)(idx * 1.5f);
        v[idx] = 0.0;
    }

    i = 0;
}

__attribute__((destructor)) void cleanup() {
    if (v) free(v);
    if (vp) free(vp);
    if (dir) free(dir);
}