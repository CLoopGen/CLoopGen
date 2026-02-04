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



void loop() {
    UV local_value;
    struct regnode_charclass *local_node = (struct regnode_charclass *)ret;
    U8 temp_bitmap[32] = {0};  // Local accumulation to introduce WAR dependency

    // Pre-initialize temp_bitmap with original values to allow safe modification
    for (int i = 0; i < 32; i++) {
        temp_bitmap[i] = local_node->bitmap[i];
    }

    for (local_value = 0; local_value < 256; local_value++) {
        if ((local_value >= 'a' && local_value <= 'z')) {
            UV idx = (local_value >> 3) & 31;
            UV bit = local_value & 7;
            temp_bitmap[idx] |= (1 << bit);  // Eliminate direct memory write, create local WAR
        }
    }

    // Write back to original memory (introduce WAW on bitmap)
    for (int i = 0; i < 32; i++) {
        local_node->bitmap[i] = temp_bitmap[i];
    }
}
