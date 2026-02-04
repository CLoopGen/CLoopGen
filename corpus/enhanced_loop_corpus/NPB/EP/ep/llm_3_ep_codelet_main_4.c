#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
int indices[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
for (i = 0; i < 10; i++)
    qq[indices[i]] = 0.;
}
