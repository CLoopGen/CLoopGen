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
for (i = 0; i < n2; i++) {
    for (j = 0; j < n3; j += 2) {
        {
            register char *_to1, *_from1;
            register int _i, _l;
            _l = sizeof(float);
            // Unroll two iterations to increase computational intensity
            if (j + 1 < n3) {
                _to1 = (char *)(&(new->hidden_weights[i][j]));
                _from1 = (char *)(&mem[memcnt]);
                for (_i = 0; _i < _l; _i++)
                    *_to1++ = *_from1++;
                memcnt += sizeof(float);

                _to1 = (char *)(&(new->hidden_weights[i][j+1]));
                _from1 = (char *)(&mem[memcnt]);
                for (_i = 0; _i < _l; _i++)
                    *_to1++ = *_from1++;
                memcnt += sizeof(float);
            } else {
                _to1 = (char *)(&(new->hidden_weights[i][j]));
                _from1 = (char *)(&mem[memcnt]);
                for (_i = 0; _i < _l; _i++)
                    *_to1++ = *_from1++;
                memcnt += sizeof(float);
            }
        }
    }
}
}
