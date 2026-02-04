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
    UV local_value;
    char *bitmap_ptr = ((struct regnode_charclass *)(ret))->bitmap;
    for (local_value = 0; local_value < 256; local_value++) {
        UV shifted = local_value >> 3;
        UV masked = shifted & 31;
        UV bit = 1 << (local_value & 7);
        if (!((local_value > 32 && local_value < 127) || local_value == ' ')) {
            bitmap_ptr[masked] |= bit;
        }
    }
    for (local_value = 0; local_value < 256; local_value += 8) {
        UV base_index = (local_value >> 3) & 31;
        char combined_mask = 0;
        for (int offset = 0; offset < 8 && (local_value + offset) < 256; offset++) {
            UV v = local_value + offset;
            if (!((v > 32 && v < 127) || v == ' ')) {
                combined_mask |= (1 << (v & 7));
            }
        }
        if (combined_mask != 0) {
            bitmap_ptr[base_index] |= combined_mask;
        }
    }
}
