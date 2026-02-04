#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = *n; j >= 1; --j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        real sum = 0.0f;
        for (i__ = j - 1; i__ >= 1; --i__) {
            sum += a[i__ + j * a_dim1] * x[i__];
        }
        temp += sum;
        x[j] = temp;
    }
}
