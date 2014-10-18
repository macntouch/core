#pragma once

#include "BiffStructure.h"
#include <Logic/Biff_structures/BiffString.h>

namespace XLS
{;

class CFRecord;

class RPHSSub : public BiffStructure
{
	BASE_OBJECT_DEFINE_CLASS_NAME(RPHSSub)
public:
	BiffStructurePtr clone();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	//virtual void getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	const size_t getSize() const;
	const unsigned __int16 getRunsNumber() const;

private:
	unsigned __int16 crun;
	LPWideString st;
};

} // namespace XLS
