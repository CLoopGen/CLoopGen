#include <stdio.h>
#include <inttypes.h>

typedef unsigned short uint16;
typedef unsigned int uint32;
typedef short int16;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

TIFFDirEntry *dir;
double *v;
int i;
int16 *vp;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(double)) // ~64MB of doubles

double v_array[DATA_SIZE];
int16 vp_array[DATA_SIZE];
TIFFDirEntry dir_entry;

void init_vars() {
    dir = &dir_entry;
    v = v_array;
    vp = vp_array;
    dir->tdir_count = DATA_SIZE;
    
    for (int j = 0; j < DATA_SIZE; j++) {
        vp[j] = (int16)(j & 0x7FFF);
        v[j] = 0.0;
    }
}