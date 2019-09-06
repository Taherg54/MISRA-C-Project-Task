﻿/*
 * BLMGR.h
 *
 * Created: 28/02/2016 04:20:32 م
 *  Author: hossam
 */ 


#ifndef BLMGR_H_
#define BLMGR_H_

#define SLAVE_COMM 0x00u
#define MSTER_COMM 0x01u
#define COMM_CINFIG (MSTER_COMM)

#define ROLE_CHAIR 0x02u
#define ROLE_CAP  0x03u
#define ROLE_MAPP 0x01u

#define DEVICE_ROLE (ROLE_CHAIR)
void BLMGR_Test(void);
void BLMGR_BluetoothInit(void);
void BLMGR_BluetoothStateMachine(void);
void BLMGR_StartDevice(void);
void BLMGR_SetReceiver(u8 Receiver);
void BLMGR_SetDeviceName(const u8 DeviceName[],u8 DeviceNameLength);
void BLMGR_SetBattLevel(u8 BattLevel);
#endif /* BLMGR_H_ */
