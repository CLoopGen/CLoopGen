#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *stack_usage_map;
int i;
int lower_bound;
int upper_bound;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    stack_usage_map = (char*)calloc(data_size, sizeof(char));
    lower_bound = 0;
    upper_bound = data_size;
}