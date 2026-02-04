#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern double *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = m; i + 3 < N; i += 4) {
        for (int j = 0; j < 1; j++) {  // Artificially increased loop depth by nesting a single-iteration loop
            Y[i] += alpha * X[i];
            Y[i + 1] += alpha * X[i + 1];
            Y[i + 2] += alpha * X[i + 2];
            Y[i + 3] += alpha * X[i + 3];
        }
    }
}
