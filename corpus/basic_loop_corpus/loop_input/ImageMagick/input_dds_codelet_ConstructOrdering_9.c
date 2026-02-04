#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t count = 65536; 

float dps[16];

float f;

ssize_t i;
ssize_t j;

unsigned char c;

unsigned char *o = NULL;

void init_vars() {
    for (size_t idx = 0; idx < 16; idx++) {
        dps[idx] = (float)(16 - idx); 
    }

    if (o == NULL) {
        o = malloc(count * sizeof(unsigned char));
        if (!o) {
            exit(1);
        }
    }

    for (size_t idx = 0; idx < count; idx++) {
        o[idx] = (unsigned char)(count - idx);
    }

    i = 0;
    j = 0;
    f = 0.0f;
    c = 0;
}