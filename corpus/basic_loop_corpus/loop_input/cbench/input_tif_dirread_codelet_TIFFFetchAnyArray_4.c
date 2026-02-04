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

typedef short int16;

TIFFDirEntry *dir;
double *v;
int i;
int16 *vp;

void init_vars() {
    uint32 data_size = 1 << 20; // Approximately 1M elements for ~0.01 sec runtime

    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    dir->tdir_count = data_size;

    v = (double *)malloc(data_size * sizeof(double));
    vp = (int16 *)malloc(data_size * sizeof(int16));

    for (uint32 idx = 0; idx < data_size; idx++) {
        vp[idx] = (int16)(idx & 0xFFFF);
        v[idx] = 0.0;
    }
}