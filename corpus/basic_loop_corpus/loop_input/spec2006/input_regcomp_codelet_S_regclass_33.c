#include <stdio.h>
#include <inttypes.h>

typedef unsigned long UV;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};

UV value;
struct regnode_charclass reg_data;
struct regnode *ret = (struct regnode *)&reg_data;

void init_vars() {
    value = 0;
    ret->flags = 0;
    ret->type = 0;
    ret->next_off = 0;
    ((struct regnode_charclass *)ret)->arg1 = 0;
    for (int i = 0; i < 32; i++) {
        ((struct regnode_charclass *)ret)->bitmap[i] = 0;
    }
}