#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

extern ChannelMoments *channel_moments;
extern double M02[129];
extern double M03[129];
extern double M11[129];
extern double M12[129];
extern double M20[129];
extern double M21[129];
extern double M30[129];
extern ssize_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c <= 32; c++) {
    ssize_t idx1 = c;
    ssize_t idx2 = c + 33;  // Split iteration space into two segments in one pass

    // First half: c from 0 to 32 → process index c
    channel_moments[idx1].invariant[0] = M20[idx1] + M02[idx1];
    channel_moments[idx1].invariant[1] = (M20[idx1] - M02[idx1]) * (M20[idx1] - M02[idx1]) + 4. * M11[idx1] * M11[idx1];
    channel_moments[idx1].invariant[2] = (M30[idx1] - 3. * M12[idx1]) * (M30[idx1] - 3. * M12[idx1]) + (3. * M21[idx1] - M03[idx1]) * (3. * M21[idx1] - M03[idx1]);
    channel_moments[idx1].invariant[3] = (M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) + (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1]);
    channel_moments[idx1].invariant[4] = (M30[idx1] - 3. * M12[idx1]) * (M30[idx1] + M12[idx1]) * ((M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - 3. * (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1])) + (3. * M21[idx1] - M03[idx1]) * (M21[idx1] + M03[idx1]) * (3. * (M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1]));
    channel_moments[idx1].invariant[5] = (M20[idx1] - M02[idx1]) * ((M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1])) + 4. * M11[idx1] * (M30[idx1] + M12[idx1]) * (M21[idx1] + M03[idx1]);
    channel_moments[idx1].invariant[6] = (3. * M21[idx1] - M03[idx1]) * (M30[idx1] + M12[idx1]) * ((M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - 3. * (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1])) - (M30[idx1] - 3 * M12[idx1]) * (M21[idx1] + M03[idx1]) * (3. * (M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - (M21[idx1] + M03[idx1]) * (M21[idx1] + M03[idx1]));
    channel_moments[idx1].invariant[7] = M11[idx1] * ((M30[idx1] + M12[idx1]) * (M30[idx1] + M12[idx1]) - (M03[idx1] + M21[idx1]) * (M03[idx1] + M21[idx1])) - (M20[idx1] - M02[idx1]) * (M30[idx1] + M12[idx1]) * (M03[idx1] + M21[idx1]);

    if (idx2 <= 64) {  // Second half: c+33 from 33 to 64
        channel_moments[idx2].invariant[0] = M20[idx2] + M02[idx2];
        channel_moments[idx2].invariant[1] = (M20[idx2] - M02[idx2]) * (M20[idx2] - M02[idx2]) + 4. * M11[idx2] * M11[idx2];
        channel_moments[idx2].invariant[2] = (M30[idx2] - 3. * M12[idx2]) * (M30[idx2] - 3. * M12[idx2]) + (3. * M21[idx2] - M03[idx2]) * (3. * M21[idx2] - M03[idx2]);
        channel_moments[idx2].invariant[3] = (M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) + (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2]);
        channel_moments[idx2].invariant[4] = (M30[idx2] - 3. * M12[idx2]) * (M30[idx2] + M12[idx2]) * ((M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - 3. * (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2])) + (3. * M21[idx2] - M03[idx2]) * (M21[idx2] + M03[idx2]) * (3. * (M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2]));
        channel_moments[idx2].invariant[5] = (M20[idx2] - M02[idx2]) * ((M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2])) + 4. * M11[idx2] * (M30[idx2] + M12[idx2]) * (M21[idx2] + M03[idx2]);
        channel_moments[idx2].invariant[6] = (3. * M21[idx2] - M03[idx2]) * (M30[idx2] + M12[idx2]) * ((M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - 3. * (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2])) - (M30[idx2] - 3 * M12[idx2]) * (M21[idx2] + M03[idx2]) * (3. * (M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - (M21[idx2] + M03[idx2]) * (M21[idx2] + M03[idx2]));
        channel_moments[idx2].invariant[7] = M11[idx2] * ((M30[idx2] + M12[idx2]) * (M30[idx2] + M12[idx2]) - (M03[idx2] + M21[idx2]) * (M03[idx2] + M21[idx2])) - (M20[idx2] - M02[idx2]) * (M30[idx2] + M12[idx2]) * (M03[idx2] + M21[idx2]);
    }
}
}
