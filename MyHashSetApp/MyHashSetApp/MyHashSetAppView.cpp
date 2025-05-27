
// MyHashSetAppView.cpp: реализация класса CMyHashSetAppView
//
#include "pch.h"
#include "framework.h"

#include "HashSet.h"
#include "Logger.h"
#include "StringUtils.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MyHashSetApp.h"
#endif

#include "MyHashSetAppDoc.h"
#include "MyHashSetAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyHashSetAppView

IMPLEMENT_DYNCREATE(CMyHashSetAppView, CView)

BEGIN_MESSAGE_MAP(CMyHashSetAppView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CMyHashSetAppView

CMyHashSetAppView::CMyHashSetAppView() noexcept
{
	// TODO: добавьте код создания

}

CMyHashSetAppView::~CMyHashSetAppView()
{
}

BOOL CMyHashSetAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMyHashSetAppView

void CMyHashSetAppView::OnDraw(CDC* pDC)
{
    CMyHashSetAppDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    if (!Logger::init("log.txt")) {
        pDC->TextOutW(10, 10, L"Ошибка: не удалось открыть лог-файл");
        return;
    }

    Logger::log("Начало обработки слов", LogLevel::INFO);

    HashSet wordsSet;

    std::ifstream file("E:\\Task4\\words.txt");
    if (!file.is_open()) {
        Logger::log("Не удалось открыть файл words.txt", LogLevel::ERR);
        pDC->TextOutW(10, 10, L"Ошибка: не удалось открыть words.txt");
        Logger::close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            wordsSet.add(line);
        }
    }
    file.close();
    Logger::log("Файл words.txt успешно загружен", LogLevel::INFO);

    std::vector<std::string> shortWords;
    std::vector<std::string> palindromes;

    for (const auto& word : wordsSet) {
        if (shorterThanFive(word)) shortWords.push_back(word);
        if (isPalindrome(word)) palindromes.push_back(word);
    }

    std::sort(shortWords.begin(), shortWords.end());
    std::sort(palindromes.begin(), palindromes.end());

    Logger::log("Формирование списков завершено", LogLevel::INFO);

    int y = 10;
    pDC->TextOutW(10, y, L"Слова < 5 символов:");
    y += 20;
    for (const auto& w : shortWords) {
        CString cw(w.c_str());
        pDC->TextOutW(10, y, cw);
        y += 20;
    }

    y += 20;
    pDC->TextOutW(10, y, L"Палиндромы:");
    y += 20;
    for (const auto& w : palindromes) {
        CString cw(w.c_str());
        pDC->TextOutW(10, y, cw);
        y += 20;
    }

    Logger::log("Вывод завершён", LogLevel::INFO);
    Logger::close();
}



// Печать CMyHashSetAppView

BOOL CMyHashSetAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMyHashSetAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMyHashSetAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CMyHashSetAppView

#ifdef _DEBUG
void CMyHashSetAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMyHashSetAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyHashSetAppDoc* CMyHashSetAppView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyHashSetAppDoc)));
	return (CMyHashSetAppDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMyHashSetAppView
