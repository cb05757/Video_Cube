#include "Cube.h"


 Cube::Cube()
{
	// Do Nothing
}

 void Cube::Initalize(int cubeSize,LPCSTR szFile1,LPCSTR szFile2,LPCSTR szFile3,LPCSTR szFile4,LPCSTR szFile5,LPCSTR szFile6)
{
	size = cubeSize; // Size of our Cube
	// Offset from center
	xOff = 0;
	yOff = 0;
	zOff = 0;

	// handle the initalization of the video files
	video1.OpenAVI(szFile1);
	video2.OpenAVI(szFile2);
	video3.OpenAVI(szFile3);
	video4.OpenAVI(szFile4);
	video5.OpenAVI(szFile5);
	video6.OpenAVI(szFile6);
}

 void Cube::Initalize(int cubeSize,float newX,float newY,float newZ,LPCSTR szFile1,LPCSTR szFile2,LPCSTR szFile3,LPCSTR szFile4,LPCSTR szFile5,LPCSTR szFile6)
{ // Add offset in also x, y, z | overload the method so that this is not required
	size = cubeSize; // Size of our Cube
	xOff = newX;
	yOff = newY;
	zOff = newZ;

	// handle the initalization of the video files
	video1.OpenAVI(szFile1);
	video2.OpenAVI(szFile2);
	video3.OpenAVI(szFile3);
	video4.OpenAVI(szFile4);
	video5.OpenAVI(szFile5);
	video6.OpenAVI(szFile6);
}

 void Cube::Draw()
{	
	
	glTranslatef (xOff, yOff, zOff); // recently added

// Front Face
		video1.GrabAVIFrame();										// Grab A Frame From The AVI
		glBegin(GL_QUADS);
			glNormal3f( 0.0f, 0.0f, 0.5f);						
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f(size*-1.0f, size*-1.0f, size*1.0f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f( size*1.0f, size*-1.0f, size*1.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f( size*1.0f,  size*1.0f,  size*1.0f);
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f(size*-1.0f,  size*1.0f,  size*1.0f);
		glEnd();

// Back Face------------------------------------------------------------

		video2.GrabAVIFrame();
		glBegin(GL_QUADS);
			glNormal3f( 0.0f, 0.0f,-0.5f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f(size*-1.0f, size*-1.0f, size*-1.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f(size*-1.0f,  size*1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f( size*1.0f,  size*1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f( size*1.0f, size*-1.0f, size*-1.0f);
		glEnd();

// Top Face-------------------------------------------------------------

		video3.GrabAVIFrame();
		glBegin(GL_QUADS);
			glNormal3f( 0.0f, 0.5f, 0.0f);	
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f(size*-1.0f,  size*1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f(size*-1.0f,  size*1.0f,  size*1.0f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f( size*1.0f,  size*1.0f,  size*1.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f( size*1.0f,  size*1.0f, size*-1.0f);
		glEnd();

// Bottom Face----------------------------------------------------------

		video4.GrabAVIFrame();
		glBegin(GL_QUADS);
			glNormal3f( 0.0f,-0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f(size*-1.0f, size*-1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f( size*1.0f, size*-1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f( size*1.0f, size*-1.0f,  size*1.0f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f(size*-1.0f, size*-1.0f,  size*1.0f);
		glEnd();

// Right Face------------------------------------------------------------

		video5.GrabAVIFrame();
		glBegin(GL_QUADS);
			glNormal3f( 0.5f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f( size*1.0f, size*-1.0f, size*-1.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f( size*1.0f,  size*1.0f, size*-1.0f);
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f( size*1.0f,  size*1.0f,  size*1.0f);
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f( size*1.0f, size*-1.0f,  size*1.0f);
		glEnd();

// Left Face------------------------------------------------------------

		video6.GrabAVIFrame();
		glBegin(GL_QUADS);
			glNormal3f(-0.5f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); 
				glVertex3f(size*-1.0f, size*-1.0f, size*-1.0f);
			glTexCoord2f(1.0f, 0.0f); 
				glVertex3f(size*-1.0f, size*-1.0f,  size*1.0f);
			glTexCoord2f(1.0f, 1.0f); 
				glVertex3f(size*-1.0f,  size*1.0f,  size*1.0f);
			glTexCoord2f(0.0f, 1.0f); 
				glVertex3f(size*-1.0f,  size*1.0f, size*-1.0f);
		glEnd();

}
 
 void Cube::CheckFrame(DWORD milliseconds)
 {
	 video1.CheckFrame(milliseconds); 
	 video2.CheckFrame(milliseconds); 
	 video3.CheckFrame(milliseconds);
	 video4.CheckFrame(milliseconds);
	 video5.CheckFrame(milliseconds);
	 video6.CheckFrame(milliseconds);
 }

 void Cube::CloseVideo()
 {
	 video1.CloseAVI();	 
	 video2.CloseAVI();
	 video3.CloseAVI();
	 video4.CloseAVI();
	 video5.CloseAVI();
	 video6.CloseAVI();
 }
 
 Cube::~Cube(void) // deconstructor
{
}
