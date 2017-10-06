#include "..\\Deedee.Escpos\\Deedee.Escpos.h"

#pragma comment(lib, "..\\Debug\\Deedee.Escpos.lib")

int main(int, char)
{
	INT32 res;
	void* doc = 0;
	WCHAR printerName[] = L"POS-80";
	res = DeedeeDocCreate(&doc);
	res = DeedeeDocWrite(doc, L"test\n");
	res = DeedeePrint((LPWSTR)printerName, doc);
	res = DeedeeDocDestroy(doc);
	return 0;
}