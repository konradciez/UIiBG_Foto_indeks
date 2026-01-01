///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPrevious = new wxButton( this, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonPrevious->SetMaxSize( wxSize( 20,-1 ) );

	bSizer7->Add( m_buttonPrevious, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	m_scrolledWindow1->SetBackgroundColour( wxColour( 224, 224, 224 ) );

	bSizer7->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );

	m_buttonNext = new wxButton( this, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonNext->SetMaxSize( wxSize( 20,-1 ) );

	bSizer7->Add( m_buttonNext, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );


	bSizer2->Add( bSizer7, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonFolder = new wxButton( this, wxID_ANY, _("Wybierz katalog"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_buttonFolder, 0, wxALL, 5 );

	m_buttonPrint = new wxButton( this, wxID_ANY, _("Drukuj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_buttonPrint, 0, wxALL, 5 );


	bSizer3->Add( bSizer4, 0, wxALIGN_CENTER|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxALL|wxEXPAND, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Rozmiar indeksu:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlWidth = new wxTextCtrl( this, wxID_ANY, _("800"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlWidth->SetMaxSize( wxSize( 70,-1 ) );

	bSizer5->Add( m_textCtrlWidth, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("px"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer5->Add( m_staticText5, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrlHeight = new wxTextCtrl( this, wxID_ANY, _("600"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlHeight->SetMaxSize( wxSize( 70,-1 ) );

	bSizer5->Add( m_textCtrlHeight, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, _("px"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer5->Add( m_staticText6, 0, wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxALIGN_LEFT, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Ilosc miniaturek:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlRows = new wxTextCtrl( this, wxID_ANY, _("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlRows->SetMaxSize( wxSize( 50,-1 ) );

	bSizer6->Add( m_textCtrlRows, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, _("wiersze"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer6->Add( m_staticText7, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxALL, 5 );

	m_textCtrlColls = new wxTextCtrl( this, wxID_ANY, _("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlColls->SetMaxSize( wxSize( 50,-1 ) );

	bSizer6->Add( m_textCtrlColls, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, _("kolumny"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer6->Add( m_staticText8, 0, wxALL, 5 );


	bSizer3->Add( bSizer6, 0, wxALIGN_LEFT, 5 );

	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Komentarz:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer3->Add( m_staticText11, 0, wxALL, 5 );

	m_textCtrlComment = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 230,-1 ), 0 );
	bSizer3->Add( m_textCtrlComment, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonPrevious->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_buttonLeftOnButtonClick ), NULL, this );
	m_scrolledWindow1->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_scrolledWindow1OnPaint ), NULL, this );
	m_buttonNext->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_buttonRightOnButtonClick ), NULL, this );
	m_buttonFolder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_buttonFolderOnButtonClick ), NULL, this );
	m_buttonPrint->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_buttonPrintOnButtonClick ), NULL, this );
	m_textCtrlWidth->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlWidthOnText ), NULL, this );
	m_textCtrlHeight->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlHeightOnText ), NULL, this );
	m_textCtrlRows->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlRowsOnText ), NULL, this );
	m_textCtrlColls->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlCollsOnText ), NULL, this );
	m_textCtrlComment->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlCommentOnText ), NULL, this );
}

MyFrame1::~MyFrame1()
{
}
