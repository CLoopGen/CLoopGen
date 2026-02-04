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
    for (value = 0; value < 256; value++) {
        UV shifted = value >> 3;
        U8 mask = (U8)(1 << (value & 7));
        int is_alpha_or_digit = 0;

        // Split condition into multiple arithmetic steps to increase computational load
        int is_upper = (value - 'A') <= ('Z' - 'A');
        int is_lower = (value - 'a') <= ('z' - 'a');
        int is_digit = (value - '0') <= ('9' - '0');
        
        is_alpha_or_digit = is_upper | is_lower | is_digit;

        if (is_alpha_or_digit) {
            ((struct regnode_charclass *)ret)->bitmap[shifted & 31] |= mask;
        }
    }
}
