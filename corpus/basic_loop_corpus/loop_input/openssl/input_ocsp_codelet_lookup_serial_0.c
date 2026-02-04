#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
char *row[6];

void init_vars() {
    for (int j = 0; j < 6; j++) {
        row[j] = malloc(256 * 1024); // Allocate ~256KB per pointer
        if (row[j] != NULL) {
            memset(row[j], 0, 256 * 1024);
        }
    }
}