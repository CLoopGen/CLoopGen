#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *exp_str;
char exp_buf[19];
int i;
int j;
int exp_buf_len;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    char *data = (char *)malloc(input_size);
    if (!data) exit(1);

    for (size_t k = 0; k < input_size - 1; k++) {
        int r = rand() % 100;
        if (r < 70) {
            data[k] = 'A' + (rand() % 26);
        } else if (r < 85) {
            data[k] = 'a' + (rand() % 26);
        } else if (r < 100) {
            data[k] = '0' + (rand() % 10);
        }
    }
    data[input_size - 1] = '\x00';

    exp_str = data;
    exp_buf_len = 19;
    i = 0;
    j = 0;
    memset(exp_buf, 0, 19);
}