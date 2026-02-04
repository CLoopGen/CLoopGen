#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int8_t ff_cb1_vects[128][40] = {0};
const int8_t ff_cb2_vects[128][40] = {0};
float cb1[40] = {0};
float cb2[40] = {0};
int cb1_idx = 0;
int cb2_idx = 0;
int i = 0;

void init_vars() {
    for (int idx = 0; idx < 128; idx++) {
        for (int j = 0; j < 40; j++) {
            ((int8_t*)ff_cb1_vects)[idx * 40 + j] = rand() % 256 - 128;
            ((int8_t*)ff_cb2_vects)[idx * 40 + j] = rand() % 256 - 128;
        }
    }
    cb1_idx = 0;
    cb2_idx = 0;
}