#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *m1;
char *m2;
char bdiff[81];
size_t i;
unsigned int diff;
size_t j;

void init_vars() {
    j = 80;
    i = 0;
    diff = 0;

    m1 = (char*)malloc(j);
    m2 = (char*)malloc(j);

    for (size_t idx = 0; idx < j; idx++) {
        m1[idx] = (char)(32 + (idx % 95));
        m2[idx] = (char)(32 + ((idx + 1) % 95));
    }

    memset(bdiff, ' ', j);
}