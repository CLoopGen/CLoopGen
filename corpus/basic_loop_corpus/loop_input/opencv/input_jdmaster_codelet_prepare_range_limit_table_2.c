#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;

JSAMPLE *table;
int i;

void init_vars() {
    table = (JSAMPLE*)malloc(256 * sizeof(JSAMPLE));
    if (!table) {
        exit(1);
    }
}

void loop(); 

__attribute__((constructor))
static void auto_init() {
    init_vars();
}