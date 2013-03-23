#ifndef BASICGLCANVAS_H
#define BASICGLCANVAS_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class BasicGLCanvas: public wxGLCanvas
{
  private:
    wxGLContext* m_Context;
  public:
    BasicGLCanvas(wxFrame* parent, int* args);
    virtual ~BasicGLCanvas();

    void resized(wxSizeEvent& evt);

    int getWidth();
    int getHeight();

    void render(wxPaintEvent& evt);
    void prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
    void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);

    // events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif // BASICGLCANVAS_H
