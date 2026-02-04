#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened version: reduce nesting by removing the inner loop structure entirely,
// but preserve outer iteration logic and pointer update.
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    // Perform width iterations implicitly — no inner loop over j
    srcp += src_linesize;
}
}
