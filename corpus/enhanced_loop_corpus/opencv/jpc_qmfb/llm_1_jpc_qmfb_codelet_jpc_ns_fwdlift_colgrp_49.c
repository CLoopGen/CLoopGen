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
            for (int i3 = 0; i3 < 4; ++i3, ++lptr2, ++hptr2) {
                int idx = i1 * 4 + i2;
                if (idx >= 16) break;
                lptr2[0] = lptr2[0] + (
                    (jpc_fix_t)(
                        (
                            (jpc_fix_big_t)(
                                (jpc_fix_t)(
                                    2. * (0.443506852043971) * ((double)(((jpc_fix_t)(1)) << 13))
                                )
                            ) * (jpc_fix_big_t)(hptr2[0])
                        ) >> 13
                    )
                );
            }
        }
    }
}
