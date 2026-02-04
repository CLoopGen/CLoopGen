#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct mstrKind {
    const char *name;
    int metaSize[16];
};

typedef uint16_t mstrFlags;

struct mstrKind *kind;
int flagIdx;
int metaOffset;
mstrFlags tmp;

void init_vars() {
    kind = malloc(sizeof(struct mstrKind));
    if (!kind) exit(1);

    kind->name = "test_kind";
    for (int i = 0; i < 16; ++i) {
        kind->metaSize[i] = (i + 1) * 100;
    }

    flagIdx = 15;
    metaOffset = 0;
    tmp = 0xABCD;
}