#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float output[32][4];

float **input;
ptrdiff_t ofs;
ptrdiff_t len;

float SW0;
float SW1;
float SW2;
float SW3;
float C1;
float C2;
float C3;
float C4;
int i;

void init_vars() {
    len = 32;
    ofs = 4; 

    SW0 = 1.0f;
    SW1 = 0.5f;
    SW2 = 0.25f;
    SW3 = 0.75f;
    C1 = 1.1f;
    C2 = 1.2f;
    C3 = 1.3f;
    C4 = 1.4f;

    input = (float**)calloc(len, sizeof(float*));
    for (int idx = 0; idx < len; idx++) {
        input[idx] = (float*)calloc(8, sizeof(float)); 
    }

    for (int idx = 0; idx < len; idx++) {
        for (int j = 0; j < 8; j++) {
            input[idx][j] = (float)(idx * 8 + j);
        }
    }
}