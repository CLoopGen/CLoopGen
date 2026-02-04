#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    int limit = n * 2;
    for (j = 1; j <= limit; j++) {
        int idx = j % n == 0 ? n : j % n;
        rowstr[idx] = 0;
        mark[idx] = 0;
    }
}
