#include <stdio.h>
#include <inttypes.h>

typedef int I32;

char *PL_bufend;
char *t;
char win32_open;
char close;
I32 brackets;

static char *PL_bufend_ptr;
static char input_buffer[1 << 24]; // 16 MB buffer

void init_vars() {
    PL_bufend_ptr = input_buffer + sizeof(input_buffer) - 1;
    PL_bufend = PL_bufend_ptr;
    t = input_buffer;
    win32_open = '(';
    close = ')';
    brackets = 1;

    for (size_t i = 0; i < sizeof(input_buffer) - 1; i++) {
        input_buffer[i] = 'a' + (i % 26);
    }
    input_buffer[sizeof(input_buffer) - 1] = '\0';
}