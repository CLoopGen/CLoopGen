#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char **newargv;
char *argv[1024];
int i;
int count = 512;

void init_vars() {
    for (int j = 0; j < count; j++) {
        argv[j] = malloc(256);
        sprintf(argv[j], "arg%d", j);
    }

    newargv = malloc(count * sizeof(char*));
    for (int j = 0; j < count; j++) {
        newargv[j] = NULL;
    }
}