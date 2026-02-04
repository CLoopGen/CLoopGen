#include <stdio.h>

#include <inttypes.h>

extern int loop_length[3];
extern int loop_num[3];
extern double loop_coeff[3][1];
extern int i;
extern int j;
extern int loop_length_in[3];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 3; j++) {
    loop_num[j] = 0;
    loop_length[j] = loop_length_in[j];
    for (i = 0; i < 1; i++) {
        loop_coeff[j][i] = 0.;
    }
}

}
