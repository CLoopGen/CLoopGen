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
    UV value1, value2;
    struct regnode_charclass *ret_cast = (struct regnode_charclass *)ret;
    U8 *bm = ret_cast->bitmap;

    for (value1 = 0; value1 < 128; value1++) {
        value2 = 255 - value1;

        // Process value1 (forward)
        if (!(((value1) >= 33 && (value1) <= 47) || 
              ((value1) >= 58 && (value1) <= 64) || 
              ((value1) >= 91 && (value1) <= 96) || 
              ((value1) >= 123 && (value1) <= 126))) {
            bm[(value1 >> 3) & 31] |= (1 << (value1 & 7));
        }

        // Process value2 (backward) - introduces WAR dependency if same byte accessed
        if (value2 != value1) {
            if (!(((value2) >= 33 && (value2) <= 47) || 
                  ((value2) >= 58 && (value2) <= 64) || 
                  ((value2) >= 91 && (value2) <= 96) || 
                  ((value2) >= 123 && (value2) <= 126))) {
                U32 idx = (value2 >> 3) & 31;
                U32 shift = value2 & 7;
                bm[idx] |= (1 << shift);
            }
        }
    }
}
