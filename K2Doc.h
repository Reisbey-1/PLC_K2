
// K2Doc.h : interface of the CK2Doc class
//


#pragma once


class CK2Doc : public COleDocument
{
protected: // create from serialization only
	CK2Doc();
	DECLARE_DYNCREATE(CK2Doc)

// Attributes
public:

// Operations
public:
	CString m_csTest;
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CK2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	static ICodeFabricPtr  CK2Doc::CreateCodeFabric();
	static ICodeFabricPtr m_sCodeFabricPtr;
protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
