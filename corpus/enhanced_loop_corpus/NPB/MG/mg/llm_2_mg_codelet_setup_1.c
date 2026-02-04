#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal using pointer arithmetic
    int *px = nx + lt;
    int *py = ny + lt;
    int *pz = nz + lt;
    for (k = lt - 1; k >= 1; k--) {
        --px; --py; --pz;
        *px = *(px + 1) / 2;
        *py = *(py + 1) / 2;
        *pz = *(pz + 1) / 2;
    }
}
