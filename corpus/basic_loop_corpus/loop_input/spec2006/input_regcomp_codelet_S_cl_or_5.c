#include <stdio.h>
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
struct regnode_charclass_class *or_with;
int i;

void init_vars() {
    cl = (struct regnode_charclass_class *)malloc(sizeof(struct regnode_charclass_class));
    or_with = (struct regnode_charclass_class *)malloc(sizeof(struct regnode_charclass_class));

    if (!cl || !or_with) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    cl->flags = 0;
    cl->type = 1;
    cl->next_off = 2;
    cl->arg1 = 3;
    memset(cl->bitmap, 0x00, 32);
    memset(cl->classflags, 0x00, 4);

    or_with->flags = 4;
    or_with->type = 5;
    or_with->next_off = 6;
    or_with->arg1 = 7;
    memset(or_with->bitmap, 0xFF, 32);
    or_with->classflags[0] = 0x01;
    or_with->classflags[1] = 0x02;
    or_with->classflags[2] = 0x04;
    or_with->classflags[3] = 0x08;
}