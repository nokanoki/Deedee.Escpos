#pragma once
#include <Windows.h>

#if DEEDEEESCPOS_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif 
#define DEEDEEAPI __stdcall

#define DEEDEEDOC_BARCODE_UPC_A 0
#define DEEDEEDOC_BARCODE_UPC_E 1
#define DEEDEEDOC_BARCODE_JAN13 2
#define DEEDEEDOC_BARCODE_JAN8	3
#define DEEDEEDOC_BARCODE_CODE39 4
#define DEEDEEDOC_BARCODE_ITF	5
#define DEEDEEDOC_BARCODE_NW7	6

#define DEEDEEDOC_QR_MODEL_1	49
#define DEEDEEDOC_QR_MODEL_2	50
#define DEEDEEDOC_QR_MICRO		51

#define DEEDEEDOC_QR_CORR_L		48
#define DEEDEEDOC_QR_CORR_M		49
#define DEEDEEDOC_QR_CORR_Q		50
#define DEEDEEDOC_QR_CORR_H		51


#if __cplusplus
extern "C" {
#endif
// doc interface
	INT32 DEEDEEAPI DeedeeDocCreate(void **doc);
	INT32 DEEDEEAPI DeedeeDocDestroy(void *doc);
	INT32 DEEDEEAPI DeedeeDocWrite(void *doc, const wchar_t* str);
	INT32 DEEDEEAPI DeedeeDocFeedLines(void *doc, int lines);
	INT32 DEEDEEAPI DeedeeDocFeed(void *doc);
	INT32 DEEDEEAPI DeedeeDocCut(void *doc, int fullcut);
	INT32 DEEDEEAPI DeedeeDocReverseFeed(void *doc,  int lines);
	//codePage: see printer selfprint for reference
	INT32 DEEDEEAPI DeedeeDocSetPrinterCodePage(void *doc, int codePage);
	INT32 DEEDEEAPI DeedeeDocSetCodePage(void *doc, int codePage);
	/*
		0 for left
		1 for center
		2 for right
	*/


	INT32 DEEDEEAPI DeedeeDocSetJustificationMode(void *doc, int mode);
	/*
		0 for none
		1 for 1dot
		2 for 2dot
	*/
	INT32 DEEDEEAPI DeedeeDocSetUnderlineMode(void *doc, int mode);
	INT32 DEEDEEAPI DeedeeDocSetEmphasized(void *doc, int enable);
	//see selfprint for reference
	INT32 DEEDEEAPI DeedeeDocSetFont(void *doc, int font);
	//reset to default
	INT32 DEEDEEAPI DeedeeDocReset(void *doc);
	INT32 DEEDEEAPI DeedeeDocSetDoubleStrike(void *doc, int enable);
	/*
		font [0 => font A, 1 => font B]
	*/
	INT32 DEEDEEAPI DeedeeDocPrintMode(void* doc,int font, int bold, int doubleHeight, int doubleWidth);
	INT32 DEEDEEAPI DeedeeDocWriteBarcode(void* doc, int barcodeEncoding, const wchar_t* str);
	//Standar esc/pos command
	INT32 DEEDEEAPI DeedeeDocWriteQR(void* doc, int model, int correction, const wchar_t* str);
	/*
		work on some OEM printers,
		magnification => zoom in dots
		correction => correction level 1 to ???? its works with 3

	*/
	INT32 DEEDEEAPI DeedeeDocWriteQR1(void* doc, int magnification, int correction, const wchar_t* str);
// print interface
	INT32 DEEDEEAPI DeedeePrint(const wchar_t* printerName, const void* doc);




#if __cplusplus
}
#endif