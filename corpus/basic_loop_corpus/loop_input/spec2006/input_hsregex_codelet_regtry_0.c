#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int i;
char **stp;
char **enp;

#define ARRAY_SIZE 10

static char *start_array[ARRAY_SIZE];
static char *end_array[ARRAY_SIZE];

void init_vars() {
    stp = start_array;
    enp = end_array;
}