#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    for (int i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            rowstr[j] = 0;
            mark[j] = 0;
        }
    }
}
