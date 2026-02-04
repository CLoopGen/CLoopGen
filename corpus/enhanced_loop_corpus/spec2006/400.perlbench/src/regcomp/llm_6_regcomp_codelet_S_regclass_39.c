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
    UV index;
    U8 temp_flags = ((struct regnode_charclass *)(ret))->flags;
    U8 temp_type = ((struct regnode_charclass *)(ret))->type;
    U16 temp_next = ((struct regnode_charclass *)(ret))->next_off;
    U32 temp_arg1 = ((struct regnode_charclass *)(ret))->arg1;
    char temp_bitmap[32];
    for (int i = 0; i < 32; i++) {
        temp_bitmap[i] = ((struct regnode_charclass *)(ret))->bitmap[i];
    }
    for (value = 0; value < 256; value++) {
        index = (value >> 3) & 31;
        if (!(((value) > 32 && (value) < 127) || (value) == ' ')) {
            temp_bitmap[index] |= (1 << (value & 7));
        }
    }
    for (int i = 0; i < 32; i++) {
        ((struct regnode_charclass *)(ret))->bitmap[i] = temp_bitmap[i];
    }
    ((struct regnode_charclass *)(ret))->flags = temp_flags;
    ((struct regnode_charclass *)(ret))->type = temp_type;
    ((struct regnode_charclass *)(ret))->next_off = temp_next;
    ((struct regnode_charclass *)(ret))->arg1 = temp_arg1;
}
