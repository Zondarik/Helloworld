
// HelloworldView.h: интерфейс класса CHelloworldView
//

#pragma once


class CHelloworldView : public CView
{
protected: // создать только из сериализации
	CHelloworldView() noexcept;
	DECLARE_DYNCREATE(CHelloworldView)

// Атрибуты
public:
	CHelloworldDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CHelloworldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в HelloworldView.cpp
inline CHelloworldDoc* CHelloworldView::GetDocument() const
   { return reinterpret_cast<CHelloworldDoc*>(m_pDocument); }
#endif

