//�۲�CPU��Ϣ����
#pragma once
#include "utility.h"

class CpuWatch{
public:
	CpuWatch(void);
	CpuWatch(char *procName);	//���캯��
	~CpuWatch(void);
	//ʱ��ת������
	static int64_t FileTimeToDouble(FILETIME &t);

	//����CPU���������
	double GetProcessCpuUtilization();	//��ȡ����CPU������
	double GetProcessCpuUtilization(HANDLE process);

	//ϵͳCPU���������
	double GetSysCpuUtilization();	//��ȡϵͳCPU������
	unsigned int GetProcessorNum();	//��ȡCPU����
	int64_t GetCpuFreq();	//��ȡCPUƵ��
	//void GetSysCpuUtilizationLoop(double &result,int sleepTime);	//�����Եػ�ȡϵͳCPU������


	int getCpuUtilization(HANDLE hProcess, double &processCpu, double &systemCpu);

	//���̲������
	HANDLE getProcH(char *procName);	//���ݽ�������ȡ���̺�
	HANDLE GetProcH();	
	void SetProcName(char *input);			//���ý�����

private:
	int64_t last_sys_kernel;
	int64_t last_sys_user;
	int64_t last_sys_idle;
	
	int64_t last_time;
	int64_t last_sys_time;
	unsigned int processor_num;	//CPU����
	char processName[MAXSIZE];	//������

	void init();
};