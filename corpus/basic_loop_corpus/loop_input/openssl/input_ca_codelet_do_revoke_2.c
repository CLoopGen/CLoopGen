#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *row[6];
int i;

void init_vars() {
    for (int j = 0; j < 6; j++) {
        row[j] = malloc(204800); // Allocate ~200KB per pointer, total ~1.2MB
        if (row[j] != NULL) {
            memset(row[j], 0, 204800);
        }
    }
}