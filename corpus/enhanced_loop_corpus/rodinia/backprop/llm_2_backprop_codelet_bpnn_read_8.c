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
extern int n2;
extern int n3;
extern int i;
extern int j;
extern int memcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n2; i >= 0; i--) {
    for (j = n3; j >= 0; j--) {
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&(new->hidden_weights[i][j]));
            _from = (char *)(&mem[memcnt - (n2 - i) * (n3 + 1) * sizeof(float) - (n3 - j) * sizeof(float)]);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        ;
        memcnt += sizeof(float);
    }
}
}
