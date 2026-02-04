#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s1;
char *s2;
int *s1_list;
int col;
int r1;
int r2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec on modern CPU)

    // Allocate s1 and s2 as character arrays of size data_size + 1 (for null terminator)
    s1 = (char*)malloc(data_size + 1);
    s2 = (char*)malloc(data_size + 1);
    s1_list = (int*)malloc(data_size * sizeof(int)); // worst-case: every char triggers write

    if (!s1 || !s2 || !s1_list) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize s1 and s2 with mixed printable characters to trigger both branches
    for (size_t i = 0; i < data_size; i++) {
        // Use a repeating pattern including allowed and disallowed chars
        unsigned char c1 = (unsigned char)((i % 95) + 32); // ASCII 32-126
        unsigned char c2 = (unsigned char)(((i + 47) % 95) + 32);

        s1[i] = (char)c1;
        s2[i] = (char)c2;
    }

    // Null terminate both strings
    s1[data_size] = '\x00';
    s2[data_size] = '\x00';

    // Initialize loop counters
    col = 0;
    r1 = 0;
    r2 = 0;
}