/******************************************************************************/
/*                                                                            */
/*  Copyright (C) 2018, FLIR Systems                                          */
/*  All rights reserved.                                                      */
/*                                                                            */
/******************************************************************************/
#ifndef CAMERAWRAPPER_H
#define CAMERAWRAPPER_H

#include <spinnaker/Spinnaker.h>
#include <spinnaker/SpinGenApi/SpinnakerGenApi.h>

using namespace std;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;

namespace flir_adk_ethernet {

using Spinnaker::CameraPtr;

class CameraWrapper {
  public:
    CameraWrapper();
    CameraWrapper(CameraPtr cam);
    CameraWrapper(const CameraWrapper& wrapper);
    virtual ~CameraWrapper();
    virtual void Init();
    virtual bool IsInitialized();
    virtual bool IsValid();
    virtual INodeMap& GetNodeMap();
    virtual INodeMap& GetTLDeviceNodeMap();
    virtual void RegisterEvent(Spinnaker::EventHandler &e);
    virtual void UnregisterEvent(Spinnaker::EventHandler &e);
    virtual void BeginAcquisition();
    virtual void EndAcquisition();
    virtual void DeInit();
  private:
    CameraPtr _cam;
};

}

#endif
