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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < m->rows; i += 2) {
        if (i < m->rows && m->t[i])
            size++;
        if (i + 1 < m->rows && m->t[i + 1])
            size++;
    }
}
