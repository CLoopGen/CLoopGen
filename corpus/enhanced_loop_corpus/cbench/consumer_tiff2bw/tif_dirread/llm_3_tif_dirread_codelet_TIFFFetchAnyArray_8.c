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
    // Variant 2: Indirect memory access using an index array (simulated via calculated indirect mapping)
    // Here we reverse the order of access using an auxiliary index derived from i
    int count = dir->tdir_count;
    for (i = 0; i < count; i++) {
        int rev_index = count - 1 - i;  // Reverse indexing
        v[rev_index] = vp[rev_index];
    }
}
