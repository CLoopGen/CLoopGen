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

extern int rnk;
extern  int *n;
extern  int *niphys;
extern  int *nophys;
extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (rnk > 1) {
        for (i = rnk - 1; i > 0; --i) {
            INT temp_is = x->dims[i].is;
            INT temp_os = x->dims[i].os;
            for (INT factor = 1; factor < niphys[i] + nophys[i]; ++factor) {
                if (factor <= niphys[i]) {
                    x->dims[i - 1].is = temp_is * factor;
                }
                if (factor <= nophys[i]) {
                    x->dims[i - 1].os = temp_os * factor;
                }
            }
            x->dims[i - 1].n = n[i - 1];
        }
    }
}
