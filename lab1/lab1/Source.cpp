#include<windows.h>
#include<glut.h>//подключение библиотеки


void PreReq()
{
	//Проекция
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	//Фоновый цвет
	glClearColor(1.0, 1.0, 1.0, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Drawing()
{
	glColor3f(0.95, 0.7, 0.51);//бежевый цвет треугольника

	glBegin(GL_TRIANGLES);//тр1
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);//тр2
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glEnd();

	glColor3f(0.145, 0.309, 0.467);//тёмно-синий цвет
	glBegin(GL_LINE_LOOP);//обводка
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
	glutInitWindowSize(400, 400); //Размеры окна
	glutInitWindowPosition(150, 150); //Позиция окна
	glutCreateWindow("lab1"); //Имя окна
	PreReq(); //Вызов функции
	glutDisplayFunc(Drawing); //Вызовфункции отрисовки
	glutMainLoop();
	return 0;
}
