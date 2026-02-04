#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    int indices[] = {1, 3, 5, 2, 4, 6}; // Example of indirect access pattern
    int size = lastcol - firstcol + 1;
    for (j = 0; j < size && j < 6; j++) {
        rho = rho + r[indices[j]] * r[indices[j]];
    }
}
