// Below is a link to the original project on NeHe
//http://nehe.gamedev.net/tutorial/playing_avi_files_in_opengl/23001/

#include <windows.h>											// Header File For Windows
#include <gl\gl.h>												// Header File For The OpenGL32 Library
#include <gl\glu.h>												// Header File For The GLu32 Library
#include <vfw.h>												// Header File For Video For Windows
#include "NeHeGL.h"												// Header File For NeHeGL

#include "Cube.h"

#pragma comment( lib, "opengl32.lib" )							// Search For OpenGL32.lib While Linking
#pragma comment( lib, "glu32.lib" )								// Search For GLu32.lib While Linking
#pragma comment( lib, "vfw32.lib" )								// Search For VFW32.lib While Linking

#ifndef CDS_FULLSCREEN											// CDS_FULLSCREEN Is Not Defined By Some
#define CDS_FULLSCREEN 4										// Compilers. By Defining It This Way,
#endif															// We Can Avoid Errors

GL_Window*	g_window;
Keys*		g_keys;

// User Defined Variables
float		angle;												// Used For Rotation
float		lrRot;												// Left/Right Rotation
float		udRot;												// Up/Down Rotation

Cube		videoCube;											// Create our video cube

GLUquadricObj *quadratic;										// Storage For Our Quadratic Objects

BOOL Initialize (GL_Window* window, Keys* keys)					// Any GL Init Code & User Initialiazation Goes Here
{
	g_window	= window;
	g_keys		= keys;
	TCHAR	title[100];											// Will Hold The Modified Window Title

	// Start Of User Initialization
	angle = 0.0f;												// Set Starting Angle To Zero
	glClearColor (0.0f, 0.0f, 0.0f, 0.5f);						// Black Background
	glClearDepth (1.0f);										// Depth Buffer Setup
	glDepthFunc (GL_LEQUAL);									// The Type Of Depth Testing (Less Or Equal)
	glEnable(GL_DEPTH_TEST);									// Enable Depth Testing
	glShadeModel (GL_SMOOTH);									// Select Smooth Shading
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate

	quadratic=gluNewQuadric();									// Create A Pointer To The Quadric Object
	gluQuadricNormals(quadratic, GLU_SMOOTH);					// Create Smooth Normals 
	gluQuadricTexture(quadratic, GL_TRUE);						// Create Texture Coords 

	glEnable(GL_TEXTURE_2D);									// Enable Texture Mapping
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);	// Set Texture Max Filter
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);	// Set Texture Min Filter

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);		// Set The Texture Generation Mode For S To Sphere Mapping
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);		// Set The Texture Generation Mode For T To Sphere Mapping

	videoCube.Initalize(2,"data/face2.avi","data/Band.avi","data/Monster.avi","data/swirl.avi","data/windows.avi","data/taxi.avi"); // Initalize the cube and assign values

	wsprintf (title, "Chris Beyer Graphic Project");
	SetWindowText(g_window->hWnd, title);	

	return TRUE;												// Return TRUE (Initialization Successful)
}

void Deinitialize (void)										// Any User DeInitialization Goes Here
{
	videoCube.CloseVideo();										// Close the AVI Files
}

void Update (DWORD milliseconds)								// Perform Motion Updates Here
{
	if (g_keys->keyDown [VK_ESCAPE] == TRUE)					
	{
		TerminateApplication (g_window);						// Terminate The Program
	}

	if (g_keys->keyDown [VK_F1] == TRUE)						
	{
		ToggleFullscreen (g_window);							// Toggle Fullscreen Mode
	}

	if (g_keys->keyDown [VK_UP])							
	{
		udRot -= 1.0; 
	}

	if (g_keys->keyDown[VK_DOWN])									
	{													
		udRot += 1.0;
	}

	if (g_keys->keyDown[VK_RIGHT])									
	{													
		lrRot += 1.0;
	}

	if (g_keys->keyDown[VK_LEFT])									
	{													
		lrRot -= 1.0;
	}

	videoCube.CheckFrame(milliseconds);							// Updates the frames of the avi files

}

void Draw (void)												// Draw Our Scene
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer

	glLoadIdentity ();											// Reset The Modelview Matrix
	glTranslatef (0.0f, 0.0f, -10.0f);							// Translate 10 Units Into The Screen
									
		glRotatef (udRot*1.1f, 1.0f, 0.0f, 0.0f);				// Rotate On The X-Axis By angle
		glRotatef (lrRot*1.1f, 0.0f, 1.0f, 0.0f);				// Rotate On The Y-Axis By angle

		videoCube.Draw();
										
	glFlush ();													// Flush The GL Rendering Pipeline
}