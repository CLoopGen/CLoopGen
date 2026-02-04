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
    cl = (struct regnode_charclass_class *)calloc(1, sizeof(struct regnode_charclass_class));
    or_with = (struct regnode_charclass_class *)calloc(1, sizeof(struct regnode_charclass_class));
    if (!cl || !or_with) {
        exit(1);
    }
    for (int j = 0; j < 32; j++) {
        or_with->bitmap[j] = (char)(j * 7 + 1);
    }
}