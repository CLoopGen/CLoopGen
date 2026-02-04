#include <stdio.h>
#include <inttypes.h>

int loop_length[3];
int loop_num[3];
double loop_coeff[3][1];
int i;
int j;
int loop_length_in[3];

void init_vars() {
    for (int j = 0; j < 3; j++) {
        loop_length_in[j] = 1000000;  // Sufficient size to achieve ~0.01 sec runtime
        loop_num[j] = 0;
        loop_length[j] = 0;
        for (int i = 0; i < 1; i++) {
            loop_coeff[j][i] = 0.0;
        }
    }
}