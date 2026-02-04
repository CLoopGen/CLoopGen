#include <stdlib.h>
#include <stdint.h>

typedef unsigned char JSAMPLE;

JSAMPLE *table;
int i;

void init_vars() {
    table = (JSAMPLE*)malloc(256 * sizeof(JSAMPLE));
    if (!table) exit(1);
}

void loop();