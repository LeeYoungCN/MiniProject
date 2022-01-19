#ifndef CAN_FRAME_TRANS_H
#define CAN_FRAME_TRANS_H
#include "vos_typedef.h"
#include <iostream>

struct CanFrameSt {
    VOS_UINT32 protType;// 协议类型
    VOS_UINT32 dstAddr;// 目的地址
    VOS_UINT32 srcAddr;// 源地址
    VOS_UINT32 Qr_Flag;// QR标志位
    VOS_UINT32 CmdCode;// 命令字高位
};

struct DataRange {
    VOS_UINT32 start;
    VOS_UINT32 end;
};

class CanFrameTrans {
public:
    CanFrameTrans();
    ~CanFrameTrans();
    VOS_VOID TransFrame(int argc, char *argv[]);
private:
    VOS_VOID   InitStr(int argc, char *argv[]);
    VOS_VOID   GetFrameSt(CanFrameSt &canFrameSt, std::string &str);
    VOS_VOID   PrintCanFrameSt(CanFrameSt camFrameSt);
    VOS_UINT32 String2U32(std::string &str, DataRange range);
    VOS_VOID GetSendBinStr();
    VOS_VOID PrintCanFrame(std::string str);

    std::string recvBinStr = "";
    std::string sendBinStr = std::string(32, '0');
    CanFrameSt recvFrameSt = {0};
    CanFrameSt sendFrameSt = {0};
};

#endif // CAN_FRAME_TRANS_H