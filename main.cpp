#include <iostream>

#include "AdasCoord/AdasCoord.h"

int test_AdasCoord(){

    AdasCoord::CalibParam calibParam;
    calibParam._imgWidth = 1280;
    calibParam._imgHeight = 720;
    calibParam._cameraHeight = 1700; //mm
    calibParam._cameraFocalLen = 1600; //pixel
    calibParam._vanishingX = 632;
    calibParam._vanishingY = 412;

    AdasCoord adasCoord(calibParam);

    return 0;
}

int main(int, char**){
    std::cout << "Hello, from AdasCoord!\n";

    test_AdasCoord();

    return 0;
}
