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

    for (value1 = 0, value2 = 255; value1 < 128; value1++, value2--) {
        UV val_forward = value1;
        UV val_backward = value2;

        if ((((val_forward) >= 33 && (val_forward) <= 47) || 
             ((val_forward) >= 58 && (val_forward) <= 64) || 
             ((val_forward) >= 91 && (val_forward) <= 96) || 
             ((val_forward) >= 123 && (val_forward) <= 126))) {
            (((ret_cast->bitmap)[(val_forward >> 3) & 31]) |= (1 << (val_forward & 7)));
        }

        if (value2 != value1 && (((val_backward) >= 33 && (val_backward) <= 47) || 
                                 ((val_backward) >= 58 && (val_backward) <= 64) || 
                                 ((val_backward) >= 91 && (val_backward) <= 96) || 
                                 ((val_backward) >= 123 && (val_backward) <= 126))) {
            (((ret_cast->bitmap)[(val_backward >> 3) & 31]) |= (1 << (val_backward & 7)));
        }
    }
}
