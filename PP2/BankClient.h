#pragma once
#include <Windows.h>
#include "SyncPrimitives.h"

class CBank;

class CBankClient
{
public:
	unsigned GetId();

private:
	CBankClient(CBank *bank, unsigned id);
	static unsigned GetSleepDuration(CBankClient *client);
	static unsigned GetBalanceChangeValue();
	static DWORD WINAPI ThreadFunction(LPVOID lpParam);	

	HANDLE m_handle;
	SyncPrimitives *m_syncPrimitives = nullptr;

	friend CBank;

	CBank *m_bank;
	unsigned m_id;
};