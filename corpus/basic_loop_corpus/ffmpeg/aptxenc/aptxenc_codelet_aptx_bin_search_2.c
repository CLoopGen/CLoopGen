#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t value;
extern int32_t factor;
extern  int32_t *intervals;
extern int32_t nb_intervals;
extern int32_t idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = nb_intervals >> 1; i > 0; i >>= 1)
    if (((int64_t)(factor) * (int64_t)(intervals[idx + i])) <= ((int64_t)value << 24))
        idx += i;

}
