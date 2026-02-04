#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t num_colors = 100000;
int64_t *colors;
size_t *choices;

void init_vars() {
    colors = (int64_t*)malloc(num_colors * sizeof(int64_t));
    size_t total_choices = 0;
    for (size_t i = 0; i < num_colors; ++i) {
        colors[i] = (i % 128) + 1;
        total_choices += colors[i];
    }
    choices = (size_t*)malloc(total_choices * sizeof(size_t));
}