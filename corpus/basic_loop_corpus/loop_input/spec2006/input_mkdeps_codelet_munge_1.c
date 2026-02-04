#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *filename;
char *p;
char *q;
char *dst;
char *buffer;

static char *internal_filename;
static char *internal_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    internal_filename = (char*)malloc(data_size);
    if (!internal_filename) exit(1);

    internal_buffer = (char*)malloc(data_size * 2); // worst-case: every space escaped
    if (!internal_buffer) exit(1);

    // Initialize filename content with mixed characters including spaces, tabs, '$', and backslashes
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 20;
        if (r == 0) internal_filename[i] = ' ';
        else if (r == 1) internal_filename[i] = '\t';
        else if (r == 2) internal_filename[i] = '$';
        else if (r == 3 || r == 4) internal_filename[i] = '\\';
        else internal_filename[i] = 'a' + (r % 26);
    }
    internal_filename[data_size - 1] = '\0';

    filename = internal_filename;
    buffer = internal_buffer;
    p = NULL;
    q = NULL;
    dst = NULL;
}

// Ensure definitions are present for linkage
char *filename;
char *p;
char *q;
char *dst;
char *buffer;