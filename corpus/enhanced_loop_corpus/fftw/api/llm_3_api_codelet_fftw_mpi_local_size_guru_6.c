#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern int i;
extern dtensor *sz;
extern INT Nafter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — access every second element, simulating a stride pattern
    // This assumes rnk allows meaningful striding (e.g., larger tensors); adjust behavior if needed
    for (i = 1; i < sz->rnk; i += 2) {
        Nafter *= sz->dims[i].n;
        if (i + 1 < sz->rnk)
            Nafter *= sz->dims[i + 1].n;  // Unrolled-like access with stride of 2
    }
}
