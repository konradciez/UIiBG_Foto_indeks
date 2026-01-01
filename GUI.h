///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* m_buttonPrevious;
		wxScrolledWindow* m_scrolledWindow1;
		wxButton* m_buttonNext;
		wxButton* m_buttonFolder;
		wxButton* m_buttonPrint;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlWidth;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrlHeight;
		wxStaticText* m_staticText6;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrlRows;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrlColls;
		wxStaticText* m_staticText8;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrlComment;

		// Virtual event handlers, override them in your derived class
		virtual void m_buttonLeftOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow1OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_buttonRightOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonFolderOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonPrintOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlWidthOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlHeightOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlRowsOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCollsOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCommentOnText( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Foto indeks"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

