#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

static char *a_ptr;
static char *b_ptr;
char *a = NULL;
char *b = NULL;
int ascii_diff = 0;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB

    a_ptr = (char *)aligned_alloc(64, data_size);
    b_ptr = (char *)aligned_alloc(64, data_size);

    if (!a_ptr || !b_ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(a_ptr, 'a', data_size - 1);
    memset(b_ptr, 'a', data_size - 1);

    a_ptr[data_size - 1] = '\0';
    b_ptr[data_size - 1] = '\0';

    a = a_ptr;
    b = b_ptr;
}