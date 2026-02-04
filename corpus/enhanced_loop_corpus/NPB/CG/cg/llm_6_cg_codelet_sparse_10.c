#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    for (j = 1; j <= n; j++) {
        mark[j] = 0;
        rowstr[j] = mark[j]; // Introduces RAW dependency: mark[j] is read after write
    }
}
