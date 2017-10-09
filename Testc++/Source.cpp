#include "..\\Deedee.Escpos\\Deedee.Escpos.h"

#pragma comment(lib, "..\\Debug\\Deedee.Escpos.lib")


int main(int, char)
{
	INT32 res;


	void* doc = 0;
	WCHAR printerName[] = L"POS-80";
	res = DeedeeDocCreate(&doc);
	DeedeeDocReset(doc);
	//DeedeeDocSetFont(doc, 2);
	DeedeeDocSetPrinterCodePage(doc, 64);//737
	DeedeeDocSetCodePage(doc, 737);
	
	DeedeeDocWrite(doc, L"test left\n");
	DeedeeDocSetJustificationMode(doc,1);
	DeedeeDocWrite(doc,L"test at center\n");
	DeedeeDocSetJustificationMode(doc,2);
	DeedeeDocWrite(doc, L"test at right\n");
	DeedeeDocSetJustificationMode(doc,0);
	DeedeeDocSetEmphasized(doc, 1);
	DeedeeDocWrite(doc, L"test in bold\n");
	DeedeeDocSetEmphasized(doc, 0);
	DeedeeDocSetUnderlineMode(doc,1);
	DeedeeDocWrite(doc, L"test underline 1dot\n");
	DeedeeDocSetUnderlineMode(doc, 2);
	DeedeeDocWrite(doc, L"test underline 2dot\n");
	DeedeeDocSetUnderlineMode(doc, 0);
	DeedeeDocSetDoubleStrike(doc, 1);
	DeedeeDocWrite(doc, L"test doublestrike\n");
	DeedeeDocSetDoubleStrike(doc, 0);
	DeedeeDocWrite(doc, L"¡Î·ÏÔıÒÌÂÊÈÍ· ¡· ¬‚ √„\n");
	DeedeeDocPrintMode(doc, 0, 1, 1, 1);
	DeedeeDocWrite(doc, L"big BIG\n");
	DeedeeDocPrintMode(doc, 0, 0, 0, 0);
	DeedeeDocWriteBarcode(doc, DEEDEEDOC_BARCODE_CODE39, L"12345678901");
	DeedeeDocFeed(doc);
	//DeedeeDocReset(doc);
	DeedeeDocWrite(doc, L"12345678901\n");
	DeedeeDocCut(doc, 1);





	//res = DeedeeDocFeed(doc);
	res = DeedeeDocCut(doc, 0);
	//res = DeedeeDocWrite(doc, L"test Ÿ—≈≈≈≈ÂÎ·ÎÂ·t");
	//res = DeedeeDocFeedLines(doc, 3);
	//res = DeedeeDocCut(doc, 1);
	res = DeedeePrint((LPWSTR)printerName, doc);
	res = DeedeeDocDestroy(doc);
	return 0;
}