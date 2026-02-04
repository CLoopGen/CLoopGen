#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s1;
char *s2;
int diff;
int valid;

static char data_s1[1 << 20];
static char data_s2[1 << 20];

void init_vars() {
    s1 = data_s1;
    s2 = data_s2;
    diff = 0;
    valid = 0;

    size_t size = sizeof(data_s1);
    for (size_t i = 0; i < size - 1; i++) {
        data_s1[i] = 'a' + (i % 26);
        data_s2[i] = 'a' + ((i + 1) % 26);
    }
    data_s1[size - 1] = '\x00';
    data_s2[size - 1] = '\x00';
}