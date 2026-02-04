#include <stdio.h>
#include <inttypes.h>

double PPictureMAD[21] = {0};
double PictureMAD[21] = {0};
double ReferenceMAD[21] = {0};
int i;

void init_vars() {
    for (int j = 0; j < 21; j++) {
        PPictureMAD[j] = (double)(j * 10 + 1);
        ReferenceMAD[j] = (double)(j * 5 + 3);
    }
}