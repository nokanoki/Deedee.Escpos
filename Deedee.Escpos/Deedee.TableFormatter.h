#pragma once
#include <vector>
class TableFormatter
{
private:
	std::vector<int> columns;
	std::vector<wchar_t> buffer;
public:
	TableFormatter();
	~TableFormatter();
	void DefineColumns(int size);
	void AddRow();
	void SetColumnContent(int idx, const wchar_t* str, int justification);
	size_t GetBufferSize() const;
	const wchar_t* GetBufferPointer() const;
	
private:
	void AddSpaces(int n);

};

