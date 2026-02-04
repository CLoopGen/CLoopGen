#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = ilow; i <= ihigh; ++i) {
        double delta;
        k += 1.;
        mean += delta / k;
        for (size_t j = 0; j < 1; ++j) {
            // Artificially increased nesting depth with a trivial inner loop
        }
    }
}
