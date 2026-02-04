#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; i < n1; i += 4) {
    dot += y[i] * x[i] + y[i + 1] * x[i + 1] + y[i + 2] * x[i + 2] + y[i + 3] * x[i + 3];
}

}
