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
extern uint16 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with pointer arithmetic
    uint32 count = dir->tdir_count;
    double *v_ptr = v + count - 1;
    uint16 *vp_ptr = vp + count - 1;
    for (i = count; i > 0; --i, --v_ptr, --vp_ptr) {
        *v_ptr = *vp_ptr;
    }
}
