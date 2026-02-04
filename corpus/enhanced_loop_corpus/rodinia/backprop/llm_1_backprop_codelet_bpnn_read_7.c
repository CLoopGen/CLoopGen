#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int input_n;
    int hidden_n;
    int output_n;
    float *input_units;
    float *hidden_units;
    float *output_units;
    float *hidden_delta;
    float *output_delta;
    float *target;
    float **input_weights;
    float **hidden_weights;
    float **input_prev_weights;
    float **hidden_prev_weights;
} BPNN;

extern char *mem;
extern BPNN *new;
extern int n1;
extern int n2;
extern int i;
extern int j;
extern int memcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= n1; i++) {
    for (j = 0; j <= n2; j++) {
        for (int k = 0; k < sizeof(float); k++) {
            ((char *)(&(new->input_weights[i][j])))[k] = mem[memcnt + k];
        }
        memcnt += sizeof(float);
    }
}
}
