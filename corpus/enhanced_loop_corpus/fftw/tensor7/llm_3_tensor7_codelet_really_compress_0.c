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
    for (i = rnk = 0; i < sz->rnk; ++i) {
        INT stride = i * sizeof(iodim); // Simulate strided access via byte offset (though logically same index, access pattern is now strided in memory)
        iodim* dim = (iodim*)((char*)sz->dims + stride);
        if (dim->n != 1)
            ++rnk;
    }
}
