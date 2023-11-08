
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
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CIND18077View construction/destruction

CIND18077View::CIND18077View() noexcept
{
	m_grid_hit = false;
	m_cactusSmallRotation = 0.0f;
	m_cactusFullRotation = 0.0f;
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

	CPoint rootNodeCenter(250, 425);
	CBrush potBrush(RGB(222, 148, 0));
	CPen outlinePen(PS_SOLID, 1, RGB(0, 0, 0));
	CBrush blueBrush(RGB(135, 206, 235));
	CRect rect(0, 0, 500, 500);
	CBrush* oldBrush = pDC->SelectObject(&blueBrush);
	pDC->Rectangle(&rect);
	pDC->SelectObject(oldBrush);

	int savedDC = pDC->SaveDC();
	pDC->SetGraphicsMode(GM_ADVANCED);
	Translate(pDC, rootNodeCenter.x, rootNodeCenter.y, false);
	Rotate(pDC, m_cactusFullRotation, false);
	Translate(pDC, -rootNodeCenter.x, -rootNodeCenter.y, false);
	DrawFigureBetter(pDC);
	DrawNodes(pDC);
	pDC->RestoreDC(savedDC);

	oldBrush = pDC->SelectObject(&potBrush);
	CPoint trapezoid[4] = { {200,450},{300,450},{290,500},{210,500} };
	pDC->SelectObject(&outlinePen);
	pDC->Polygon(trapezoid, 4);
	CRect pot(190, 430, 310, 450);
	pDC->Rectangle(&pot);
	pDC->SelectObject(oldBrush);


	savedDC = pDC->SaveDC();
	pDC->SetGraphicsMode(GM_ADVANCED);
	Translate(pDC, 475, 25, true);
	Rotate(pDC, 90, false);
	CFont fontText;
	fontText.CreateFont(30, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, 0, 0, 0, 0, 0, _T("Helvetica"));
	CFont* oldF = pDC->SelectObject(&fontText);
	COLORREF crlOld = pDC->SetTextColor(RGB(0, 0, 0));
	int nOldMode = pDC->SetBkMode(TRANSPARENT);
	CString msg = L"18077 Pavle Antonijevic";
	pDC->TextOut(0, 0, msg);
	pDC->SetTextColor(RGB(255, 255, 0));
	pDC->TextOut(-2, -2, msg);
	pDC->SelectObject(&oldF);
	pDC->SetBkMode(nOldMode);
	pDC->RestoreDC(savedDC);

	if (m_grid_hit)
	{
		CPen pen(PS_SOLID, 2, RGB(234, 234, 234));
		pDC->SetBkMode(TRANSPARENT);
		CPen* oldPen = pDC->SelectObject(&pen);

		int gridCellSize = 25;
		int width = 500;
		int height = 500;

		for (int x = 0; x <= width; x += gridCellSize)
		{
			pDC->MoveTo(x, 0);
			pDC->LineTo(x, height);
		}
		for (int y = 0; y <= height; y += gridCellSize)
		{
			pDC->MoveTo(0, y);
			pDC->LineTo(width, y);
		}

		pDC->SelectObject(oldPen);

	}
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


void CIND18077View::DrawFigureBetter(CDC* pDC)
{
	pDC->SetGraphicsMode(GM_ADVANCED);

	DrawCactusPart(pDC, CPoint(190,225), 1, 0, true);
	DrawCactusPart(pDC, CPoint(190, 295), 2, 90, false);
	DrawCactusPart(pDC, CPoint(380, 295), 2, 135, true);
	DrawCactusPart(pDC, CPoint(250, 350), 3, 45, true);
	DrawCactusPart(pDC, CPoint(310, 295), 2, 0, false, true);
	DrawCactusPart(pDC, CPoint(250, 425), 1, 0, true, true);
}

void CIND18077View::DrawCactusPart(CDC* pDC, CPoint nodeCenter, int partCount, float angle, bool start, bool light) //true = right, false = left
{
	float scaleWidth = 0.8f - (partCount * 0.18f);
	float scaleHeight = partCount == 2 ? 0.7 : 0.85;
	float rotAngle = start ? angle : -angle;
	int savedDC;

	if (light && partCount == 1) {
		savedDC = pDC->SaveDC();
		Translate(pDC, nodeCenter.x, nodeCenter.y, false);
		Rotate(pDC, rotAngle, false);
		Scale(pDC, scaleWidth, scaleHeight, false);
		pDC->PlayMetaFile(mf_cactus_light, CRect(-50, -100, 50, 0));
		pDC->RestoreDC(savedDC);
	}
	else {
		for (int i = 0; i < partCount; i++) {
			savedDC = pDC->SaveDC();
			if (light) {
				Translate(pDC, nodeCenter.x, nodeCenter.y, false);
				Rotate(pDC, m_cactusSmallRotation, false);
				Scale(pDC, scaleWidth, scaleHeight, false);
				pDC->PlayMetaFile(mf_cactus_light, CRect(-50, -100, 50, 0));
				light = false;
			}
			else {
				Translate(pDC, nodeCenter.x, nodeCenter.y, false);
				Rotate(pDC, rotAngle, false);
				Scale(pDC, scaleWidth, scaleHeight, false);
				pDC->PlayMetaFile(mf_cactus, CRect(-50, -100, 50, 0));
			}
			pDC->RestoreDC(savedDC);
			if (start) rotAngle -= partCount == 3 ? 45 : 90;
			else rotAngle += partCount == 3 ? 45 : 90;
		}
	}
}

void CIND18077View::DrawNodes(CDC* pDC)
{
	CBrush greenBrush(RGB(0, 204, 0));
	CBrush lightGreenBrush(RGB(0, 255, 0));
	pDC->SelectObject(&lightGreenBrush);
	//root
	pDC->Ellipse(250 - 10, 425 - 10, 250 + 10, 425 + 10);
	pDC->SelectObject(&greenBrush);
	//node1 250,350
	pDC->Ellipse(250 - 10, 350 - 10, 250 + 10, 350 + 10);
	//node2 310,295
	pDC->Ellipse(310 - 10, 295 - 10, 310 + 10, 295 + 10);
	//node3 190,295
	pDC->Ellipse(190 - 10, 295 - 10, 190 + 10, 295 + 10);
	//node4 380,295
	pDC->Ellipse(380 - 10, 295 - 10, 380 + 10, 295 + 10);
	//node5 190,225
	pDC->Ellipse(190 - 10, 225 - 10, 190 + 10, 225 + 10);
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


void CIND18077View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const float rotationIncrement = 5.0f; // Degrees to rotate with each key press
	if (nChar == 'A')
	{
		m_cactusSmallRotation -= rotationIncrement;
	}
	else if (nChar == 'D')
	{
		m_cactusSmallRotation += rotationIncrement;
	}

	if (nChar == VK_LEFT)
	{
		m_cactusFullRotation -= rotationIncrement;
	}
	else if (nChar == VK_RIGHT) {
		m_cactusFullRotation += rotationIncrement;
	}

	if (m_cactusSmallRotation >= 360.0f) {
		m_cactusSmallRotation -= 360.0f;
	}
	else if (m_cactusSmallRotation < 0.0f) {
		m_cactusSmallRotation += 360.0f;
	}

	if (m_cactusFullRotation >= 360.0f) {
		m_cactusFullRotation -= 360.0f;
	}
	else if (m_cactusFullRotation < 0.0f) {
		m_cactusFullRotation += 360.0f;
	}

	if (nChar == VK_SPACE)
	{
		m_grid_hit = !m_grid_hit;
		Invalidate();
	}


	Invalidate();
	UpdateWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
