#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char JSAMPLE;

JSAMPLE *table;
int i;

void init_vars() {
    table = (JSAMPLE*)malloc(512 * sizeof(JSAMPLE));
    if (!table) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(table, 0, 512 * sizeof(JSAMPLE));
}
// End of file