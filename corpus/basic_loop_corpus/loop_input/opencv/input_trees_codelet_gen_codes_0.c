#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned short ush;
typedef ush ushf;

ushf *bl_count;
ush next_code[16];
unsigned int code;
int bits;

void init_vars() {
    bl_count = (ushf*)calloc(16, sizeof(ushf));
    if (!bl_count) exit(1);

    for (int i = 0; i < 15; i++) {
        bl_count[i] = 1000 + i;
    }

    code = 0;
}