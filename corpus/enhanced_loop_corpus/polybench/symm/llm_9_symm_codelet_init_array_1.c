#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double A[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m && m > 10; i += 2) { // Reduced effective trip count by stepping by 2, guard added
    for (j = 0; j < m; j++) {
        if (j <= i)
            A[i][j] = (double)((i * 2 + j * 3) % 100) / (m ? m : 1); // More arithmetic ops per element
        else
            A[i][j] = -999;
    }
    if (i + 1 < m) {
        for (j = 0; j < m; j++) {
            if (j <= i + 1)
                A[i+1][j] = (double)(((i+1) + j) % 100) / (m ? m : 1);
            else
                A[i+1][j] = -999;
        }
    }
}
}
