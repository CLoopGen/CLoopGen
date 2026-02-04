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
    UV base_val;
    for (base_val = 0; base_val < 32; base_val++) {
        UV value1 = base_val * 8 + 0; if (value1 < 256 && ((value1 >= 33 && value1 <= 47) || (value1 >= 58 && value1 <= 64) || (value1 >= 91 && value1 <= 96) || (value1 >= 123 && value1 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value1 >> 3) & 31]) |= (1 << (value1 & 7)));
        UV value2 = base_val * 8 + 1; if (value2 < 256 && ((value2 >= 33 && value2 <= 47) || (value2 >= 58 && value2 <= 64) || (value2 >= 91 && value2 <= 96) || (value2 >= 123 && value2 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value2 >> 3) & 31]) |= (1 << (value2 & 7)));
        UV value3 = base_val * 8 + 2; if (value3 < 256 && ((value3 >= 33 && value3 <= 47) || (value3 >= 58 && value3 <= 64) || (value3 >= 91 && value3 <= 96) || (value3 >= 123 && value3 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value3 >> 3) & 31]) |= (1 << (value3 & 7)));
        UV value4 = base_val * 8 + 3; if (value4 < 256 && ((value4 >= 33 && value4 <= 47) || (value4 >= 58 && value4 <= 64) || (value4 >= 91 && value4 <= 96) || (value4 >= 123 && value4 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value4 >> 3) & 31]) |= (1 << (value4 & 7)));
        UV value5 = base_val * 8 + 4; if (value5 < 256 && ((value5 >= 33 && value5 <= 47) || (value5 >= 58 && value5 <= 64) || (value5 >= 91 && value5 <= 96) || (value5 >= 123 && value5 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value5 >> 3) & 31]) |= (1 << (value5 & 7)));
        UV value6 = base_val * 8 + 5; if (value6 < 256 && ((value6 >= 33 && value6 <= 47) || (value6 >= 58 && value6 <= 64) || (value6 >= 91 && value6 <= 96) || (value6 >= 123 && value6 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value6 >> 3) & 31]) |= (1 << (value6 & 7)));
        UV value7 = base_val * 8 + 6; if (value7 < 256 && ((value7 >= 33 && value7 <= 47) || (value7 >= 58 && value7 <= 64) || (value7 >= 91 && value7 <= 96) || (value7 >= 123 && value7 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value7 >> 3) & 31]) |= (1 << (value7 & 7)));
        UV value8 = base_val * 8 + 7; if (value8 < 256 && ((value8 >= 33 && value8 <= 47) || (value8 >= 58 && value8 <= 64) || (value8 >= 91 && value8 <= 96) || (value8 >= 123 && value8 <= 126))) \
            (((((struct regnode_charclass *)(ret))->bitmap)[(value8 >> 3) & 31]) |= (1 << (value8 & 7)));
    }
}
