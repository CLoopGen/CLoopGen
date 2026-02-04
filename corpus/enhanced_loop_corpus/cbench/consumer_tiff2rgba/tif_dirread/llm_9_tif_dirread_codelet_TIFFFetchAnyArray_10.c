#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern float *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32 count = dir->tdir_count;
    double sum = 0.0;
    for (i = count - 1; i >= 0; i--) {
        sum += vp[i];
        v[i] = sum / (count - i);
    }
}
