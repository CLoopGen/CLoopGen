#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
uint8_t **in;
int len = 1048576;        // 1MB per channel
int channels = 2;
int ch;
int out_bps = 2097152;    // out bytes per channel: 2 * len
int is = 1;               // input stride
int os = 2;               // output stride
int in_elements = 2;

void init_vars() {
    out = calloc(out_bps * channels, sizeof(uint8_t));
    if (!out) exit(1);

    in = malloc(channels * sizeof(uint8_t*));
    if (!in) exit(1);

    for (int i = 0; i < channels; i++) {
        in[i] = malloc(len * is * sizeof(uint8_t));
        if (!in[i]) exit(1);
        for (int j = 0; j < len; j++) {
            in[i][j * is] = rand() % 256;
        }
    }
}