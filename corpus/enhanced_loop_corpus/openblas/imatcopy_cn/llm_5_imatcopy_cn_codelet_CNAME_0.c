#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
        if (aptr[j] != 0.0f) {
            aptr[j] = alpha * aptr[j];
        }
    }
    aptr += lda;
}
}
