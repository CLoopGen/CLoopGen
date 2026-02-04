#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++)
    for (j = 0; j < n; j += 2)
        A[i][j] = (double)((i + j) % n) / (5 * m);
if (n > 0)
    for (i = 0; i < m; i++)
        for (j = 1; j < n; j += 2)
            A[i][j] = (double)((i + j) % n) / (5 * m);
}
