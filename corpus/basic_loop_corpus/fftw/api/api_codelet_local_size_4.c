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

extern  dtensor *sz;
extern ptrdiff_t *local_n;
extern ptrdiff_t *local_start;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < sz->rnk; ++i)
    local_n[i] = local_start[i] = 0;

}
