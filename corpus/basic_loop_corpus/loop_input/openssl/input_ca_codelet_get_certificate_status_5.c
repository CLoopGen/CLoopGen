#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char *row[6];
int i;

void init_vars() {
    for (int j = 0; j < 6; j++) {
        row[j] = malloc(200000); // Allocate ~200KB per pointer to ensure sufficient data size
        if (!row[j]) {
            exit(1);
        }
    }
}