#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s1;
char *s2;
int *s1_list;
int col;
int r1;
int r2;
int *canons1;
int lpos;

static char s1_buffer[131072];
static char s2_buffer[131072];
static int s1_list_buffer[131072];
static int canons1_buffer[131072];

void init_vars() {
    const size_t data_size = 131072; // ~128KB per buffer

    // Initialize buffers with printable characters to control condition branches
    for (size_t i = 0; i < data_size - 1; i++) {
        s1_buffer[i] = (i % 16) ? " abc._~-~def"[i % 11] : 'X'; // mostly valid, some 'X' to trigger conditions
        s2_buffer[i] = (i % 16) ? " xyz._~-~uvw"[i % 11] : 'Y';
        canons1_buffer[i] = (i % 7) != 0; // sporadic true values
    }
    s1_buffer[data_size - 1] = '\x00'; // null terminate s1
    s2_buffer[data_size - 1] = 'Z';    // ensure s2 not null-terminated early

    // Assign external pointers
    s1 = s1_buffer;
    s2 = s2_buffer;
    s1_list = s1_list_buffer;
    canons1 = canons1_buffer;

    // Initialize scalar variables
    col = 0;
    r1 = 0;
    r2 = 0;
    lpos = 0;
}