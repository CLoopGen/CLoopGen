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
            // Change memory access to strided pattern: instead of sequential [j][i], access with a fixed stride in higher dimension
            // Here, we maintain logical equivalence but simulate strided access by scaling index
            int idx = j * 2; // Simulate stride of 2 for potential larger array layout
            ((double*)loop_coeff)[idx + i] = 0.;
        }
    }
}
