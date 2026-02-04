#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *line;
int *error;
unsigned long result;

static char data_buffer[134217728]; // 128MB buffer to ensure ~0.01s runtime

void init_vars() {
    // Initialize large numeric string: many '1' digits to stay within safe integer growth
    memset(data_buffer, '1', sizeof(data_buffer) - 1);
    data_buffer[sizeof(data_buffer) - 1] = '\0';

    line = data_buffer;
    error = (int*)malloc(sizeof(int));
    *error = 0;
    result = 0;
}