#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double white_point;
extern double *histogram;
extern double intensity;
extern ssize_t white;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double local_intensity = 0.0;
    ssize_t i;
    // Remove loop-carried dependency on 'intensity' by using a local accumulator
    // and restructure to count down from 65534 to avoid immediate decrement affecting first access
    for (i = (ssize_t)65534UL; i >= 0; i--) {
        local_intensity += histogram[i + 1];
        // Introduce artificial RAW dependency: use updated local_intensity immediately in computation
        double threshold_check = local_intensity - white_point;
        if (threshold_check >= 0.0) {
            white = i;
            intensity = local_intensity;
            goto exit_loop;
        }
    }
    // Ensure white is set even if loop doesn't break early (full iteration)
    white = 0;
    intensity = local_intensity;
exit_loop:
    return;
}
