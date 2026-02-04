#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern float *b;
extern BLASLONG i;
extern float *a_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1, temp2;
    for (i = 0; i < m; i++) {
        temp1 = *(a_offset + 0);
        temp2 = *(a_offset + 1);
        *(b + 0) = temp1 + temp2;
        a_offset += 2;
        b++;
    }
}
