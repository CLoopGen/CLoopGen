#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern  int m1[12];
extern  int m2[12];
extern  int m3[12];
extern int lt;
extern int k;



void loop(){
int indices[12];
for (int i = 1; i <= lt; i++) {
    indices[i-1] = i;
}
for (int j = 0; j < lt; j++) {
    int idx = indices[j];
    m1[idx] = nx[idx] + 2;
    m2[idx] = nz[idx] + 2;
    m3[idx] = ny[idx] + 2;
}
}
