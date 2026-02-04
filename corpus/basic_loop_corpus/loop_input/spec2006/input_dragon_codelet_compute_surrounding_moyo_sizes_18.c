#include <stdio.h>
#include <inttypes.h>

int pos;
float moyo_sizes[400];
float moyo_values[400];

void init_vars() {
    for (int i = 0; i < 400; i++) {
        moyo_sizes[i] = 0.0f;
        moyo_values[i] = 0.0f;
    }
}