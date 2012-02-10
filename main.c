/*
 *	File		:	main.c
 *	Description	:	This implements the main function of the program. Compile this file and run the executable to run the program.
 *	Author		:	Harshul Jain/Raj Kamal Singh
 *	Created On	:	10 Feb 11:01
 *	Last Edited	:	10 Feb 11:01
 */


#include<stdio.h>
#include<GL/glut.h>
#include"key.h"
#include"window.h"


void init(){
        glClearColor(0.0,0.0,0.0,1.0); /* black background  */
        glColor3f(0.0, 1.0, 0.0); /* draw in green, until color changed  */
        glMatrixMode(GL_PROJECTION);   /* enter GL_PROJECTION mode to make changes to the projection view matrix */
        glLoadIdentity();
        gluOrtho2D(0.0,ortho_x,0.0,ortho_y);     /* left, right, bottom, up: aspect ratio should be same as in glutInitWindowSize */
        glMatrixMode(GL_MODELVIEW);  /* come back to the modelview mode, in which objects are created  */
}

void createField(){

}

void lets_draw(void){
        glClear(GL_COLOR_BUFFER_BIT);
        createField();
        glFlush();
}

int main(int argc, char** argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(10,10); 
        glutInitWindowSize(win_x,win_y);
        glutCreateWindow("Interactive Football Field");
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleWindowResize);
        init();
        glutDisplayFunc(lets_draw);
        glutMainLoop();
        return 0;
}
