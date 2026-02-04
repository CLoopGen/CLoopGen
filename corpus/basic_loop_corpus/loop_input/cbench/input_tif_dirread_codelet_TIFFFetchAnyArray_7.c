#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
uint32 *vp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to fit within ~0.01 sec on modern CPU
    dir = (TIFFDirEntry *)malloc(sizeof(TIFFDirEntry));
    v = (double *)aligned_alloc(32, data_size * sizeof(double));
    vp = (uint32 *)aligned_alloc(32, data_size * sizeof(uint32));

    dir->tdir_count = data_size;
    dir->tdir_tag = 0;
    dir->tdir_type = 0;
    dir->tdir_offset = 0;

    for (size_t idx = 0; idx < data_size; idx++) {
        vp[idx] = (uint32)(idx & 0xFFFFFFFF);
        v[idx] = 0.0;
    }
}