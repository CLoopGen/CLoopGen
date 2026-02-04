#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};


extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Process the bitmap array with a stride of 4 over byte index, simulating non-unit stride access
    // Values are still checked in order, but updates are grouped by stride-accessed bytes
    struct regnode_charclass *rnc = (struct regnode_charclass *)ret;
    unsigned char *bm = rnc->bitmap;
    
    // First, zero out or prepare to update in strided manner (though condition remains)
    // We'll iterate over strided indices and collect applicable values per byte
    for (int stride_offset = 0; stride_offset < 4; stride_offset++) {
        for (value = stride_offset * 8; value < 256; value += 32) {  // Stride of 32 in value maps to same bitmap index offset
            UV temp_val = value;
            for (int bit = 0; bit < 8; bit += 4) {  // Inner unroll to maintain coverage
                UV v = temp_val + bit;
                if (v >= 256) continue;
                if (!((((v) >= 'A' && (v) <= 'Z') || ((v) >= 'a' && (v) <= 'z')) || ((v) >= '0' && (v) <= '9'))) {
                    bm[(v >> 3) & 31] |= (1 << (v & 7));
                }
            }
        }
    }
}
