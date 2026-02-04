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
extern uint32 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping (bit-reversed indexing)
    // Simulates a more complex access pattern useful in FFT-like computations
    uint32 count = dir->tdir_count;
    for (i = count - 1; i >= 0; i--) {
        uint32 bit_reversed_i = 0;
        uint32 temp = i;
        int num_bits = 0;
        uint32 c = count - 1;
        while (c >>= 1) num_bits++;
        c = i;
        for (int b = 0; b <= num_bits; b++) {
            bit_reversed_i = (bit_reversed_i << 1) | (c & 1);
            c >>= 1;
        }
        if (bit_reversed_i < count)
            v[bit_reversed_i] = vp[bit_reversed_i];
    }
}
