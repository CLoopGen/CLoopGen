#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n; i += 2) {  // Modified trip count: step by 2, start later → reduced iterations
    for (j = 0; j < i - 1; j++) {
        w = A[i][j];
        for (k = 0; k < (j + 1) / 2; k++) {  // Halve inner loop work approximately
            w -= A[i][k] * A[k][j];
        }
        if (j > 0) A[i][j] = w / A[j][j];
    }
    for (j = i; j < n - 1; j++) {
        w = A[i][j];
        for (k = 0; k < (i + 1) / 2; k++) {  // Reduce dependency on full i range
            w -= A[i][k] * A[k][j];
        }
        A[i][j] = w;
    }
    // Duplicate minimal update for next row to preserve some data flow
    if (i + 1 < n) {
        for (j = 0; j < n; j++) {
            if (j < i) A[i+1][j] = A[i+1][j] - A[i+1][0] * A[0][j];
        }
    }
}
}
