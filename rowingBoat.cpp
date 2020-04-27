#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using  namespace std;

//variable declarations
int boatStatus = 0;

float boatX = 0;
float boatY = 0;

//text variables
int i, s, m, y; //i is loop variable, s is spacing, m is index var for msg[], y axis value
string ins[2] = { "B: START BOAT","E: STOP BOAT" };
string t; //temp string

//function declarations
void instructions();
void draw_background();
void draw_boat();

//keyboard entries
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'B':		//boat start
	case 'b':
		boatStatus = 1;
		break;
	case 'E':		//boat stop
	case 'e':
		boatStatus = 0;
		break;
	default:
		break;
	}
}

//displays instructions on screen
void instructions()
{
	m = 0;
	y = 700;
	s = 15;
	while (m < 2)
	{
		t = ins[m];
		for (i = 0; i < t.length(); i++)
		{
			glColor3f(0, 0, 0);
			glRasterPos2i((i * s) + 20, y);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, t.at(i));
		}
		m++;
		y = y - 20;
	}
}

void draw_background()
{
	glBegin(GL_POLYGON);		//rectangular background lower
	glColor3f(0.2, 0.5, 0.8);
	glVertex2i(0, 0);
	glVertex2i(1200, 0);
	glVertex2i(1200, 220);
	glVertex2i(0, 220);
	glEnd();
	
	glBegin(GL_POLYGON);		//rectangular background upper
	glColor3f(0.2, 0.6, 0.2);
	glVertex2i(0,220);
	glVertex2i(1200,220);
	glVertex2i(1200,750);
	glVertex2i(0,750);
	glEnd();
}

void draw_Boat()
{
	glBegin(GL_POLYGON);		//boat
	glColor3f(0.9, 0.5, 0.1);
	glVertex2i(250, 20);
	glVertex2i(220, 100);
	glVertex2i(550, 100);
	glVertex2i(500, 20);
	glEnd();

	glBegin(GL_POLYGON);		//man body
	glColor3f(1, 1, 1);
	glVertex2i(270, 100);
	glVertex2i(330, 100);
	glVertex2i(310, 150);
	glVertex2i(290, 150);
	glVertex2i(310, 200);
	glVertex2i(270, 200);
	glVertex2i(270, 100);
	glEnd();

	glBegin(GL_POLYGON);	//face
	glColor3f(1.2, 0.5, 0.4);
	glVertex2i(275, 200);
	glVertex2i(295, 200);
	glVertex2i(295, 220);
	glVertex2i(300, 220);
	glVertex2i(295, 250);
	glVertex2i(275, 250);
	glVertex2i(275, 200);
	glEnd();

	glBegin(GL_POLYGON);	//hair
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(295, 250);
	glVertex2i(300, 270);
	glVertex2i(275, 260);
	glVertex2i(275, 250);
	glVertex2i(295, 250);
	glEnd();

	glBegin(GL_POLYGON);	//oar
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(310, 150);
	glVertex2i(250, 0);
	glVertex2i(270, 0);
	glVertex2i(310, 160);
	glVertex2i(310, 150);
	glEnd();
}

//movement of boat
void boat()
{
	if (boatStatus == 1)
	{
		boatX += .5;
	}
	if (boatX > 1000)
	{
		boatX = -600;
	}
	glPushMatrix();
	glTranslatef(boatX, boatY, 0);
	draw_Boat();
	glPopMatrix();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1200.0, 0.0, 750.0);
}

void myDisplay(void)
{
		draw_background();
		instructions();
		boat();
		glFlush();
		glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1150, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rowing Boat");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
}
