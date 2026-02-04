#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;

char *to;
char *toend;
char *from;
char *fromend;
int delim;
I32 tolen;

static char *from_buffer = NULL;
static char *to_buffer = NULL;

void init_vars() {
    const size_t input_size = 64 << 20; // 64 MB input
    const size_t output_size = input_size; // Worst case: same size

    from_buffer = (char*)malloc(input_size);
    to_buffer = (char*)malloc(output_size);
    if (!from_buffer || !to_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill from_buffer with sample data containing backslashes and delimiters
    for (size_t i = 0; i < input_size - 1; i++) {
        if (rand() % 16 == 0) {
            from_buffer[i] = '\\';
            // Occasionally followed by delim, sometimes not
            if (rand() % 2 == 0)
                from_buffer[++i] = delim;
            else
                from_buffer[++i] = 'X';
        } else if (rand() % 32 == 0) {
            from_buffer[i] = delim;
        } else {
            from_buffer[i] = 'a' + (i % 26);
        }
    }
    from_buffer[input_size - 1] = '\0'; // Ensure termination

    delim = '"'; // Choose a delimiter

    from = from_buffer;
    fromend = from_buffer + input_size;
    to = to_buffer;
    toend = to_buffer + output_size;
    tolen = 0;
}