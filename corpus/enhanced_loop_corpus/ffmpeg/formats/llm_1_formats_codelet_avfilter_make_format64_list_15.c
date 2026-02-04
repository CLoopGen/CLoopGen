#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten potential nested structure (though original is flat), simulate reduced depth by removing any implied nesting
// Since original loop is already at minimal nesting, ensure no internal loops exist
for (count = 0; fmts[count] != -1; count++)
    ;
}
