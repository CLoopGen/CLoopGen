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
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = m->rows - 1; i >= 0; i--) {
        if (m->t[i])
            size++;
    }
}
