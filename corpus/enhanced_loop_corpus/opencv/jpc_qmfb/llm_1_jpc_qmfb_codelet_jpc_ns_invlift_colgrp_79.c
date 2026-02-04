#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i1 = 0; i1 < 4; ++i1) {
        for (int i2 = 0; i2 < 4; ++i2) {
            for (int i3 = 0; i3 < 1; ++i3) {
                int idx = i1 * 4 + i2;
                if (idx >= 16) continue;
                hptr2[0] = hptr2[0] + (
                    -(jpc_fix_t)(
                        ((jpc_fix_big_t)(
                            (jpc_fix_t)(
                                (2. * (-1.5861343420599241)) * ((double)((jpc_fix_t)(1) << 13))
                            )
                        ) * (jpc_fix_big_t)(lptr2[0])
                    ) >> 13)
                );
                ++hptr2;
                ++lptr2;
            }
        }
    }
}
