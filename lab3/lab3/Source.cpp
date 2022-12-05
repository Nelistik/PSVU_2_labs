#include<glut.h>
#include <windows.h>


const float camera[] = { 0,0,1 };
double rt_z = 0;
double rt_x = 0;


void cameraFunc(int button, int x, int y) { //функция вращения камеры
	if (button == GLUT_KEY_RIGHT) rt_z += 10;
	else if (button == GLUT_KEY_LEFT) rt_z -= 10;
	else if (button == GLUT_KEY_UP) rt_x += 10;
	else if (button == GLUT_KEY_DOWN) rt_x -= 10;
	glutPostRedisplay();
}

int angle = 0;
int zeroTime;        // стартовое время
static GLfloat rot = 0.0f;
static GLfloat vRate = 100.0f; // скорость движения объекта

void texture() { //текстура
	GLuint Texture;
	int width, height;
	width = 1;
	height = 2;
	struct { unsigned char r, g, b, a; }data[3][2];
	data[2][0].b = 255;
	data[2][0].r = 255;
	data[2][0].g = 255;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBindTexture(GL_TEXTURE_2D, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 4, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); // GL_RGBA = 0
}
void Initialize() {
	texture();
	glEnable(GL_TEXTURE_2D);
	glClearColor(1.0, 1.0, 1.0, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, 0, 0);
}

void Display() {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0, -2.0);
	glRotatef(rot, 0, 0, 0);
	glRotatef(rt_x, 1.0, 0.0, 0.0);
	glRotatef(rt_z, 0.0, 0.0, 1.0);
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	// цветок 1
	glColor3f(0.0f, 1.0f, 0.0f);//стебель
	glTranslatef(x + 0.1, y + 0.7, z - 0.1);
	GLUquadric* obj = gluNewQuadric();
	gluCylinder(obj, 0.03, 0.03, 0.5, 50, 50);

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
	gluCylinder(obj1, 0.03, 0.03, 0.5, 50, 50);

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
	gluCylinder(obj2, 0.03, 0.03, 0.5, 50, 50);
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

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 1.0f, 0.4f);
	glVertex3f(300.0f, 300.0f, 0.49f);
	glVertex3f(300.0f, -300.0f, 0.49f);
	glVertex3f(-300.0f, -300.0f, 0.49f);
	glVertex3f(-300.0f, 300.0f, 0.49f);
	glEnd();
	glutSwapBuffers();
}
void codingFrames(int width, int height) {
	if (height <= 0) height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width / (double)height, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void animate() {
	int highTime = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = highTime - zeroTime;
	rot = (vRate / 1400) * elapsedTime;
	glutPostRedisplay();
}

const float light0_position[4] = { 100,-1, 0, 100 };

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("lab3");
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(Display);
	glutSpecialFunc(cameraFunc);
	glutReshapeFunc(codingFrames);
	glutIdleFunc(animate);

	zeroTime = glutGet(GLUT_ELAPSED_TIME);
	Initialize();

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glutMainLoop();

	return 0;
}
