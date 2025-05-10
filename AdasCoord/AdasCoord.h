#pragma once

#define ADASCOORD_FLAG_SUCCESSFUL               (0)     // 运行成功
#define ADASCOORD_FLAG_BAD_PARAMETER			(-1)    // 参数错误
#define ADASCOORD_FLAG_NULL_POINTER			    (-2)    // 空指针
#define ADASCOORD_FLAG_UNINITIALIZED			(-3)    // 未初始化
#define ADASCOORD_FLAG_BUSY					    (-4)    // 线程忙碌
#define ADASCOORD_FLAG_COND_NOT_MET             (-5)    // 条件不满足
#define ADASCOORD_FLAG_EXCEPTION				(-6)    // 意外发生
#define ADASCOORD_FLAG_FETAL					(-7)    // 致命错误
#define ADASCOORD_FLAG_LICENSE_INVALID		    (-16)	// 无效授权
#define ADASCOORD_FLAG_OUT_OF_RANGE			    (-17)   // 超出范围
#define ADASCOORD_FLAG_OUT_OF_ACTION			(-18)   // 行动停止

#include <vector>

class AdasCoord{
public:
    struct CalibParam{
        float _imgWidth;
        float _imgHeight;
        float _cameraHeight;
        float _cameraFocalLen;
        float _vanishingX;
        float _vanishingY;
    };

public:
    AdasCoord(const CalibParam& calibParam_);
    ~AdasCoord();

private:
    int init();

private:
    CalibParam _calibParam;

    float _cameraTheta;
    std::vector<float> _vecPhi;
    std::vector<float> _vecGroundY;
    std::vector<float> _vecWidthReal;

}; // class AdasCoord