#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **samples;
int16_t **matrix;
int in_ch;
int len;
int i;
int j;
int v0;

void init_vars() {
    len = 65536;  
    in_ch = 8;

    matrix = (int16_t**)calloc(1, sizeof(int16_t*));
    matrix[0] = (int16_t*)calloc(in_ch, sizeof(int16_t));
    for (j = 0; j < in_ch; j++) {
        matrix[0][j] = (int16_t)(j + 1);
    }

    samples = (int16_t**)calloc(in_ch, sizeof(int16_t*));
    for (i = 0; i < in_ch; i++) {
        samples[i] = (int16_t*)calloc(len, sizeof(int16_t));
        for (j = 0; j < len; j++) {
            samples[i][j] = (int16_t)((j + i) & 0x7FF); 
        }
    }
}