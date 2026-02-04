#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern void *p;
extern npy_intp stride;
extern npy_intp n;
extern int size;
extern char *a;
extern char *b;
extern char c;
extern int j;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (a = (char *)p; n > 0; n--, a += stride - m) {
        b = a + (size - 1);
        char temp_a, temp_b;
        for (j = 0; j < m; j++, a++, b--) {
            temp_a = *a;
            temp_b = *b;
            *a = temp_b;
            *b = temp_a;
        }
        a -= m;  
    }
}
