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
    UV temp_value;
    for (temp_value = 0; temp_value < 256; temp_value++) {
        UV index = temp_value;
        if (!((index) >= 'a' && (index) <= 'z')) {
            U8 bit_pos = (U8)(index & 7);
            U8 byte_pos = (U8)((index >> 3) & 31);
            ((struct regnode_charclass *)ret)->bitmap[byte_pos] |= (1 << bit_pos);
        }
    }
    value = temp_value;
}
