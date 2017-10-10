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
	EXPORT INT32 DEEDEEAPI DeedeeDocCreate(void **doc);
	EXPORT INT32 DEEDEEAPI DeedeeDocDestroy(void *doc);
	EXPORT INT32 DEEDEEAPI DeedeeDocWrite(void *doc, const wchar_t* str);
	EXPORT INT32 DEEDEEAPI DeedeeDocFeedLines(void *doc, int lines);
	EXPORT INT32 DEEDEEAPI DeedeeDocFeed(void *doc);
	EXPORT INT32 DEEDEEAPI DeedeeDocCut(void *doc, int fullcut);
	EXPORT INT32 DEEDEEAPI DeedeeDocReverseFeed(void *doc,  int lines);
	//codePage: see printer selfprint for reference
	EXPORT INT32 DEEDEEAPI DeedeeDocSetPrinterCodePage(void *doc, int codePage);
	EXPORT INT32 DEEDEEAPI DeedeeDocSetCodePage(void *doc, int codePage);
	/*
		0 for left
		1 for center
		2 for right
	*/


	EXPORT INT32 DEEDEEAPI DeedeeDocSetJustificationMode(void *doc, int mode);
	/*
		0 for none
		1 for 1dot
		2 for 2dot
	*/
	EXPORT INT32 DEEDEEAPI DeedeeDocSetUnderlineMode(void *doc, int mode);
	EXPORT INT32 DEEDEEAPI DeedeeDocSetEmphasized(void *doc, int enable);
	//see selfprint for reference
	EXPORT INT32 DEEDEEAPI DeedeeDocSetFont(void *doc, int font);
	//reset to default
	EXPORT INT32 DEEDEEAPI DeedeeDocReset(void *doc);
	EXPORT INT32 DEEDEEAPI DeedeeDocSetDoubleStrike(void *doc, int enable);
	/*
		font [0 => font A, 1 => font B]
	*/
	EXPORT INT32 DEEDEEAPI DeedeeDocPrintMode(void* doc,int font, int bold, int doubleHeight, int doubleWidth);
	EXPORT INT32 DEEDEEAPI DeedeeDocWriteBarcode(void* doc, int barcodeEncoding, const wchar_t* str);
	//Standar esc/pos command
	EXPORT INT32 DEEDEEAPI DeedeeDocWriteQR(void* doc, int model, int correction, const wchar_t* str);
	/*
		work on some OEM printers,
		magnification => zoom in dots
		correction => correction level 1 to ???? its works with 3

	*/
	EXPORT INT32 DEEDEEAPI DeedeeDocWriteQR1(void* doc, int magnification, int correction, const wchar_t* str);
	EXPORT INT32 DEEDEEAPI DeedeeDocSetLeftMargin(void* doc, int val);
	EXPORT INT32 DEEDEEAPI DeedeeDocSetPrintableAreaWidth(void* doc, int va);
	
	// tableformmater interface
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterCreate(void** table);
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterDestroy(void* table);
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterDefineColumn(void* table, int size);
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterAddColumnContent(void* table,int idx, int justification, const wchar_t* str);
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterAddRow(void* table);
	EXPORT INT32 DEEDEEAPI DeedeeTableFormatterGetBuffer(void* table, const wchar_t** buffer, size_t* size);

	// print interface
	EXPORT INT32 DEEDEEAPI DeedeePrint(const wchar_t* printerName, const void* doc);




#if __cplusplus
}
#endif

