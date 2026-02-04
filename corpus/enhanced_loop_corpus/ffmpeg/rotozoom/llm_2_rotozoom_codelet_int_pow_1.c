#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *v_arr = (int64_t*)aligned_alloc(32, sizeof(int64_t) * 1);
    v_arr[0] = v;

    for (int i = p; i > 0; i--) {
        v_arr[0] *= a;
        v_arr[0] /= (1 << 16);
    }

    v = v_arr[0];
    free(v_arr);
}
