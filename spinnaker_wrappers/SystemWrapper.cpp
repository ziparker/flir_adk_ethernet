/******************************************************************************/
/*                                                                            */
/*  Copyright (C) 2018, FLIR Systems                                          */
/*  All rights reserved.                                                      */
/*                                                                            */
/******************************************************************************/
#include "SystemWrapper.h"

using namespace flir_adk_ethernet;

SystemWrapper::SystemWrapper(Spinnaker::SystemPtr sys) : _sys(sys) {}

SystemWrapper::~SystemWrapper() {}

CameraListWrapper SystemWrapper::GetCameras() {
    Spinnaker::CameraList lst = _sys->GetCameras();
    CameraListWrapper camList(lst);
    return camList;
}

void SystemWrapper::ReleaseInstance() {
    _sys->ReleaseInstance();
}
