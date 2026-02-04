#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char **units;
double bytes;
double extent;
ssize_t i;

void init_vars() {
    bytes = 1024.0; 
    extent = 268435456.0; 

    units = (char **)calloc(100, sizeof(char *));
    if (!units) exit(1);

    for (int j = 0; j < 99; j++) {
        units[j] = (char *)calloc(4, sizeof(char));
        if (!units[j]) exit(1);
        sprintf(units[j], "U%d", j);
    }
    units[99] = (char *)((void *)0);
}