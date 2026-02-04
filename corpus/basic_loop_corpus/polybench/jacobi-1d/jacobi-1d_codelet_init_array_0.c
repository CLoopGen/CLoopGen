#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; i++) {
    A[i] = ((double)i + 2) / n;
    B[i] = ((double)i + 3) / n;
}

}
