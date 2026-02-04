#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ans = 0.0;
    for (i = len - 1; i > 0; i--) {
        if (c[i - 1] >= 0.0) {
            ans = c[i - 1] + x * ans;
        } else {
            ans = x * ans;
        }
    }
}
