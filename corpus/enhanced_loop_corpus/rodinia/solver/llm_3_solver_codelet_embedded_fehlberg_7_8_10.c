#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b11_1;
extern  float b11_4;
extern  float b11_5;
extern  float b11_6;
extern  float b11_7;
extern  float b11_8;
extern  float b11_9;
extern  float b11_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Order Traversal
    // Accesses array elements with a stride of 3 and processes in reverse to alter access pattern
    int i;
    for (i = 90; i >= 0; i -= 3) {
        // Base index
        initvalu_temp[i] = initvalu[i] + h * (
            b11_1  * finavalu_temp[0][i]  +
            b11_4  * finavalu_temp[3][i]  +
            b11_5  * finavalu_temp[4][i]  +
            b11_6  * finavalu_temp[5][i]  +
            b11_7  * finavalu_temp[6][i]  +
            b11_8  * finavalu_temp[7][i]  +
            b11_9  * finavalu_temp[8][i]  +
            b11_10 * finavalu_temp[9][i]
        );

        // Process i-1 if valid
        if (i - 1 >= 0) {
            initvalu_temp[i-1] = initvalu[i-1] + h * (
                b11_1  * finavalu_temp[0][i-1]  +
                b11_4  * finavalu_temp[3][i-1]  +
                b11_5  * finavalu_temp[4][i-1]  +
                b11_6  * finavalu_temp[5][i-1]  +
                b11_7  * finavalu_temp[6][i-1]  +
                b11_8  * finavalu_temp[7][i-1]  +
                b11_9  * finavalu_temp[8][i-1]  +
                b11_10 * finavalu_temp[9][i-1]
            );
        }

        // Process i-2 if valid
        if (i - 2 >= 0) {
            initvalu_temp[i-2] = initvalu[i-2] + h * (
                b11_1  * finavalu_temp[0][i-2]  +
                b11_4  * finavalu_temp[3][i-2]  +
                b11_5  * finavalu_temp[4][i-2]  +
                b11_6  * finavalu_temp[5][i-2]  +
                b11_7  * finavalu_temp[6][i-2]  +
                b11_8  * finavalu_temp[7][i-2]  +
                b11_9  * finavalu_temp[8][i-2]  +
                b11_10 * finavalu_temp[9][i-2]
            );
        }
    }
}
