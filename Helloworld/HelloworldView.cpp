
// HelloworldView.cpp: реализация класса CHelloworldView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Helloworld.h"
#endif

#include "HelloworldDoc.h"
#include "HelloworldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloworldView

IMPLEMENT_DYNCREATE(CHelloworldView, CView)

BEGIN_MESSAGE_MAP(CHelloworldView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHelloworldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CHelloworldView

CHelloworldView::CHelloworldView() noexcept
{
	// TODO: добавьте код создания

}

CHelloworldView::~CHelloworldView()
{
}

BOOL CHelloworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CHelloworldView

void CHelloworldView::OnDraw(CDC* /*pDC*/)
{
	CRect rect;

	GetClientRect(&rect);
	CDC* pDc = GetDC();

	CFont new_font;

	// Create a font Song format 100 for the word height
	VERIFY(new_font.CreatePointFont(250, _T(" "), pDc));

	// Select the font to enter the PDC
	CFont* default_font = pDc->SelectObject(&new_font);

	// Set the font background to be transparent
	pDc->SetBkMode(TRANSPARENT);

	// Set the font color
	pDc->SetTextColor(RGB(255, 90, 90));

	// Display text, centered display
	pDc->DrawText(CString("Hello world"), rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	// Restore the default font of the PDC
	pDc->SelectObject(default_font);

	// Release the font object
	new_font.DeleteObject();

	// TODO: добавьте здесь код отрисовки для собственных данных

}


// Печать CHelloworldView


void CHelloworldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHelloworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CHelloworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CHelloworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CHelloworldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHelloworldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CHelloworldView

#ifdef _DEBUG
void CHelloworldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloworldDoc* CHelloworldView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloworldDoc)));
	return (CHelloworldDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CHelloworldView
