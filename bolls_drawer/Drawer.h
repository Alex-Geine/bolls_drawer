#pragma once
#include <afxwin.h>
#include<gdiplus.h>
#include  <math.h>
#include "BollsRow.h"

using namespace Gdiplus;

// Drawer

class Drawer : public CStatic
{
	DECLARE_DYNAMIC(Drawer)
	friend class Controller;
public:
	Drawer();
	virtual ~Drawer();
	ULONG_PTR token;
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	
	BollsRow* br = nullptr;


};
