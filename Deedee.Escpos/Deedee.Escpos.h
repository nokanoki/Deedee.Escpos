#pragma once
#include <Windows.h>

#if DEEDEEESCPOS_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif 
#define DEEDEEAPI __stdcall





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


// print interface
	INT32 DEEDEEAPI DeedeePrint(const wchar_t* printerName, const void* doc);




#if __cplusplus
}
#endif