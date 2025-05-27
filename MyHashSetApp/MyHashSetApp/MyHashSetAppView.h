
// MyHashSetAppView.h: интерфейс класса CMyHashSetAppView
//

#pragma once


class CMyHashSetAppView : public CView
{
protected: // создать только из сериализации
	CMyHashSetAppView() noexcept;
	DECLARE_DYNCREATE(CMyHashSetAppView)

// Атрибуты
public:
	CMyHashSetAppDoc* GetDocument() const;

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
	virtual ~CMyHashSetAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MyHashSetAppView.cpp
inline CMyHashSetAppDoc* CMyHashSetAppView::GetDocument() const
   { return reinterpret_cast<CMyHashSetAppDoc*>(m_pDocument); }
#endif

