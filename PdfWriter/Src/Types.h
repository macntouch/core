﻿#ifndef _PDF_WRITER_SRC_TYPES_H
#define _PDF_WRITER_SRC_TYPES_H

#include "Consts.h"
#include "../../DesktopEditor/common/Types.h"
#include <string>

namespace PdfWriter
{
	enum EEncryptMode
	{
		encryptmode_R2 = 2,
		encryptmode_R3 = 3
	};
	struct TRect
	{
		TRect()
		{
			fLeft   = 0.0;
			fBottom = 0.0;
			fRight  = 0.0;
			fTop    = 0.0;
		}
		TRect(double dL, double dT, double dR, double dB)
		{
			fLeft   = dL;
			fBottom = dB;
			fRight  = dR;
			fTop    = dT;
		}

		double fLeft;
		double fBottom;
		double fRight;
		double fTop;
	};
	typedef TRect TBox;
	class CMatrix	
	{
	public:

		CMatrix()
		{
			m11 = 1;
			m12 = 0;
			m21 = 0;
			m22 = 1;
			x   = 0;
			y   = 0;
		}

		void Reset()
		{
			m11 = 1;
			m12 = 0;
			m21 = 0;
			m22 = 1;
			x   = 0;
			y   = 0;
		}

		void Apply(double& dX, double& dY)
		{
			double _x = dX;
			double _y = dY;

			dX = _x * m11 + _y * m21 + x;
			dY = _x * m12 + _y * m22 + y;
		}
		bool operator==(const CMatrix& oMatrix)
		{
			if (abs(oMatrix.m11 - m11) > 0.001
				|| abs(oMatrix.m12 - m12) > 0.001
				|| abs(oMatrix.m21 - m21) > 0.001
				|| abs(oMatrix.m22 - m22) > 0.001
				|| abs(oMatrix.x - x) > 0.001
				|| abs(oMatrix.y - y) > 0.001)
				return false;

			return true;
		}

	public:

		double m11;
		double m12;
		double m21;
		double m22;
		double x;
		double y;
	};
	enum ELineCapStyle
	{
		linecap_Butt             = 0,
		linecap_Round            = 1,
		linecap_ProjectingSquare = 2,

		linecap_Min              = 0,
		linecap_Max              = 2
	};
	enum ELineJoinStyle
	{
		linejoin_Miter = 0,
		linejoin_Round = 1,
		linejoin_Bevel = 2,

		linejoin_Min   = 0,
		linejoin_Max   = 2
	};
	class CDashMode
	{
	public:

		CDashMode()
		{
			m_pPattern  = NULL;
			m_unCount   = 0;
			m_dPhase    = 0;
		}
		~CDashMode()
		{
			if (m_pPattern)
				delete[] m_pPattern;
		}
		void Set(const double* pPattern, unsigned int unCount, double dPhase)
		{
			if (!pPattern || !unCount)
				return;

			if (m_pPattern)
				delete[] m_pPattern;

			m_pPattern = new double[unCount];
			if (!m_pPattern)
				return;

			::memcpy((BYTE*)m_pPattern, (BYTE*)pPattern, unCount * sizeof(double));
			m_unCount = unCount;
			m_dPhase  = dPhase;
		}

	private:
		double*      m_pPattern;
		unsigned int m_unCount;
		double       m_dPhase;
	};
	enum ETextRenderingMode
	{
		textrenderingmode_Fill               = 0,
		textrenderingmode_Stroke             = 1,
		textrenderingmode_FillThenStroke     = 2,
		textrenderingmode_Invisible          = 3,
		textrenderingmode_FillClipping       = 4,
		textrenderingmode_StrokeClipping     = 5,
		textrenderingmode_FillStrokeClipping = 6,
		textrenderingmode_Clipping           = 7,

		textrenderingmode_Min                = 0,
		textrenderingmode_Max                = 7
	};
	enum EColorSpace
	{
		colotspace_DeviceGray = 0,
		colotspace_DeviceRGB  = 1,
		colotspace_DeviceCMYK = 2,
		colotspace_CalGray    = 3,
		colotspace_CalRGB     = 4,
		colotspace_LAB        = 5,
		colotspace_ICCBASED   = 6,
		colotspace_Separation = 7,
		colotspace_DeviceN    = 8,
		colotspace_Indexed    = 9,
		colotspace_Pattern    = 10,

		colotspace_Min        = 0,
		colotspace_Max        = 10
	};
	struct TRgb
	{
		double r;
		double g;
		double b;

