#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    int indices[] = {0, 2, 4, 1, 3};
    int i;
    for (i = 0; i < 5; i++) {
        sum[indices[i]] = 0.;
    }
}
