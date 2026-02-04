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
int *index_map_i = (int*)malloc((n2 + 1) * sizeof(int));
int *index_map_j = (int*)malloc((n3 + 1) * sizeof(int));
for (int idx = 0; idx <= n2; idx++) index_map_i[idx] = (n2 - idx); // reverse mapping for i
for (int idx = 0; idx <= n3; idx++) index_map_j[idx] = (idx * 2) % (n3 + 1); // strided access via modulo

for (int ii = 0; ii <= n2; ii++) {
    int mapped_i = index_map_i[ii];
    for (int jj = 0; jj <= n3; jj++) {
        int mapped_j = index_map_j[jj];
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&(new->hidden_weights[mapped_i][mapped_j]));
            _from = (char *)(&mem[memcnt]);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        ;
        memcnt += sizeof(float);
    }
}
free(index_map_i);
free(index_map_j);
}
