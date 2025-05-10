#pragma once

#define ADASCOORD_FLAG_SUCCESSFUL               (0)     // ���гɹ�
#define ADASCOORD_FLAG_BAD_PARAMETER			(-1)    // ��������
#define ADASCOORD_FLAG_NULL_POINTER			    (-2)    // ��ָ��
#define ADASCOORD_FLAG_UNINITIALIZED			(-3)    // δ��ʼ��
#define ADASCOORD_FLAG_BUSY					    (-4)    // �߳�æµ
#define ADASCOORD_FLAG_COND_NOT_MET             (-5)    // ����������
#define ADASCOORD_FLAG_EXCEPTION				(-6)    // ���ⷢ��
#define ADASCOORD_FLAG_FETAL					(-7)    // ��������
#define ADASCOORD_FLAG_LICENSE_INVALID		    (-16)	// ��Ч��Ȩ
#define ADASCOORD_FLAG_OUT_OF_RANGE			    (-17)   // ������Χ
#define ADASCOORD_FLAG_OUT_OF_ACTION			(-18)   // �ж�ֹͣ

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