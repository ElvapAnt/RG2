
// IND_18077View.h : interface of the CIND18077View class
//

#pragma once


class CIND18077View : public CView
{
protected: // create from serialization only
	CIND18077View() noexcept;
	DECLARE_DYNCREATE(CIND18077View)

// Attributes
public:
	CIND18077Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CIND18077View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HENHMETAFILE mf_cactus;
	HENHMETAFILE mf_cactus_light;

	void DrawCactusPart(CDC* pDC, CPoint center, float scaleWidth, float scaleHeight, float rotation);
	void DrawFigure(CDC* pDC);
	void Translate(CDC* pDC, float dX, float dY, bool rightMultiply);
	void Scale(CDC* pDC, float sX, float sY, bool rightMultiply);
	void Rotate(CDC* pDC, float angle, bool rightMultiply);
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IND_18077View.cpp
inline CIND18077Doc* CIND18077View::GetDocument() const
   { return reinterpret_cast<CIND18077Doc*>(m_pDocument); }
#endif

