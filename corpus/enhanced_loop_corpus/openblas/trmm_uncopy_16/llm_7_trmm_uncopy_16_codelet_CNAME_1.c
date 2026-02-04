#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_b = b;
for (ii = 0; ii < i; ii++) {
    *(local_b + 0)  = *(a01++);
    *(local_b + 1)  = *(a02++);
    *(local_b + 2)  = *(a03++);
    *(local_b + 3)  = *(a04++);
    *(local_b + 4)  = *(a05++);
    *(local_b + 5)  = *(a06++);
    *(local_b + 6)  = *(a07++);
    *(local_b + 7)  = *(a08++);
    *(local_b + 8)  = *(a09++);
    *(local_b + 9)  = *(a10++);
    *(local_b + 10) = *(a11++);
    *(local_b + 11) = *(a12++);
    *(local_b + 12) = *(a13++);
    *(local_b + 13) = *(a14++);
    *(local_b + 14) = *(a15++);
    *(local_b + 15) = *(a16++);

    local_b += 16;
}
b = local_b; 
}
