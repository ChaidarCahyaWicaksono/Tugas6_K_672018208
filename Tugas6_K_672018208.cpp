#include<stdlib.h>
#include<Windows.h>
#include<gl/GL.h>
#include<GL\glut.h>
#include <math.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;
int is_depth;




void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{
	if(is_depth)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	glPushMatrix();
	
	//depan
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(-45,15,0);
	glVertex3f(-45,-15, 0);
	glVertex3f(-15, -15, 0);
	glVertex3f(-15,15,0);
	glEnd();
	
//dpn 2
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(-15,15,0);
	glVertex3f(-15,-15, 0);
	glVertex3f(-15, -15, -20);
	glVertex3f(-15,15,-20);
	glEnd();
	
	//dpn3
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(-15,15,-20);
	glVertex3f(-15,-15, -20);
	glVertex3f(15, -15, -20);
	glVertex3f(15,15,-20);
	glEnd();
	
	//dpn4
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(15,15,0);
	glVertex3f(15,-15, 0);
	glVertex3f(15, -15, -20);
	glVertex3f(15,15,-20);
	glEnd();
	
	//dpn5
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(45,15,0);
	glVertex3f(45,-15, 0);
	glVertex3f(15, -15, 0);
	glVertex3f(15,15,0);
	glEnd();
	
	//blkg
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(-45,15,-120);
	glVertex3f(-45,-15, -120);
	glVertex3f(45, -15, -120);
	glVertex3f(45,15,-120);
	glEnd();
	
	//smpg kiri
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(-45,15,0);
	glVertex3f(-45,-15, 0);
	glVertex3f(-45, -15, -120);
	glVertex3f(-45,15,-120);
	glEnd();
	
	//smpg kanan
	glBegin(GL_QUADS);
	glColor3ub(246, 174, 45);
	glVertex3f(45,15,0);
	glVertex3f(45,-15, 0);
	glVertex3f(45, -15, -120);
	glVertex3f(45,15,-120);
	glEnd();
	
	//bwh
	glBegin(GL_QUADS);
	glColor3ub(43, 45, 66);
	glVertex3f(-45,-15,50);
	glVertex3f(45,-15, 50);
	glVertex3f(45, -15, -170);
	glVertex3f(-45,-15,-170);
	glEnd();
	
	//kamarkiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,15,-30);
	glVertex3f(-45,-15, -30);
	glVertex3f(-15, -15, -30);
	glVertex3f(-15,15,-30);
	glEnd();
	
	//kmrkiri2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,15,-60);
	glVertex3f(-45,-15, -60);
	glVertex3f(-15, -15, -60);
	glVertex3f(-15,15,-60);
	glEnd();
	
	//kmrkiri3
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,15,-90);
	glVertex3f(-45,-15, -90);
	glVertex3f(-15, -15, -90);
	glVertex3f(-15,15,-90);
	glEnd();
	
	//kmarkiri4
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-15,15,-30);
	glVertex3f(-15,-15, -30);
	glVertex3f(-15, -15, -90);
	glVertex3f(-15,15,-90);
	glEnd();
	
	//kmrkanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(45,15,-30);
	glVertex3f(45,-15, -30);
	glVertex3f(15, -15, -30);
	glVertex3f(15,15,-30);
	glEnd();
	
	//kmrkanan2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(45,15,-90);
	glVertex3f(45,-15, -90);
	glVertex3f(15, -15, -90);
	glVertex3f(15,15,-90);
	glEnd();
	
	//kmrkanan3
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(15,15,-30);
	glVertex3f(15,-15, -30);
	glVertex3f(15, -15, -90);
	glVertex3f(15,15,-90);
	glEnd();
	
