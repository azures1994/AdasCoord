#include <stdexcept>
#include <cmath>

#include "AdasCoord.h"

AdasCoord::AdasCoord(const CalibParam& calibParam_){
    this->_calibParam = calibParam_;

    int ret = ADASCOORD_FLAG_SUCCESSFUL;

    ret = this->init();
    if(ret != ADASCOORD_FLAG_SUCCESSFUL) throw std::runtime_error("AdasCoord init failed!\n");
}

AdasCoord::~AdasCoord(){
}

int AdasCoord::init(){

    float cx = this->_calibParam._imgWidth / 2.0f;
    float cy = this->_calibParam._imgHeight / 2.0f;

    //! _cameraTheta
    this->_cameraTheta = atan((cy - this->_calibParam._vanishingY) / this->_calibParam._cameraFocalLen);

    //!  _vecPhi
    this->_vecPhi.resize(this->_calibParam._imgHeight);
    for(int i = 0; i < this->_calibParam._imgHeight; i++){
        float alpha = atan((i - cy) / this->_calibParam._cameraFocalLen);
        this->_vecPhi[i] = this->_cameraTheta + alpha;
    }

    //! _vecGroundY
    this->_vecGroundY.resize(this->_calibParam._imgHeight);
    for(int i = 0; i < this->_calibParam._imgHeight; i++){
        if(this->_vecPhi[i] <= 0){
            this->_vecGroundY[i] = -1;
            continue;
        }

        this->_vecGroundY[i] = this->_calibParam._cameraHeight / (tan(this->_vecPhi[i]));
    }

    //! _vecWidthReal
    this->_vecWidthReal.resize(this->_calibParam._imgHeight);
    for(int i = 0; i < this->_calibParam._imgHeight; i++){
        if(this->_vecGroundY[i] == -1){
            this->_vecWidthReal[i] = -1;
            continue;
        }

        float Zc = this->_vecGroundY[i] * cos(this->_cameraTheta) + this->_calibParam._cameraHeight * sin(this->_cameraTheta);

        this->_vecWidthReal[i] = Zc / this->_calibParam._cameraFocalLen;
    }

    return ADASCOORD_FLAG_SUCCESSFUL;
}