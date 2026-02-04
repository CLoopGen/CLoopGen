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
    uint32 data_size = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime

    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    v = (double *)malloc(data_size * sizeof(double));
    vp = (float *)malloc(data_size * sizeof(float));

    dir->tdir_count = data_size;
    dir->tdir_tag = 0;
    dir->tdir_type = 0;
    dir->tdir_offset = 0;

    for (uint32 idx = 0; idx < data_size; idx++) {
        vp[idx] = (float)(idx & 0xFF);
    }

    for (uint32 idx = 0; idx < data_size; idx++) {
        v[idx] = 0.0;
    }

    i = 0;
}