/*	//sgitigaatap
	glBegin(GL_TRIANGLES);
	glColor3ub(138, 90, 68);
	glVertex3f(-45,15,0);
	glVertex3f(-45,15, -120);
	glVertex3f(-45,25,-60);
	glEnd();
	
	//SGITIGAATS
	//sgitigaatap
	glBegin(GL_TRIANGLES);
	glColor3ub(138, 90, 68);
	glVertex3f(-45,20,-40);
	glVertex3f(-45,20, -80);
	glVertex3f(-45,40,-60);
	glEnd();
	
	//SGITIGAATASKANAN
	//sgitigaatap
	glBegin(GL_TRIANGLES);
	glColor3ub(138, 90, 68);
	glVertex3f(45,15,0);
	glVertex3f(45,15, -120);
	glVertex3f(45,25,-60);
	glEnd();
	
	//SGITIGAATS
	//sgitigaatap
	glBegin(GL_TRIANGLES);
	glColor3ub(138, 90, 68);
	glVertex3f(45,20,-40);
	glVertex3f(45,20, -80);
	glVertex3f(45,40,-60);
	glEnd();
	
	//ATAPATAS
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,14,10);
	glVertex3f(50,14, 10);
	glVertex3f(50, 22, -42);
	glVertex3f(-50,22,-42);
	glEnd();
	
	//ATAP ATAS 2
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,22,-42);
	glVertex3f(50,22, -42);
	glVertex3f(50, 40, -60);
	glVertex3f(-50,40,-60);
	glEnd();
	
	//ATAPATASBLKG
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,14,-130);
	glVertex3f(50,14, -130);
	glVertex3f(50, 22, -78);
	glVertex3f(-50,22,-78);
	glEnd();
	
	//ATAP ATAS BLKG2
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,22,-78);
	glVertex3f(50,22, -78);
	glVertex3f(50, 40, -60);
	glVertex3f(-50,40,-60);
	glEnd();
	
*/	//JENDELA KIRI
	glBegin(GL_QUADS);
	glColor3ub(52, 58, 64);
	glVertex3f(-35,14,0.1);
	glVertex3f(-35,-2, 0.1);
	glVertex3f(-25, -2, 0.1);
	glVertex3f(-25,14,0.1);
	glEnd();
	
	//JENDELAKANAN
	glBegin(GL_QUADS);
	glColor3ub(52, 58, 64);
	glVertex3f(35,14,0.1);
	glVertex3f(35,-2, 0.1);
	glVertex3f(25, -2, 0.1);
	glVertex3f(25,14,0.1);
	glEnd();
	
	//JNDELATGH
	glBegin(GL_QUADS);
	glColor3ub(52, 58, 64);
	glVertex3f(15,14,-19.9);
	glVertex3f(15,-2, -19.9);
	glVertex3f(-5, -2, -19.9);
	glVertex3f(-5,14,-19.9);
	glEnd();
	
	//PINTU
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(-15,14,-19.9);
	glVertex3f(-15,-15, -19.9);
	glVertex3f(-5, -15, -19.9);
	glVertex3f(-5,14,-19.9);
	glEnd();
	
	//PGERDEPAN
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(-6,14,0);
	glVertex3f(-6,-15, 0);
	glVertex3f(-5, -15,0);
	glVertex3f(-5,14,0);
	glEnd();
	
	//VARIASI
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(-15,-2,0);
	glVertex3f(-15,-1, 0);
	glVertex3f(-5, -1,0);
	glVertex3f(-5,-2,0);
	glEnd();
	
	//PGERDEPANKANAN
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(6,14,0);
	glVertex3f(6,-15, 0);
	glVertex3f(5, -15,0);
	glVertex3f(5,14,0);
	glEnd();
	
	//VARIASI
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(15,-2,0);
	glVertex3f(15,-1, 0);
	glVertex3f(5, -1,0);
	glVertex3f(5,-2,0);
	glEnd();
	
	//JENDELA KANAN
	glBegin(GL_QUADS);
	glColor3ub(52, 58, 64);
	glVertex3f(45.1,14,-55);
	glVertex3f(45.1,-2, -55);
	glVertex3f(45.1, -2,-65);
	glVertex3f(45.1,14,-65);
	glEnd();
	
	//JENDELA KIRI
	glBegin(GL_QUADS);
	glColor3ub(052, 58, 64);
	glVertex3f(-45.1,14,-55);
	glVertex3f(-45.1,-2, -55);
	glVertex3f(-45.1, -2,-65);
	glVertex3f(-45.1,14,-65);
	glEnd();
	
	//PINTUBLKANG
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(-5,11,-120.1);
	glVertex3f(5,11, -120.1);
	glVertex3f(5, -15,-120.1);
	glVertex3f(-5,-15,-120.1);
	glEnd();
	
	//kasur
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(15,-10,-30);
	glVertex3f(45,-10, -30);
	glVertex3f(45,-10,-45);
	glVertex3f(15,-10,-45);
	glEnd();
	 //ttp kasur
	 
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(15,-10,-45);
	glVertex3f(45,-10, -45);
	glVertex3f(45,-15,-45);
	glVertex3f(15,-15,-45);
	glEnd();
	
		//kasur sebelah
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(15,-10,-90);
	glVertex3f(45,-10, -90);
	glVertex3f(45,-10,-75);
	glVertex3f(15,-10,-75);
	glEnd();
	 //ttp kasur
	 
	glBegin(GL_QUADS);
	glColor3ub(148, 27, 12);
	glVertex3f(15,-10,-75);
	glVertex3f(45,-10, -75);
	glVertex3f(45,-15,-75);
	glVertex3f(15,-15,-75);
	glEnd();
	
	//slimut
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(15,-9.9,-30);
	glVertex3f(25,-9.9, -30);
	glVertex3f(25,-9.9,-45);
	glVertex3f(15,-9.9,-45);
	glEnd();
	
	
	//tv
glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-29);
	glVertex3f(25,2,-29);
	glVertex3f(25,-6,-29);
	glVertex3f(35,-6,-29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,-6,-29);
	glVertex3f(25,-6,-29);
	glVertex3f(25,-6,-30);
	glVertex3f(35,-6,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-29);
	glVertex3f(25,2,-29);
	glVertex3f(25,2,-30);
	glVertex3f(35,2,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(25,2,-29);
	glVertex3f(25,-6,-29);
	glVertex3f(25,-6,-30);
	glVertex3f(25,2,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-29);
	glVertex3f(35,-6,-29);
	glVertex3f(35,-6,-30);
	glVertex3f(35,2,-30);
	glEnd();
	
	
	//figura 1
	glBegin(GL_QUADS);
	glColor3ub(116, 0, 184);
	glVertex3f(-32,2,-29.9);
	glVertex3f(-28,2,-29.9);
	glVertex3f(-28,6,-29.9);
	glVertex3f(-32,6,-29.9);
	glEnd();
	
	//kaca figura
	glBegin(GL_QUADS);
	glColor3ub(144, 224, 239);
	glVertex3f(-31.9,1,-29.8);
	glVertex3f(-27.9,1,-29.8);
	glVertex3f(-27.9,5,-29.8);
	glVertex3f(-31.9,5,-29.8);
	glEnd();
	
	
	//salibbb
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-30,10,-30.9);
	glVertex3f(-30.5,10,-30.9);
	glVertex3f(-30.5,4,-30.9);
	glVertex3f(-30,4,-30.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-32,8,-30.9);
	glVertex3f(-28.5,8,-30.9);
	glVertex3f(-28.5,8.5,-30.9);
	glVertex3f(-32,8.5,-30.9);
	glEnd();
	
	
	
	
	
	
	
	
	
	
	
	
	glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch (key){
		case 'w':
			case 'W':
				glTranslatef(0,0,3);
				break;
		case 'd':
			case 'D':
				glTranslatef(3,0,0);
				break;
		case 's':
			case 'S':
				glTranslatef(0,0,-3);
				break;
		case 'a':
			case 'A':
				glTranslatef(-3,0,0);
				break;
				
		case '7':
			
				glTranslatef(0,3,0);
				break;
		case '9':
			
				glTranslatef(0,-3,0);
				break;
		case '2':
			
				glRotatef(2,1,0,0);
				break;
		case '8':
			
				glRotatef(2,1,0,0);
				break;
		case '6':
			
				glRotatef(2,0,1,0);
				break;
		case '4':
			
				glRotatef(-2,0,1,0);
				break;
		case '1':
			
				glRotatef(2,1,0,1);
				break;
		case '3':
			
				glRotatef(-2,0,0,1);
				break;
		case '5':
			if(is_depth){
				is_depth=0;
				glDisable(GL_DEPTH_TEST);
			}
			else{
				is_depth=1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi){
	if(tinggi==0) tinggi=1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, lebar/tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Chaidar Cahya Wicaksono - 672018208");
    init();
    glutDisplayFunc(tampil);
    glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
