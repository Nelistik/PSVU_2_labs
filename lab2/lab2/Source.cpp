#include<windows.h>
#include<glut.h>

const float camera[] = { 0,0,1 };
double rt_z = 0;
double rt_x = 0;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, 0, 0);
}
void cameraFunc(int button, int x, int y) { //функция вращения камеры
	if (button == GLUT_KEY_RIGHT) rt_z += 1;
	else if (button == GLUT_KEY_LEFT) rt_z -= 1;
	else if (button == GLUT_KEY_UP) rt_x += 1;
	else if (button == GLUT_KEY_DOWN) rt_x -= 1;
	glutPostRedisplay();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rt_x, 1.0, 0.0, 0.0);
	glRotatef(rt_z, 0.0, 0.0, 1.0);
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;

	// цветок 1
	glColor3f(0.0f, 1.0f, 0.0f);//стебель
	glTranslatef(x + 0.1, y + 0.7, z - 0.1);
	GLUquadric* obj = gluNewQuadric();
	gluCylinder(obj, 0.02, 0.02, 0.5, 30, 30);

	glColor3f(1.0f, 1.0f, 0.3f); //рыльце
	glTranslatef(x, y, z);
	glutSolidSphere(0.1f, 50, 50);

	glColor3f(0.7f, 0.6f, 0.7f); //лепестки
	glTranslatef(x, y + 0.15, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x + 0.15, y - 0.15, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.15, y - 0.15, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.15, y + 0.15, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glFlush();

	// цветок 2
	glColor3f(0.0f, 1.0f, 0.0f); //стебель
	glTranslatef(x + 0.55, y - 0.4, z + 0.001);
	GLUquadric* obj1 = gluNewQuadric();
	gluCylinder(obj1, 0.02, 0.02, 0.5, 50, 50);

	glColor3f(1.0f, 1.0f, 0.3f); //рыльце
	glTranslatef(x, y, z);
	glutSolidSphere(0.1f, 50, 50);
	glFlush();

	glColor3f(0.0f, 1.0f, 1.0f); //лепестки
	glTranslatef(x, y + 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x + 0.14, y - 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.14, y - 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.14, y + 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glFlush();

	// цветок 3
	glColor3f(0.0f, 1.0f, 0.0f); //стебель
	glTranslatef(x - 0.15, y - 0.6, z + 0.001);
	GLUquadric* obj2 = gluNewQuadric();
	gluCylinder(obj2, 0.02, 0.02, 0.5, 50, 50);
	glColor3f(1.0f, 1.0f, 0.3f); //рыльце
	glTranslatef(x, y, z);
	glutSolidSphere(0.1f, 50, 50);
	glFlush();
	glColor3f(1.0f, 0.0f, 0.0f); //лепестки
	glTranslatef(x, y + 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x + 0.14, y - 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.14, y - 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glTranslatef(x - 0.14, y + 0.14, z + 0.001);
	glutSolidSphere(0.1f, 50, 50);
	glFlush();

	glBegin(GL_POLYGON); //текстура земли
	glColor3f(0.4f, 1.0f, 0.4f);
	glVertex3f(300.0f, 300.0f, 0.49f);
	glVertex3f(300.0f, -300.0f, 0.49f);
	glVertex3f(-300.0f, -300.0f, 0.49f);
	glVertex3f(-300.0f, 300.0f, 0.49f);
	glEnd();
	glutSwapBuffers();
}

const float light_lab1[4] = { 1,-1, -1, 0 };
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("lab2");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(Display);
	glutSpecialFunc(cameraFunc);

	Init();

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_lab1);

	glutMainLoop();
	return 0;
}