#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include "utility.h"



////����
//class GpuInterface
//{
//public:
//	virtual int GetGpuUsage(){	return -1;	};
//	virtual int GetGpuTemp(){	return -1;	};
//};


//��ȡ�Կ������ʺ��¶���Ϣ����
class GpuWatch
{
public:
	GpuWatch(void);
	~GpuWatch(void);
	//��ʼ���Կ�
	static bool InitGpuInterface(void);
	static int GetGpuUsage();	//��ȡGPU������
	static int GetGpuTemp();	//��ȡGPU�¶�
	static void GetGpuInformation(char *buf,int size);	//��ȡGPU������Ϣ
	static int gpuUtilization , gpuTemp , graNum;	//gpu�����ʺ��¶�,�Կ���Ŀ
	/*static GpuInterface* pInterface;*/
	static std::string graInfo;	//�Կ���Ϣ
	static void ChangeToLower(std::string &str);
	static int type;

private:
	bool isInit;	//�Կ��Ƿ��Ѿ���ʼ��
};


//AMD�Կ���ص���,�̳�GpuInterface��
class AMDInterface/*: public GpuInterface*/
{
public:
	AMDInterface(void);	//���캯��
	~AMDInterface();
	static void* _stdcall ADLMainMemoryAlloc(int size);	//����ռ�
	static void _stdcall ADLMainMemoryFree(void **buf);	//�ͷſռ�

	int GetGpuUsage();	//��ȡGPU����
	int GetGpuTemp();	//��ȡGPU�¶�

	//���庯��ָ��
	static ADL_MAIN_CONTROL_CREATE  AdlMainControlCreate;
	static ADL_MAIN_CONTROL_REFRESH AdlMainControlRefresh;
	static ADL_OVERDRIVE5_TEMPERATURE_GET AdlOverDrive5TemperatureGet;
	static ADL_OVERDRIVE5_CURRENTACTIVITY_GET AdlOverDrive5CurrentActivityGet;

private:
	bool InitAdlApi();	//��ʼ��API
	bool isInit;	//�Ƿ��Ѿ���ʼ��
};

//Nvidia�Կ���ص��࣬�̳�GpuInterface��
class NvidiaInterface/*: public GpuInterface*/
{
public:
	NvidiaInterface(void);	//���캯��
	~NvidiaInterface();
	int GetGpuUsage();	//��ȡGPU������
	int GetGpuTemp();	//��ȡGPU�¶�

private:
	bool InitNvApi();	//��ʼ��N��
	bool isInit;
	NvPhysicalGpuHandle phys;
};

#endif
