#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern float *y;
extern int N;
extern float num0;
extern float num1;
extern float num2;
extern float num3;
extern float num4;
extern float mem0;
extern float mem1;
extern float mem2;
extern float mem3;
extern float mem4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float delay_line[5] = {mem0, mem1, mem2, mem3, mem4};

    for (int i = 0; i < N; i++) {
        float sum = x[i];
        sum += num0 * delay_line[0];
        sum += num1 * delay_line[1];
        sum += num2 * delay_line[2];
        sum += num3 * delay_line[3];
        sum += num4 * delay_line[4];

        for (int j = 4; j > 0; j--) {
            delay_line[j] = delay_line[j-1];
        }
        delay_line[0] = x[i];

        y[i] = sum;
    }

    mem0 = delay_line[0];
    mem1 = delay_line[1];
    mem2 = delay_line[2];
    mem3 = delay_line[3];
    mem4 = delay_line[4];
}
