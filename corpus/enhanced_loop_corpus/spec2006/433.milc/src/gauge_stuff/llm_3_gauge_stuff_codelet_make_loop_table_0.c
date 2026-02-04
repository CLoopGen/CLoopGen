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
    // Use indirect memory access via an index mapping array to alter access pattern
    int index_map[3] = {2, 0, 1}; // Reorder access: process j=2 first, then j=0, then j=1

    for (j = 0; j < 3; j++) {
        int mapped_j = index_map[j]; // Indirect access using mapped index
        loop_num[mapped_j] = 0;
        loop_length[mapped_j] = loop_length_in[mapped_j];
        for (i = 0; i < 1; i++) {
            loop_coeff[mapped_j][i] = 0.;
        }
    }
}
