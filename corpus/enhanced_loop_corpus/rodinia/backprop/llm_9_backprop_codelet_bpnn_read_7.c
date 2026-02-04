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
int stride = 2;
for (i = 0; i <= n1; i += stride) {
    if (i + 1 <= n1) {
        for (j = 0; j <= n2; j++) {
            {
                register char *_to1, *_from1;
                register int _i1, _l1;
                _to1 = (char *)(&(new->input_weights[i][j]));
                _from1 = (char *)(&mem[memcnt]);
                _l1 = (sizeof(float));
                for (_i1 = 0; _i1 < _l1; _i1++)
                    *_to1++ = *_from1++;
            }
            memcnt += sizeof(float);
            {
                register char *_to2, *_from2;
                register int _i2, _l2;
                _to2 = (char *)(&(new->input_weights[i+1][j]));
                _from2 = (char *)(&mem[memcnt]);
                _l2 = (sizeof(float));
                for (_i2 = 0; _i2 < _l2; _i2++)
                    *_to2++ = *_from2++;
            }
            memcnt += sizeof(float);
        }
    } else {
        for (j = 0; j <= n2; j++) {
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
        }
    }
}
}
