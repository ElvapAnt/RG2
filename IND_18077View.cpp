
// IND_18077View.cpp : implementation of the CIND18077View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IND_18077.h"
#endif

#include "IND_18077Doc.h"
#include "IND_18077View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIND18077View

IMPLEMENT_DYNCREATE(CIND18077View, CView)

BEGIN_MESSAGE_MAP(CIND18077View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CIND18077View construction/destruction

CIND18077View::CIND18077View() noexcept
{
	mf_cactus_light = ::GetEnhMetaFile(_T("cactus_part_light.emf"));
	mf_cactus = ::GetEnhMetaFile(_T("cactus_part.emf"));
}

CIND18077View::~CIND18077View()
{
	if (mf_cactus!=NULL) {
		DeleteEnhMetaFile(mf_cactus);
	}
	if (mf_cactus_light!=NULL) {
		DeleteEnhMetaFile(mf_cactus_light);
	}
}

BOOL CIND18077View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIND18077View drawing

void CIND18077View::OnDraw(CDC* pDC)
{
	CIND18077Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush blueBrush(RGB(135, 206, 235));
	CRect rect(0, 0, 500, 500);
	CBrush* oldBrush = pDC->SelectObject(&blueBrush);
	pDC->Rectangle(&rect);
	pDC->SelectObject(oldBrush);

	DrawFigure(pDC);
	// TODO: add draw code for native data here
}


// CIND18077View printing

BOOL CIND18077View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIND18077View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIND18077View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIND18077View diagnostics

#ifdef _DEBUG
void CIND18077View::AssertValid() const
{
	CView::AssertValid();
}

void CIND18077View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


void CIND18077View::DrawFigure(CDC* pDC)
{
	pDC->SetGraphicsMode(GM_ADVANCED);
	
	int savedDC = pDC->SaveDC();
	Translate(pDC, 152, 142, true);
	Rotate(pDC, 0, true);
	Scale(pDC, 0.75, 0.85, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 190-22, 295-73, true);
	Rotate(pDC, 0, true);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 310 - 22, 295 - 73, true);
	Rotate(pDC, 0, true);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 190, 295-25, true);
	Rotate(pDC, 90, false);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 310-2, 295+25, true);
	Rotate(pDC, 270, false);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 380-20, 295+15, true);
	Rotate(pDC, 315, false);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	savedDC = pDC->SaveDC();
	Translate(pDC, 380+15, 295+20, true);
	Rotate(pDC, 225, false);
	Scale(pDC, 0.45, 0.75, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);



	savedDC = pDC->SaveDC();
	Translate(pDC, 250+12, 350+5, true);
	Rotate(pDC, 180, false);
	Scale(pDC, 0.25, 0.85, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);
	savedDC = pDC->SaveDC();
	Translate(pDC, 250+8, 350+12, true);
	Rotate(pDC, 225, false);
	Scale(pDC, 0.25, 0.85, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);
	savedDC = pDC->SaveDC();
	Translate(pDC, 250+8, 350-5, true);
	Rotate(pDC, 135, false);
	Scale(pDC, 0.25, 0.85, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	//na ovaj se rotira ceo kaktus :
	savedDC = pDC->SaveDC();
	Translate(pDC, 250-38, 425-80, true);
	Rotate(pDC, 0, true);
	Scale(pDC, 0.75, 0.85, false);
	pDC->PlayMetaFile(mf_cactus, CRect(0, 0, 100, 100));
	pDC->RestoreDC(savedDC);

	CBrush potBrush(RGB(222, 148, 0));
	CPen outlinePen(PS_SOLID, 1, RGB(0, 0, 0));
	int savedState = pDC->SaveDC();

	CBrush greenBrush(RGB(0, 204, 0));

	pDC->SelectObject(&greenBrush);
	pDC->Ellipse(250 - 10, 425 - 10, 250 + 10, 425 + 10);
	pDC->Ellipse(250 - 10, 350 - 10, 250 + 10, 350 + 10);
	pDC->Ellipse(310 - 10, 295 - 10, 310 + 10, 295 + 10);
	pDC->Ellipse(190 - 10, 295 - 10, 190 + 10, 295 + 10);
	pDC->Ellipse(380 - 10, 295 - 10, 380 + 10, 295 + 10);
	pDC->Ellipse(190 - 10, 225 - 10, 190 + 10, 225 + 10);

	CPoint trapezoid[4] = { {200,450},{300,450},{290,490},{210,490} };
	pDC->SelectObject(&potBrush);
	pDC->SelectObject(&outlinePen);
	pDC->Polygon(trapezoid, 4);
	CRect rect(190, 430, 310, 450);
	pDC->Rectangle(&rect);

	pDC->RestoreDC(savedState);


}

void CIND18077View::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xForm = { 1, 0, 0, 1, dX, dY };
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND18077View::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xForm = { sX, 0, 0, sY, 0, 0 };
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND18077View::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	float rad = angle * 3.14159265f / 180.0f;
	XFORM xForm = { cos(rad), sin(rad), -sin(rad), cos(rad), 0, 0};
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}


CIND18077Doc* CIND18077View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIND18077Doc)));
	return (CIND18077Doc*)m_pDocument;
}
#endif //_DEBUG


// CIND18077View message handlers
