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

// print interface
	INT32 DEEDEEAPI DeedeePrint(const wchar_t* printerName, const void* doc);




#if __cplusplus
}
#endif