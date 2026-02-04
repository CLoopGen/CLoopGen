#include <stdio.h>
#include <inttypes.h>

typedef unsigned long Hashseq;

Hashseq hashprobe = 0;
int i = 0;

void init_vars() {
    hashprobe = 1;
    i = 0;
}