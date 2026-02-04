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
struct regnode_charclass ret_storage;

void init_vars() {
    value = 0;
    ret_storage.flags = 0;
    ret_storage.type = 0;
    ret_storage.next_off = 0;
    ret_storage.arg1 = 0;
    for (int i = 0; i < 32; i++) {
        ret_storage.bitmap[i] = 0;
    }
}

struct regnode *ret = (struct regnode *)&ret_storage;