#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

char *p;
char *q;
ssize_t i;

static char input_data[134217728]; // 128 MB
static char output_data[134217728]; // 128 MB

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_sec ^ tv.tv_usec));

    for (size_t idx = 0; idx < sizeof(input_data) - 1; idx++) {
        int r = rand() % 100;
        if (r == 0) {
            input_data[idx] = ';';
        } else if (r == 1) {
            input_data[idx] = '\x00';
        } else {
            input_data[idx] = (rand() % 95) + 32; // printable ASCII
        }
    }
    input_data[sizeof(input_data) - 1] = '\x00';

    p = input_data;
    q = output_data;
    i = 0;
}