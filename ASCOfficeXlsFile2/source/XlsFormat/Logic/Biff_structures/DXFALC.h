#pragma once

#include "BiffStructure.h"

namespace XLS
{;

class CFRecord;

class DXFALC : public BiffStructure
{
	BASE_OBJECT_DEFINE_CLASS_NAME(DXFALC)
public:
	BiffStructurePtr clone();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	//virtual void getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

private:
	unsigned char alc;
	bool fWrap;
	unsigned char alcv;
	bool fJustLast;
	unsigned char trot;
	unsigned char cIndent;
	bool fShrinkToFit;
	bool fMergeCell;
	unsigned char iReadingOrder;

	unsigned int iIndent;
};

} // namespace XLS
