
// CntrItem.h : interface of the CK2CntrItem class
//

#pragma once

class CK2Doc;
class CK2View;

class CK2CntrItem : public COleClientItem
{
	DECLARE_SERIAL(CK2CntrItem)

// Constructors
public:
	CK2CntrItem(CK2Doc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer

// Attributes
public:
	CK2Doc* GetDocument()
		{ return reinterpret_cast<CK2Doc*>(COleClientItem::GetDocument()); }
	CK2View* GetActiveView()
		{ return reinterpret_cast<CK2View*>(COleClientItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);

// Implementation
public:
	~CK2CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

