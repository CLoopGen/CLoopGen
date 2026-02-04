#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int size = 16;
    int64_t v_vec[size];
    
    for (int i = 0; i < size; i++) {
        v_vec[i] = v;
    }

    for (int iter = p; iter > 0; iter--) {
        for (int i = 0; i < size; i += 2) // Strided access: step by 2
        {
            v_vec[i] *= a;
            v_vec[i] /= (1 << 16);
        }
    }

    v = v_vec[0]; // update scalar result
}
