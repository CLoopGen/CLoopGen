#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

struct regnode_charclass_class {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
    char classflags[4];
};

struct regnode_charclass_class *cl;
struct regnode_charclass_class *and_with;
int i;

void init_vars() {
    cl = (struct regnode_charclass_class *)malloc(sizeof(struct regnode_charclass_class));
    and_with = (struct regnode_charclass_class *)malloc(sizeof(struct regnode_charclass_class));

    if (!cl || !and_with) {
        exit(1);
    }

    memset(cl->bitmap, 0xFF, 32);
    memset(and_with->bitmap, 0x55, 32);
    memset(cl->classflags, 0x01, 4);
    memset(and_with->classflags, 0x02, 4);

    cl->flags = 1;
    cl->type = 2;
    cl->next_off = 3;
    cl->arg1 = 4;

    and_with->flags = 5;
    and_with->type = 6;
    and_with->next_off = 7;
    and_with->arg1 = 8;
}