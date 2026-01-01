#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_buttonLeftOnButtonClick( wxCommandEvent& event )
{
    if (m_currentPage > 0 && !m_indexPageBitmaps.empty()) {
        m_currentPage--;
        m_indexPageBitmap = m_indexPageBitmaps[m_currentPage];
        m_scrolledWindow1->Refresh();
    }
}

void GUIMyFrame1::m_scrolledWindow1OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(m_scrolledWindow1);

    if (m_indexPageBitmap.IsOk())
    {
        m_scrolledWindow1->DoPrepareDC(dc);
        dc.DrawBitmap(m_indexPageBitmap, 0, 0, false);
        m_indexPageBitmap.SaveFile("preview.bmp", wxBITMAP_TYPE_BMP);
    }
}

void GUIMyFrame1::m_buttonRightOnButtonClick( wxCommandEvent& event )
{
    if (m_currentPage + 1 < (int)m_indexPageBitmaps.size()) {
        m_currentPage++;
        m_indexPageBitmap = m_indexPageBitmaps[m_currentPage];
        m_scrolledWindow1->Refresh();
    }
}

void GUIMyFrame1::m_buttonFolderOnButtonClick( wxCommandEvent& event )
{
    wxDirDialog dlg(this, "Wybierz katalog ze zdjęciami", wxEmptyString, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if (dlg.ShowModal() == wxID_OK) {
        m_selectedFolder = dlg.GetPath();
        RebuildIndexPage();
    }
}

void GUIMyFrame1::m_buttonPrintOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_buttonPrintOnButtonClick
}

void GUIMyFrame1::m_textCtrlWidthOnText( wxCommandEvent& event )
{
// TODO: Implement m_textCtrlWidthOnText
}

void GUIMyFrame1::m_textCtrlHeightOnText( wxCommandEvent& event )
{
// TODO: Implement m_textCtrlHeightOnText
}

void GUIMyFrame1::m_textCtrlRowsOnText( wxCommandEvent& event )
{
// TODO: Implement m_textCtrlRowsOnText
}

void GUIMyFrame1::m_textCtrlCollsOnText( wxCommandEvent& event )
{
// TODO: Implement m_textCtrlCollsOnText
}

void GUIMyFrame1::m_textCtrlCommentOnText( wxCommandEvent& event )
{
// TODO: Implement m_textCtrlCommentOnText
}

// funkcja tworząca indeksy po wybraniu katalogu
void GUIMyFrame1::RebuildIndexPage()
{
    int textCtrlWidth, textCtrlHeight, rows, cols;
    m_textCtrlWidth->GetValue().ToLong((long*)&textCtrlWidth);
    m_textCtrlHeight->GetValue().ToLong((long*)&textCtrlHeight);
    m_textCtrlRows->GetValue().ToLong((long*)&rows);
    m_textCtrlColls->GetValue().ToLong((long*)&cols);

    // potrzebne 36px na header z m_currentPage, itd...
    int newHeight = textCtrlHeight - 36;
    int thumbnailHeight = newHeight / rows;
    int thumbnailPhotoHeight = thumbnailHeight - 16;
    int thumbnailWidth = textCtrlWidth / cols;

    wxArrayString fileNames = GetSortedBmpFileNames(m_selectedFolder);
    wxString comment = m_textCtrlComment->GetValue();

    int thumbsPerPage = rows * cols;
    int totalPages = (fileNames.GetCount() + thumbsPerPage - 1) / thumbsPerPage;
    m_indexPageBitmaps.clear();


    for (int page = 0; page < totalPages; ++page) {
        int startIdx = page * thumbsPerPage;
        int endIdx = std::min(startIdx + thumbsPerPage, (int)fileNames.GetCount());
        wxArrayString pageFiles;

        for (int i = startIdx; i < endIdx; ++i) {
            pageFiles.Add(fileNames[i]);
        }

        // tworzymy bitmapę do wybranych plików - tych które się na niej zmieszczą
        m_indexPageBitmaps.push_back(CreateIndexPageBitmap(
            pageFiles,
            m_selectedFolder,
            comment,
            textCtrlWidth,
            textCtrlHeight,
            rows,
            cols,
            thumbnailWidth,
            thumbnailPhotoHeight,
            thumbnailHeight,
            page
        ));
    }

    m_currentPage = 0;
    if (!m_indexPageBitmaps.empty()) {
        m_indexPageBitmap = m_indexPageBitmaps[0];
    }
    else {
        m_indexPageBitmap = wxBitmap(textCtrlWidth, textCtrlHeight); // pusta strona
    }  

    m_scrolledWindow1->SetScrollbars(20, 20, textCtrlWidth / 20.f, textCtrlHeight / 20.f);
    m_scrolledWindow1->Refresh();
}


