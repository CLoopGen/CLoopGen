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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rnk = 0;
    for (i = 0; i < sz->rnk; ++i) {
        INT n_val = sz->dims[i].n;
        if (n_val != 1) {
            rnk++;
        }
        sz->dims[i].is = sz->dims[i].os + n_val; // Introduce WAW and RAW: modifies is using os and n
        sz->dims[i].os = sz->dims[i].is - 1;    // WAR dependency on previous line's write to is
    }
}
