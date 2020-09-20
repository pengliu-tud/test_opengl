//
// Created by lyp on 20.09.20.
//
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*
Mat img = imread("../shanghai.bmp");

int width = img.cols;
int height = img.cols;

GLubyte* pixels;

GLuint load_texture(cv::Mat& image)
{
    int width = image.cols;
    int height = image.cols;
    //OpenGL纹理用整型数表示
    GLuint texture_ID;

    //获取图像指针
    int pixellength = width*height*3;
    pixels = new GLubyte[pixellength];
    memcpy(pixels, image.data, pixellength * sizeof(unsigned char));

    //将texture_ID设置为2D纹理信息
    glGenTextures(1, &texture_ID);
    glBindTexture(GL_TEXTURE_2D, texture_ID);
    //纹理放大缩小使用线性插值
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    free(pixels);
    return texture_ID;
}

void draw()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    drawCameraFrame();
    glFlush();
}

void drawCameraFrame()
{
    GLuint image = load_texture();
    if (!m_isTextureInitialized)
    {
        glGenTextures(1, &m_backgroundTextureId);
        glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        m_isTextureInitialized = true;
    }

    int w = m_backgroundTextureId.cols;
    int h = m_backgroundTextureId.rows;

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

    if (m_backgroundImage.channels() == 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_backgroundImage.data);
    else if(m_backgroundImage.channels() == 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, m_backgroundImage.data);
    else if (m_backgroundImage.channels()==1)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_backgroundImage.data);

    const GLfloat bgTextureVertices[] = { 0, 0, w, 0, 0, h, w, h };
    const GLfloat bgTextureCoords[]   = { 1, 0, 1, 1, 0, 0, 0, 1 };
    const GLfloat proj[]              = { 0, -2.f/w, 0, 0, -2.f/h, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1 };

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(proj);

    glMatrixMode(GL_MODEVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, bgTextureVertices);
    glTexCoordPointer(2, GL_FLOAT, 0, bgTextureCoords);

    glColor4f(1,1,1,1);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
}

void processVideo()
{
    cv::Mat currentFrame;
    capture >> currentFrame;

    // Check the capture succeeded:
    if (currentFrame.empty())
    {
        std::cout << "Cannot open video capture device" << std::endl;
        return;
    }

    cv::Size frameSize(currentFrame.cols, currentFrame.rows);
}

bool processFrame(const cv::Mat& cameraFrame)
{
    // Clone image used for background (we will draw overlay on it)
    cv::Mat img = cameraFrame.clone();

    // Set a new camera frame:
    drawingCtx.updateBackground(img);

    // Request redraw of the window:
    drawingCtx.updateWindow();


}

int main( int argc, char** argv)
{
    cv::VideoCapture capture = cv::VideoCapture(1);
    cv::namedWindow(windowName, cv::WINDOW_OPENGL);
    cv::resizeWindow(windowName, frameSize.width, frameSize.height);
    cv::setOpenGlContext(windowName);
    cv::setOpenGlDrawCallback(windowName, draw, NULL);
    cv::updateWindow(windowName);

}
*/

Mat m_backgroundImage = imread("/home/lyp/1_Code/test_opengl/spongebob.jpg");
GLuint m_backgroundTextureId;

void drawCameraFrame()
{
    glGenTextures(1, &m_backgroundTextureId);
    glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


    int w = m_backgroundImage.cols;
    int h = m_backgroundImage.rows;

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

    // Upload new texture data:

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_backgroundImage.data);

    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, m_backgroundImage.data);

    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_backgroundImage.data);

    const GLfloat bgTextureVertices[] = { 0, 0, static_cast<GLfloat>(w), 0, 0, static_cast<GLfloat>(h), static_cast<GLfloat>(w), static_cast<GLfloat>(h) };
    const GLfloat bgTextureCoords[]   = { 1, 0, 1, 1, 0, 0, 0, 1 };
    const GLfloat proj[]              = { 0, -2.f/w, 0, 0, -2.f/h, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1 };

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(proj);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_backgroundTextureId);

    // Update attribute values.
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, bgTextureVertices);
    glTexCoordPointer(2, GL_FLOAT, 0, bgTextureCoords);

    glColor4f(1,1,1,1);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);

}

void draw(void* param)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    drawCameraFrame();
    glFlush();
}

int main ( int argc, char** argv )
{
//    cv::namedWindow("windowName", cv::WINDOW_OPENGL);
    cv::namedWindow("windowName");
    cv::resizeWindow("windowName", m_backgroundImage.cols, m_backgroundImage.rows);

    cv::setOpenGlContext("windowName");

    cv::setOpenGlDrawCallback("windowName", draw, nullptr);

    updateWindow("windowName");
    waitKey(0);
    return 0;
}

/*

#include <GL/glut.h>
#include <GL/gl.h>
#include <opencv2/cv.h>
#include <opencv2/highgui/highgui.hpp>

GLuint texture; //纹理图
IplImage *img;
unsigned char* textureImage;

void makeTextureImg(IplImage *image)
{
    int width = image->width;
    int height = image->height;
    CvScalar s;

    //读入彩色图
    textureImage = new unsigned char[width * height * 3];
    for (int i = 0; i < height; i++ )
        for (int j = 0; j < width; j++)
        {
            s = cvGet2D(image, i, j);
            textureImage[i * 3 * width + 3 * j] = s.val[0];
            textureImage[i * 3 * width + 3 * j + 1] = s.val[1];
            textureImage[i * 3 * width + 3 * j + 2] = s.val[2];
        }

}

int loadTexture(IplImage* image, GLuint* text)
{
    if (image==NULL) return -1;
    glGenTextures(1, text);
    glBindTexture(GL_TEXTURE_2D, *text);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);

    return 0;

}

void display()
{
    glClearColor (0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize (500, 500);
}
*/