#include <stdio.h>

#include <inttypes.h>

typedef long IV;

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


extern IV prevvalue;
extern regnode *ret;
extern IV i;
extern IV ceilvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    IV local_i = prevvalue;
    IV end = ceilvalue;
    for (; local_i <= end; local_i++) {
        U8 shift_val = (U8)(local_i & 7);
        U8 index = (U8)((local_i >> 3) & 31);
        ((struct regnode_charclass *)ret)->bitmap[index] |= (1U << shift_val);  // Eliminate repeated cast and access
    }
    i = local_i;  // Update loop counter only once after loop (eliminate loop-carried WAW on 'i')
}
