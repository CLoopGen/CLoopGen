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
    UV i;
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    U8 local_bitmap[32] = {0}; // Eliminate loop-carried store dependency by using local copy

    // Unroll the loop in chunks to change data dependency pattern and enable ILP
    for (i = 0; i < 256; i += 4) {
        UV v0 = i + 0, v1 = i + 1, v2 = i + 2, v3 = i + 3;
        UV idx0 = (v0 >> 3) & 31, idx1 = (v1 >> 3) & 31, idx2 = (v2 >> 3) & 31, idx3 = (v3 >> 3) & 31;
        U8 m0 = (1 << (v0 & 7)), m1 = (1 << (v1 & 7)), m2 = (1 << (v2 & 7)), m3 = (1 << (v3 & 7));

        // Process four values independently — eliminate loop-carried dependency
        if ((v0 >= 'A' && v0 <= 'Z') || (v0 >= 'a' && v0 <= 'z') || (v0 >= '0' && v0 <= '9'))
            local_bitmap[idx0] |= m0;
        if ((v1 >= 'A' && v1 <= 'Z') || (v1 >= 'a' && v1 <= 'z') || (v1 >= '0' && v1 <= '9'))
            local_bitmap[idx1] |= m1;
        if ((v2 >= 'A' && v2 <= 'Z') || (v2 >= 'a' && v2 <= 'z') || (v2 >= '0' && v2 <= '9'))
            local_bitmap[idx2] |= m2;
        if ((v3 >= 'A' && v3 <= 'Z') || (v3 >= 'a' && v3 <= 'z') || (v3 >= '0' && v3 <= '9'))
            local_bitmap[idx3] |= m3;
    }

    // Final non-loop-carried write: copy accumulated result
    for (i = 0; i < 32; i++)
        rcc->bitmap[i] = local_bitmap[i];
}
