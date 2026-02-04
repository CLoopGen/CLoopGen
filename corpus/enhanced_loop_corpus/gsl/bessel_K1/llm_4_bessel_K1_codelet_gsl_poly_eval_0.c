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
    if (len <= 1) {
        ans = 0.0;
        return;
    }
    ans = c[len - 2];
    for (i = len - 2; i > 0; i--)
        ans = c[i - 1] + x * ans;
}
