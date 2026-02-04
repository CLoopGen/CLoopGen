#include <stdio.h>

#include <inttypes.h>

struct quantum_matrix_struct {
    int rows;
    int cols;
    _Complex float *t;
};


typedef struct quantum_matrix_struct quantum_matrix;

extern quantum_matrix *m;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (m->rows > 100 ? 100 : m->rows); i += 2) {
        if (__imag__(m->t[i]) > 0.0f)
            size++;
    }
}
