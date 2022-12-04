#include<windows.h>
#include<glut.h>//����������� ����������


void PreReq()
{
	//��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	//������� ����
	glClearColor(1.0, 1.0, 1.0, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Drawing()
{
	glColor3f(0.95, 0.7, 0.51);//������� ���� ������������

	glBegin(GL_TRIANGLES);//��1
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);//��2
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glEnd();

	glColor3f(0.145, 0.309, 0.467);//����-����� ����
	glBegin(GL_LINE_LOOP);//�������
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400); //������� ����
	glutInitWindowPosition(150, 150); //������� ����
	glutCreateWindow("lab1"); //��� ����
	PreReq(); //����� �������
	glutDisplayFunc(Drawing); //������������ ���������
	glutMainLoop();
	return 0;
}
