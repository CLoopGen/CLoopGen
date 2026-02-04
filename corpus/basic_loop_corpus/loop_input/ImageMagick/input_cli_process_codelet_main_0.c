#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int arg_count;
char **args;

void init_vars() {
    const int num_args = 100000; // Large enough to take ~0.01s (depends on system)
    args = malloc((num_args + 1) * sizeof(char*));
    if (!args) exit(1);

    for (int i = 0; i < num_args; i++) {
        args[i] = malloc(1);
        if (!args[i]) exit(1);
        args[i][0] = 'a';
    }
    args[num_args] = (char *)((void *)0); // Null terminator
}