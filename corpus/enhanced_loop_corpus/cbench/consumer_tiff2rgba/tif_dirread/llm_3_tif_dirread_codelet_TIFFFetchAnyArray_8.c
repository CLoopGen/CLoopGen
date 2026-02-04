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

typedef int int32;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern int32 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with pointer arithmetic
    int32 count = dir->tdir_count;
    double *v_ptr = v + count;
    int32 *vp_ptr = vp + count;
    for (i = 0; i < count; i++) {
        *(--v_ptr) = *(--vp_ptr);
    }
}
