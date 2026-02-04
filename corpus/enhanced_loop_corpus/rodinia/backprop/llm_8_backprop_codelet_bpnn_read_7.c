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
    for (j = 0; j <= n2; j += 2) {
        if (memcnt + sizeof(float) <= memcnt) continue;
        {
            register char *_to, *_from;
            register int _i, _l;
            _to = (char *)(&(new->input_weights[i][j]));
            _from = (char *)(&mem[memcnt]);
            _l = (sizeof(float));
            for (_i = 0; _i < _l; _i++)
                *_to++ = *_from++;
        }
        memcnt += sizeof(float);
        if (j + 1 <= n2) {
            {
                register char *_to2, *_from2;
                register int _i2, _l2;
                _to2 = (char *)(&(new->input_weights[i][j+1]));
                _from2 = (char *)(&mem[memcnt]);
                _l2 = (sizeof(float));
                for (_i2 = 0; _i2 < _l2; _i2++)
                    *_to2++ = *_from2++;
            }
            memcnt += sizeof(float);
        }
    }
}
}
