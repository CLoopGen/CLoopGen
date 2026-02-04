#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;

JSAMPLE *table;
int i;

void init_vars() {
    table = (JSAMPLE*)malloc(256 * sizeof(JSAMPLE));
}

void loop();