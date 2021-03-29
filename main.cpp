
/*** OPENGL CHEOPS PYRAMIDS PROJECT - DIAKOSTERGAKIS MICHALIS & XHULIO HALILI ***/

#include <Windows.h>
#include <GL\glew.h> //OpenGL Extension Wrangler Library
#include <GL\freeglut.h> //OpenGL Utility Toolkit glutCreateWindow
#include <iostream>

void initGL()
{
	glClear(GL_COLOR_BUFFER_BIT); //color buffer clear
}

void render()
{
       
	glBegin(GL_QUADS); // skybox & background	
		glColor3ub(52, 204, 255); // light blue color
		glVertex2f(-1.0, 0.8); // upper left
		glColor3ub(255, 255, 255); // white color
		glVertex2f(1.0, 0.8); // upper right
		glColor3ub(230, 190, 138); // pale gold color
		glVertex2f(1.0, -0.35); // bottom right
		glColor3ub(230, 190, 138); // pale gold color
		glVertex2f(-1.0, -0.35); // bottom Left	
	glEnd();

	glBegin(GL_TRIANGLES); // right pyramid
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(0.3, -0.3); // bottom Left
		glColor3ub(150, 95, 45); // dark gold color 
		glVertex2f(0.6, -0.3); // bottom right
		glColor3ub(205, 133, 63); //gold color
		glVertex2f(0.4, 0.2); // top
	glEnd();

	glBegin(GL_TRIANGLES); // right pyramid shading
		glColor3ub(10, 10, 10); // shading color
		glVertex2f(0.4, 0.2); // top
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(0.3, -0.3); // bottom right
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(0.2, -0.2); // bottom Left
	glEnd();

	glBegin(GL_TRIANGLES); // central pyramid
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(-0.1, -0.3); // bottom Left	
		glColor3ub(150, 95, 45); // dark gold color 
		glVertex2f(0.4, -0.3); // bottom right
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(0.1, 0.4); // top
	glEnd();

	glBegin(GL_TRIANGLES); // central pyramid shading
		glColor3ub(10, 10, 10); // shading color
		glVertex2f(0.1, 0.4); // top
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(-0.1, -0.3); // bottom right
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(-0.2, -0.2); // bottom Left	
	glEnd();

	glBegin(GL_TRIANGLES); // left pyramid
		glColor3ub(205, 133, 63); // gold color
		glColor3ub(150, 95, 45); // dark gold color 
		glVertex2f(0, -0.3); // bottom right
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(-0.5, -0.3); // bottom Left	
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(-0.25, 0.3); // top
	glEnd();

	glBegin(GL_TRIANGLES); // left pyramid shading
		glColor3ub(10, 10, 10); // shading color
		glVertex2f(-0.25, 0.3); // top
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(-0.5, -0.3); // bottom right
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(-0.45, -0.3); // bottom Left	
	glEnd(); 

	glBegin(GL_TRIANGLES); // small pyramid
		glColor3ub(205, 133, 63); // gold color
		glColor3ub(150, 85, 45); // dark gold color 
		glVertex2f(-0.05, -0.3); // bottom right
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(-0.25, -0.3); // bottom Left	
		glColor3ub(205, 133, 63); // gold color
		glVertex2f(-0.15, -0.1); // top
	glEnd();

	glBegin(GL_TRIANGLES); // small pyramid shading
		glColor3ub(10, 10, 10); // shading color
		glVertex2f(-0.15, -0.1); // top
		glColor3ub(116, 76, 40); // brown color 
		glVertex2f(-0.2, -0.3); // bottom right
		glColor3ub(116, 76, 40); // brown color
		glVertex2f(-0.25, -0.3); // bottom Left	
	glEnd();

	glFlush();
}

int main(int argc, char* argv[]) {

	//glu OpenGL Utility Library GLU
	
	glutInit(&argc, argv);	
	glMatrixMode(GL_PROJECTION);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(1200, 600); //optimal resolution to match the original photo
	glutCreateWindow("OpenGL Cheops Pyramids");
	

	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}
	
	initGL();


	glutMainLoop();
	return 0;
}