	public:
		TRgb()
		{
			r = 0;
			g = 0;
			b = 0;
		}
		TRgb(const TRgb& oColor)
		{
			r = oColor.r;
			g = oColor.g;
			b = oColor.b;
		}
		bool operator ==(const TRgb& oColor)const
		{
			if (r == oColor.r && g == oColor.g && b == oColor.b)
				return true;

			return false;
		}
	};
	struct TColor
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;

	public:
		TColor()
		{
			r = 0;
			g = 0;
			b = 0;
		}
		TColor(const unsigned char& R, const unsigned char& G, const unsigned char& B)
		{
			r = R;
			g = G;
			b = B;
		}
	};
	enum EPageLayout
	{
		pagelayout_Single         = 0,
		pagelayout_OneColumn      = 1,
		pagelayout_TwoColumnLeft  = 2,
		pagelayout_TwoCoulmnRight = 3,

		pagelayout_Min            = 0,
		pagelayout_Max            = 3
	};
	enum EPageMode
	{
		pagemode_UseNone    = 0,
		pagemode_UseOutline = 1,
		pagemode_UseThumbs  = 2,
		pagemode_FullScreen = 3,

		pagemode_Min        = 0,
		pagemode_Max        = 3
	};
	enum EPageNumStyle
	{
		pagenumstyle_Decimal      = 0,
		pagenumstyle_UpperRoman   = 1,
		pagenumstyle_LowerRoman   = 2,
		pagenumstyle_UpperLetters = 3,
		pagenumstyle_LowerLetters = 4,

		pagenumstyle_Min          = 0,
		pagenumstyle_Max          = 4
	};
	class CPoint
	{
	public:

		CPoint()
		{
			x = 0;
			y = 0;
		}
		void Set(double dX, double dY)
		{
			x = dX;
			y = dY;
		}
		void Reset()
		{
			x = 0;
			y = 0;
		}
		CPoint& operator=(const CPoint& oPoint)
		{
			x = oPoint.x;
			y = oPoint.y;
			return *this;
		}

	public:

		double x;
		double y;
	};
	enum EGrMode
	{
		grmode_PAGE  = 0x01,
		grmode_PATH  = 0x02,
		grmode_TEXT  = 0x03,
		grmode_CLIP  = 0x04,
		grmode_SHADE = 0x05,
		grmode_IMAGE = 0x06,
		grmode_XOBJ  = 0x08
	};
	enum EBlendMode
	{
		blendmode_Normal     = 0,
		blendmode_Multiply   = 1,
		blendmode_Screen     = 2,
		blendmode_Overlay    = 3,
		blendmode_Darken     = 4,
		blendmode_Lighten    = 5,
		blendmode_ColorDodge = 6,
		blendmode_ColorBum   = 7,
		blendmode_HardLight  = 8,
		blendmode_SoftLight  = 9,
		blendmode_Difference = 10,
		blendmode_Exclusion  = 11,

		blendmode_Min        = 0,
		blendmode_Max        = 11,
		blendmode_Unknown    = 12
	};
	enum EStandard14Fonts
	{
		standard14fonts_Helvetica            = 0,
		standard14fonts_HelveticaBold        = 1,
		standard14fonts_HelveticaOblique     = 2,
		standard14fonts_HelveticeBoldOblique = 3,
		standard14fonts_Courier              = 4,
		standard14fonts_CourierBold          = 5,
		standard14fonts_CourierOblique       = 6,
		standard14fonts_CourierBoldOblique   = 7,
		standard14fonts_Times                = 8,
		standard14fonts_TimesBold            = 9,
		standard14fonts_TimesOblique         = 10,
		standard14fonts_TimesBoldOblique     = 11,
		standard14fonts_Symbol               = 12,
		standard14fonts_ZapfDingbats         = 13,

		standard14fonts_Min                  = 0,
		standard14fonts_Max                  = 13
	};
	enum EImageTilePatternType
	{
		imagetilepatterntype_Default   = 0,
		imagetilepatterntype_InverseX  = 1,
		imagetilepatterntype_InverseY  = 2,
		imagetilepatterntype_InverseXY = 3
	};
	enum EFontType
	{
		fontUnknownType,
		//----- Gr8BitFont
		fontType1,
		fontType1C,
		fontType1COT,
		fontType3,
		fontTrueType,
		fontTrueTypeOT,
		//----- GrCIDFont
		fontCIDType0,
		fontCIDType0C,
		fontCIDType0COT,
		fontCIDType2,
		fontCIDType2OT
	};
}

#endif // _PDF_WRITER_SRC_TYPES_H