#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

char *p;
char *q;
char *xpm_buffer;
MagickBooleanType active;

static char input_data[131072]; // 128KB buffer

void init_vars() {
    size_t data_size = sizeof(input_data);
    
    // Initialize input_data with alternating quotes and non-quote characters
    for (size_t i = 0; i < data_size - 1; i += 4) {
        input_data[i] = 'a';
        input_data[i+1] = '"';
        input_data[i+2] = 'b';
        input_data[i+3] = 'c';
    }
    // Ensure null termination at the end
    input_data[data_size - 1] = '\x00';

    // Allocate output buffer (same size as input, plus margin)
    char *output_buffer = malloc(data_size * 2);
    if (!output_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize pointers
    p = input_data;
    xpm_buffer = output_buffer;
    q = xpm_buffer;
    active = MagickFalse;
}