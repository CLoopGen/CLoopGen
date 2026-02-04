#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern complex **A_me;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)malloc((hi - lo + 1) * sizeof(int));
for (int idx = 0; idx <= hi - lo; idx++) {
    index_map[idx] = lo + idx;
}
for (int idx = 0; idx <= hi - lo; idx++) {
    int k = index_map[idx];
    tmp = A_me[i][k];
    A_me[i][k] = A_me[j][k];
    A_me[j][k] = tmp;
}
free(index_map);
}
