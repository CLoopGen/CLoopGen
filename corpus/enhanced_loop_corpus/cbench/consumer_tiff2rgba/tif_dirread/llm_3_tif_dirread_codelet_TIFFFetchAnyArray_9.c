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



void loop(){
    // Variant 2: Reverse consecutive access using pointer arithmetic (forward indexing from base offset)
    double *v_ptr = v + dir->tdir_count - 1;
    float  *vp_ptr = vp + dir->tdir_count - 1;
    int n = dir->tdir_count;
    for (i = n - 1; i >= 0; i--) {
        *v_ptr-- = *vp_ptr--;
    }
}
