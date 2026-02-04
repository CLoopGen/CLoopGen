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

const unsigned char PL_fold[256] = {0};

UV value;
struct regnode_charclass regnode_storage;

struct regnode_charclass *ret = &regnode_storage;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        ((unsigned char *)PL_fold)[i] = (i + 1) % 256;
    }
    ret->flags = 0;
    ret->type = 0;
    ret->next_off = 0;
    ret->arg1 = 0;
    for (int i = 0; i < 32; ++i) {
        ret->bitmap[i] = (i < 16) ? 0xFF : 0x00;
    }
}