// funkcja tworząca bitmapę dla danych nazw plików, rozmiarów okna, itd.
wxBitmap GUIMyFrame1::CreateIndexPageBitmap(
    const wxArrayString& fileNames,
    const wxString& folderPath,
    const wxString& comment,
    int pageWidth,
    int pageHeight,
    int rows,
    int cols,
    int thumbW,
    int thumbPhotoH,
    int thumbH, // rozmiar całego thumbnail - wraz z podpisem
    int pageNum
)
{
    bool done = false;
    wxBitmap bitmap(pageWidth, pageHeight);
    wxMemoryDC memDC(bitmap);

    memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();

    // header
    wxString header = wxString::Format(
        "strona: %d, katalog: %s",
        pageNum + 1,
        wxFileName(folderPath).GetFullName()
    );

    memDC.DrawText(header, 5, 2);
    memDC.DrawText("komentarz: " + comment, 5, 18);

    const int headerOffsetY = 36; // rozmiar headera

    // miniatury
    int idx = 0;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (idx >= (int)fileNames.GetCount()) {
                done = true;
                break;
            }

            wxString fileName = fileNames[idx];
            wxImage img(folderPath + "/" + fileName, wxBITMAP_TYPE_BMP);

            if (!img.IsOk())
            {
                ++idx;
                continue;
            }

			// tworzenie miniatury w dostępnym miejscu
            int imgW = img.GetWidth();
            int imgH = img.GetHeight();
            double scale = std::min((double)thumbW / imgW, (double)thumbPhotoH / imgH);
            int scaledW = std::max(1, (int)(imgW * scale));
            int scaledH = std::max(1, (int)(imgH * scale));
            wxImage scaledImg = img.Scale(scaledW, scaledH, wxIMAGE_QUALITY_HIGH);
            wxBitmap bmp(scaledImg);

            int x = c * thumbW + (thumbW - scaledW) / 2;
            int y = r * thumbH + headerOffsetY + (thumbPhotoH - scaledH) / 2;

            memDC.DrawBitmap(bmp, x, y, false);

			
            wxString shortName = ShortenFileName(fileName, thumbW, memDC);
            memDC.DrawText(shortName, c * thumbW, r * thumbH + headerOffsetY + thumbPhotoH + 2);

            ++idx;
        }

        if (done)
            break;
    }

    memDC.SelectObject(wxNullBitmap);
    return bitmap;
}

// funkcja skracająca nazwę pliku tak, aby zmieściła się w szerokości przeznaczonej na miniaturę
wxString GUIMyFrame1::ShortenFileName(const wxString& name, int maxWidth, wxDC& dc)
{
	wxString result = name;
	int textWidth = dc.GetTextExtent(result).GetWidth();
	if (textWidth <= maxWidth) return result;
	for (int i = result.Length(); i > 0; --i) {
		wxString test = wxT("~") + result.Right(i);
		if (dc.GetTextExtent(test).GetWidth() <= maxWidth) return test;
	}
	return wxT("~") + result.Right(8); // fallback
}

// funkcja sortująca nazwy zdjęc w folderze
wxArrayString GUIMyFrame1::GetSortedBmpFileNames(const wxString& folderPath)
{
	wxArrayString files;
	wxDir dir(folderPath);
	if (!dir.IsOpened()) return files;
	wxString filename;

	bool cont = dir.GetFirst(&filename, "*.bmp", wxDIR_FILES);
	while (cont) {
		files.Add(filename);
		cont = dir.GetNext(&filename);
	}
	files.Sort();

	return files;
}