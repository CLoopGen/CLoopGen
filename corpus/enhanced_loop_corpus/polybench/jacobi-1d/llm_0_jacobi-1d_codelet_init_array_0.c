#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < n; i++) {
    for (j = 0; j < 1; j++) {  // Artificially increased nesting depth with a single-iteration inner loop
        A[i] = ((double)i + 2) / n;
        B[i] = ((double)i + 3) / n;
    }
}
}
