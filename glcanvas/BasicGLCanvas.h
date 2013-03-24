#ifndef BASICGLCANVAS_H
#define BASICGLCANVAS_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class BasicGLCanvas: public wxGLCanvas
{
  protected:
    wxGLContext* m_Context;
  public:
    BasicGLCanvas(wxFrame* parent, int* args);
    virtual ~BasicGLCanvas();

    void resized(wxSizeEvent& evt);

    int getWidth() const;
    int getHeight() const;

    virtual void render(wxPaintEvent& evt);
    void prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y) const;
    void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y) const;

    // events
    virtual void mouseMoved(wxMouseEvent& event);
    virtual void mouseDown(wxMouseEvent& event);
    virtual void mouseWheelMoved(wxMouseEvent& event);
    virtual void mouseReleased(wxMouseEvent& event);
    virtual void rightClick(wxMouseEvent& event);
    virtual void mouseLeftWindow(wxMouseEvent& event);
    virtual void keyPressed(wxKeyEvent& event);
    virtual void keyReleased(wxKeyEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif // BASICGLCANVAS_H
