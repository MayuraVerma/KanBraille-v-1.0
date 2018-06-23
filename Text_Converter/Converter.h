// Convert.h : header file
//
#if !defined(AFX_EMF2BMP_H__12044F2C_BFFB_411B_BED2_586BD35C67B1__INCLUDED_)
#define AFX_EMF2BMP_H__12044F2C_BFFB_411B_BED2_586BD35C67B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Text_Converter 
{
		char fchr;
	    int  found;
		int  i,j;
		int  bRet;
public:
		int Srg_To_Kuvempu(const char*pszSRCFile,const char* pszDSTFile);
		int SreeLipi_To_Kuvempu(const char*pszSRCFile,const char* pszDSTFile);
		int Surabhi_To_Kuvempu(const char*pszSRCFile,const char* pszDSTFile);
		int Akruthi_To_Kuvempu(const char*pszSRCFile,const char* pszDSTFile);
};
#endif 
