#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int utf8_length;
unsigned char *utf8_value;
int i;
int isdnsname;

void init_vars() {
    const size_t data_size = 512 * 1024; // 512 KB of input data

    utf8_value = (unsigned char *)malloc(data_size);
    if (!utf8_value) {
        utf8_length = 0;
        isdnsname = 0;
        return;
    }

    utf8_length = data_size;

    for (size_t idx = 0; idx < utf8_length; ++idx) {
        double r = rand() / (double)RAND_MAX;
        if (r < 0.6) {
            utf8_value[idx] = 'a' + (rand() % 26);
        } else if (r < 0.8) {
            utf8_value[idx] = '0' + (rand() % 10);
        } else if (r < 0.85) {
            utf8_value[idx] = '-';
        } else if (r < 0.95) {
            utf8_value[idx] = '.';
        } else {
            utf8_value[idx] = '_';
        }
    }

    i = 0;
    isdnsname = 1;
}