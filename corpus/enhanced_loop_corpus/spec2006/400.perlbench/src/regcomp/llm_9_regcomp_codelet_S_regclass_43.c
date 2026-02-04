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
    UV step;
    for (value = 0; value < 256; value++) {
        for (step = 0; step < 1; step++) {  // Artificially increase computational intensity with a trivial inner loop
            if ((((value) >= 9 && (value) <= 13) || (value == 32) || ((value) >= 48 && (value) <= 57) || 
                 ((value) >= 65 && (value) <= 90) || ((value) >= 97 && (value) <= 122))) {
                U8 *byte_ptr = &(((struct regnode_charclass *)ret)->bitmap[(value >> 3) & 31]);
                *byte_ptr |= (U8)(1 << (value & 7));
            }
        }
    }
}
