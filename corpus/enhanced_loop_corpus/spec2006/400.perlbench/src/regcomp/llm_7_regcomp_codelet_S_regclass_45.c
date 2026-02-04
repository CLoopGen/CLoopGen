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
    UV temp_val;
    U8 *bm = ((struct regnode_charclass *)(ret))->bitmap;
    // Eliminate repeated global access by caching control, introducing RAW dependency within unrolled segments
    for (value = 0; value < 256; value += 4) {
        for (int offset = 0; offset < 4; ++offset) {
            temp_val = value + offset;
            if (!((temp_val) == ' ' || (temp_val) == '\t' || (temp_val) == '\n' || (temp_val) == '\r' || (temp_val) == '\f')) {
                bm[(temp_val >> 3) & 31] |= (1 << (temp_val & 7)); // RAW: bm load/use before store in next iteration
            }
        }
    }
}
