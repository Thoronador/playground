#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "BasicGLCanvas.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
    BasicGLCanvas * glPane;
};

class MyFrame: public wxFrame
{
private:
  wxGLCanvas* canvasGL ;

public:

    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnTriangle(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

enum
{
    ID_Quit = 1,
    ID_About,
    ID_Triangle,
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Quit,  MyFrame::OnQuit)
    EVT_MENU(ID_About, MyFrame::OnAbout)
    EVT_MENU(ID_Triangle, MyFrame::OnTriangle)
END_EVENT_TABLE()

//This implements the "main" function.
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    MyFrame *frame = new MyFrame( _("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
    //frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello GL World"), wxPoint(50,50), wxSize(400,200));

    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};

    glPane = new BasicGLCanvas( (wxFrame*) frame, args);
    sizer->Add(glPane, 1, wxEXPAND);

    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);


    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, -1, title, pos, size),
  canvasGL(NULL)
{
    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Triangle, _("&Triangle") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( _("Welcome to wxWidgets!") );

    canvasGL = new wxGLCanvas(this, -1, wxPoint(0,0));
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("This is a wxWidgets Hello world sample"),
                  _("About Hello World"),
                  wxOK | wxICON_INFORMATION, this );
}

void MyFrame::OnTriangle(wxCommandEvent& WXUNUSED(event))
{
    canvasGL->SetCurrent();
}
