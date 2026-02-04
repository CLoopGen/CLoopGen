#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short uint16;
typedef unsigned int uint32;
typedef int int32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

TIFFDirEntry *dir;
double *v;
int i;
int32 *vp;

void init_vars() {
    const size_t data_size = 1 << 24; // 16 million elements, ~128MB for doubles
    dir = (TIFFDirEntry *)calloc(1, sizeof(TIFFDirEntry));
    v = (double *)malloc(data_size * sizeof(double));
    vp = (int32 *)malloc(data_size * sizeof(int32));

    dir->tdir_count = data_size;
    dir->tdir_tag = 0;
    dir->tdir_type = 0;
    dir->tdir_offset = 0;

    for (size_t idx = 0; idx < data_size; idx++) {
        vp[idx] = (int32)(idx & 0xFFFF);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        v[idx] = 0.0;
    }
}