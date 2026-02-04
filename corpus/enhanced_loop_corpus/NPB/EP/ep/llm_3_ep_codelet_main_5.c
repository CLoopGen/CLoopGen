#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    int indices[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (i = 0; i <= 10 - 1; i++) {
        int j = indices[i];
        q[j] += qq[j];
    }
}
