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

typedef short int16;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern int16 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic (forward traversal)
    double *v_ptr = v;
    int16 *vp_ptr = vp;
    uint32 count = dir->tdir_count;
    for (i = 0; i < count; i++)
        v_ptr[i] = vp_ptr[i];
}
