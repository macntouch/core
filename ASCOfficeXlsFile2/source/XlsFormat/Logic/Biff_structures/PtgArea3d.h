#pragma once

#include "OperandPtg.h"
#include "CellRangeRef.h"
#include "Logic/GlobalWorkbookInfo.h"

namespace XLS
{;

class CFRecord;

class PtgArea3d: public OperandPtg
{
	BASE_OBJECT_DEFINE_CLASS_NAME(PtgArea3d)
public:
	PtgArea3d(const CellRef& cell_base_ref_init);
	PtgArea3d(const unsigned __int16 ixti, const std::wstring& word, const PtgDataType data_type, const CellRef& cell_base_ref_init);
	BiffStructurePtr clone();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void loadFields(CFRecord& record);
	virtual void storeFields(CFRecord& record);

	virtual void assemble(AssemblerStack& ptg_stack, PtgQueue& extra_data, BiffStructurePtr & parent);

	static const unsigned __int16 fixed_id = 0x1B;
private:
	unsigned __int16 ixti;
	RgceAreaRel area_rel;
	RgceArea area;
	const CellRef& cell_base_ref;
	GlobalWorkbookInfoPtr global_info;
};

} // namespace XLS
