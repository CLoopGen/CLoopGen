#include <stdio.h>
#include <string.h>

int j;
char size[14];

void init_vars() {
    j = 13;
    for (int i = 0; i < 14; i++) {
        size[i] = '.';
    }
    size[13] = '\0';
}