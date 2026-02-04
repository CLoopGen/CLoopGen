#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int input_rows;
extern int input_cols;
extern float *output;
extern int output_rows;
extern int output_cols;
extern int i;
extern int j;
extern int i2;
extern int j2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0 , i2 = 0; i < output_rows; i++ , i2++) {
    if (i2 >= input_rows) {
        i2 = i2 - input_rows;
    }
    for (j = 0 , j2 = 0; j < output_cols; j++ , j2++) {
        if (j2 >= input_cols) {
            j2 = j2 - input_cols;
        }
        output[i * output_cols + j] = input[i2 * input_cols + j2];
    }
}

}
