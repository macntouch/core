
#include "FileMoniker.h"
#include <Binary/CFRecord.h>
#include <utils.h>

namespace OSHARED
{


FileMoniker::FileMoniker()
{
}


FileMoniker::FileMoniker(XLS::CFRecord& record)
{
	load(record);
}


XLS::BiffStructurePtr FileMoniker::clone()
{
	return XLS::BiffStructurePtr(new FileMoniker(*this));
}


void FileMoniker::store(XLS::CFRecord& record)
{
#pragma message("####################### FileMoniker record has no BiffStructure::store() implemented")
	Log::error(" Error!!! FileMoniker record has no BiffStructure::store() implemented.");
	//record << something;
}


void FileMoniker::load(XLS::CFRecord& record)
{
	unsigned int ansiLength;
	record >> cAnti >> ansiLength >> ansiPath >> endServer >> versionNumber;
	record.skipNunBytes(20); // reserved
	record >> cbUnicodePathSize;
	if(cbUnicodePathSize)
	{
		unsigned int cbUnicodePathBytes;
		record >> cbUnicodePathBytes >> usKeyValue;

#if defined(_WIN32) || defined(_WIN64)
        unicodePath = std::wstring(record.getCurData<wchar_t>(), cbUnicodePathBytes / 2);
#else
        unicodePath = convertUtf16ToWString(record.getCurData<UTF16>(), cbUnicodePathBytes / 2);
#endif
		record.skipNunBytes(cbUnicodePathBytes);
	}
}


} // namespace OSHARED

