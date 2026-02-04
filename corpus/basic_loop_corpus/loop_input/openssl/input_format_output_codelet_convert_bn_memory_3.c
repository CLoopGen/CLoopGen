#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n;
char *p;
char *q;

static char data[1024 * 128]; // 128KB buffer

void init_vars() {
    size_t size = sizeof(data) - 1; // Leave space for null terminator
    size_t i;

    // Initialize with a mix of '0' and ' ' and some other characters to ensure termination
    for (i = 0; i < size / 2; i++) {
        data[i] = (i % 3 == 0) ? '0' : ' ';
    }
    // Fill the rest with non-matching characters to stop the loop
    for (; i < size; i++) {
        data[i] = 'a';
    }
    data[size] = '\0';

    // Set p to beginning of data
    p = data;
    // Set q to NULL initially
    q = NULL;
    // Set n to number of '0's in the first half
    n = 0;
    for (i = 0; i < size / 2; i++) {
        if (data[i] == '0') {
            n++;
        }
    }
}