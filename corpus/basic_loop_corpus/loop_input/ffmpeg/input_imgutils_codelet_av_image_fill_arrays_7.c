#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int dst_linesize[4];
int align;
int i;

void init_vars() {
    align = 16;
    dst_linesize[0] = 1000;
    dst_linesize[1] = 2000;
    dst_linesize[2] = 3000;
    dst_linesize[3] = 4000;
}