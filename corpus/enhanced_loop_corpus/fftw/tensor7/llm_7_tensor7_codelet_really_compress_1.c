#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern  tensor *sz;
extern int i;
extern int rnk;
extern tensor *x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rnk = 0;
    for (i = 0; i < sz->rnk; ++i) {
        INT n_val = sz->dims[i].n;
        if (n_val != 1) {
            iodim current_dim = sz->dims[i];
            x->dims[rnk] = current_dim;
            rnk += 1;
        } else {
            // Introduce a dummy operation to create a WAW-like pattern on `rnk` even when not updating
            rnk += 0;
        }
    }
}
