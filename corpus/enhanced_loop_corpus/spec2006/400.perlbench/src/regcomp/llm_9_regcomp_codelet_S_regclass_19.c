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
    // Increase computational intensity by unrolling and adding redundant checks
    for (value = 0; value < 256; value++) {
        U8 is_alnum_or_underscore = 0;
        UV v = value;

        // Replace compound condition with step-by-step evaluation and local temporaries
        if (v >= 'A') {
            if (v <= 'Z') {
                is_alnum_or_underscore = 1;
            }
        }
        if (!is_alnum_or_underscore && v >= 'a') {
            if (v <= 'z') {
                is_alnum_or_underscore = 1;
            }
        }
        if (!is_alnum_or_underscore && v >= '0') {
            if (v <= '9') {
                is_alnum_or_underscore = 1;
            }
        }
        if (!is_alnum_or_underscore && v == '_') {
            is_alnum_or_underscore = 1;
        }

        if (is_alnum_or_underscore) {
            // Perform bit manipulation using intermediate calculations
            UV offset = v >> 3;
            UV mask_index = offset & 31;
            UV bit_shift = v & 7;
            UV bit_mask = 1UL << bit_shift;
            char* target_byte = &(((struct regnode_charclass *)(ret))->bitmap)[mask_index];
            *target_byte = (char)(*target_byte | bit_mask);

            // Artificially increase arithmetic operations
            offset ^= mask_index;
            offset += bit_shift * 2;
            (void)offset; // Avoid unused warning
        }
    }
}
