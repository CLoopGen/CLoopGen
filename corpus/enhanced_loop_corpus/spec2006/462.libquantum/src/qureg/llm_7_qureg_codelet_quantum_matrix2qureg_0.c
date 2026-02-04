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
    int local_size = size;
    for (i = 0; i < m->rows; i++) {
        _Complex float val = m->t[i];
        if (__imag__(val) != 0.0f || __real__(val) != 0.0f)
            local_size++;
    }
    size = local_size;
}
