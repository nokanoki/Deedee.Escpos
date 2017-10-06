#pragma once
#include <vector>
#include <Windows.h>

class EscposDocument
{
private:
	std::vector<unsigned char> buffer;
	UINT codePage;
public:
	EscposDocument();
	~EscposDocument();
	void Write(const wchar_t* str);

	size_t GetBufferSize() const;
	const unsigned char* GetBufferPointer() const;

};