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
    for (i = 0; i < len; i++) {
        ans += c[i] * x;
    }
}
