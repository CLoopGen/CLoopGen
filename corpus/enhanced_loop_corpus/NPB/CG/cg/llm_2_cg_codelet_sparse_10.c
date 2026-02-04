#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order (backward traversal)
    for (j = n; j >= 1; j--) {
        rowstr[j] = 0;
        mark[j] = 0;
    }
}
