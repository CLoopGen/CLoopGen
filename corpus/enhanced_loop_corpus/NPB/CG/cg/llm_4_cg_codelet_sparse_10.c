#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    for (j = 1; j <= n; j++) {
        if (j % 2 == 0) {
            rowstr[j] = 0;
        } else {
            mark[j] = 0;
        }
    }
}
