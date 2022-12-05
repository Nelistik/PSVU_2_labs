#include <glut.h>
#include <stdio.h>
#include <math.h>

 /* константа -- астрономическая единица: можно изменить для изменения масштаба */
GLfloat au = 8;

void texture() {
    GLuint Texture;
    int width, height;
    width = -300;
    height = 300;
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
    glTexImage2D(GL_TEXTURE_2D, 100, 400, width, height, 300, GL_RGBA, GL_UNSIGNED_BYTE, data); // GL_RGBA = 0
}

/* Земля -- 1, остальные планеты -- пропорции; солнце задано математическим центром (условные размеры) */
GLfloat Mercf = .4;
GLfloat Venf = .9;
GLfloat defPlanetEf = .30;
GLfloat Marsf = .5;
GLfloat Jupf = 11.0;
GLfloat Satf = 9.0;
GLfloat Urnf = 4.0;
GLfloat Nepf = 3.9;

/* Пропорциональная дистанция (отношение к а.е.)*/
GLfloat Mercd = .311;
GLfloat Vend = .727;
GLfloat defPlanetEd = 1.0;
GLfloat Marsd = 1.60;
GLfloat Jupd = 5.24;
GLfloat Satd = 9.9;
GLfloat Urnd = 20.0;
GLfloat Nepd = 29.97;

/* Начальное положение планет */
GLfloat Merca = 56.0;
GLfloat Vena = 285.0;
GLfloat defPlanetEa = 219.0;
GLfloat Marsa = 208.0;
GLfloat Jupa = 115.0;
GLfloat Sata = 230.0;
GLfloat Urna = 13.0;
GLfloat Nepa = 335.0;

/* планетный год, пропрция */
GLfloat Mercv = .241;
GLfloat Venv = .615;
GLfloat defPlanetEv = 1;
GLfloat Marsv = 1.88;
GLfloat Jupv = 11.9;
GLfloat Satv = 29.4;
GLfloat Urnv = 83.7;
GLfloat Nepv = 163.7;


void init(void) {
    texture();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.00, 0.00, 0.00, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(Nepd * au / 4.1), (Nepd * au / 4.1), -(Nepd * au / 4.1),
        (Nepd * au / 4.1), -(Nepd * au / 4.1), (Nepd * au / 4.1));
    glEnable(GL_COLOR_MATERIAL);
}

/**
 * отрисовка солнца
 */
void DrawSun() {   
    GLfloat surface[] = { 1.0, 1.0, 0.0, 1.0 };
    glColor3f(1.0, 1.0, 0.0);
    GLUquadricObj* Sun;
    Sun = gluNewQuadric();
    gluQuadricNormals(Sun, GL_TRUE);
    gluSphere(Sun, 0.5, 10, 10);
}

/**
 * Отрисовка Меркурия (здесь и далее структурировано по расположению от Солнца)
 */
void DrawMerc() { 
    glPushMatrix();
    glColor3f(.5, .4, 0);
    glRotatef(Merca, 0, 1, 0);
    glTranslatef(Mercd * au, 0.0, 0.0);
    GLUquadricObj* Merc;
    Merc = gluNewQuadric();
    gluQuadricNormals(Merc, GL_TRUE);
    gluSphere(Merc, Mercf * defPlanetEf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Mercd * au) - .05, (Mercd * au) + .05, 100, 100);
    glPopMatrix();

}

/**
 * Венера
 */
void DrawVen() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 2.0);
    glRotatef(Vena, 0, 1, 0);
    glTranslatef(Vend * au, 0.0, 0.0);
    GLUquadricObj* Ven;
    Ven = gluNewQuadric();
    gluQuadricNormals(Ven, GL_TRUE);
    gluSphere(Ven, Venf * defPlanetEf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Vend * au) - .05, (Vend * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Земля (зелёный цвет)
 */
void DrawdefPlanetE() {
    glPushMatrix();
    glColor3f(0, 0.6, 0);
    glRotatef(defPlanetEa, 0, 1, 0);
    glTranslatef(defPlanetEd * au, 0.0, 0.0);
    GLUquadricObj* defPlanetE;
    defPlanetE = gluNewQuadric();
    gluQuadricNormals(defPlanetE, GL_TRUE);
    gluSphere(defPlanetE, defPlanetEf, 20, 20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (defPlanetEd * au) - .05, (defPlanetEd * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Марс
 */
void DrawMars() {     
    glPushMatrix();
    glColor3f(4.0, 0, 0);
    glRotatef(Marsa, 0, 1, 0);
    glTranslatef(Marsd * au, 0.0, 0.0);
    GLUquadricObj* Mars;
    Mars = gluNewQuadric();
    gluQuadricNormals(Mars, GL_TRUE);
    gluSphere(Mars, Marsf * defPlanetEf, 20, 20);
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Marsd * au) - .05, (Marsd * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Юпитер
 */
void DrawJup() {
    GLfloat scaling = 2.0;
    glPushMatrix();
    glColor3f(1.0, 0.2, 0);
    glRotatef(Jupa, 0, 1, 0);
    glTranslatef(Jupd * au / scaling, 0.0, 0.0);
    GLUquadricObj* Jup;
    Jup = gluNewQuadric();
    gluQuadricNormals(Jup, GL_TRUE);
    gluSphere(Jup, defPlanetEf * Jupf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Jupd * au / scaling) - .05, (Jupd * au / scaling) +
        .05, 100, 100);
    glPopMatrix();

}

/**
 * Сатурн
 */
void DrawSat() {
    //Draws Sat and sets its position 
    GLfloat scaling = 2.2;
    glPushMatrix();
    glColor3f(.9, .1, 0);
    glRotatef(Sata, 0, 1, 0);
    glTranslatef(Satd * au / scaling, 0.0, 0.0);
    GLUquadricObj* Sat;
    Sat = gluNewQuadric();
    gluQuadricNormals(Sat, GL_TRUE);
    gluSphere(Sat, Satf * defPlanetEf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Satd * au / scaling) - .05, (Satd * au / scaling) +
        .05, 100, 100);
    glPopMatrix();
}

/**
 * Уран
 */
void DrawUrn() {
    //Draws Urn and sets its position 
    GLfloat scaling = 3.45;
    glPushMatrix();
    glColor3f(0, .4, 1.0);
    glRotatef(Urna, 0, 1, 0);
    glTranslatef(Urnd * au / scaling, 0.0, 0.0);
    GLUquadricObj* Urn;
    Urn = gluNewQuadric();
    gluQuadricNormals(Urn, GL_TRUE);
    gluSphere(Urn, Urnf * defPlanetEf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Urnd * au / scaling) - .05, (Urnd * au / scaling) +
        .05, 100, 100);
    glPopMatrix();

}

/**
 * Нептун
 */
void DrawNep() {
    GLfloat scaling = 4.2;
    glPushMatrix();
    glColor3f(0, 0, 1);
    glRotatef(Nepa, 0, 1, 0);
    glTranslatef(Nepd * au / scaling, 0.0, 0.0);
    GLUquadricObj* Nep;
    Nep = gluNewQuadric();
    gluQuadricNormals(Nep, GL_TRUE);
    gluSphere(Nep, Nepf * defPlanetEf, 20, 20);
    glPopMatrix();
    //орбита
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* orbit;
    orbit = gluNewQuadric();
    gluDisk(orbit, (Nepd * au / scaling) - .05, (Nepd * au / scaling) + .05, 100, 100);
    glPopMatrix();

}

/**
 * Свет на всех планетах (источник -- мат. центр)
 */
void setLight() {
    //Diffuse color 
    GLfloat LightDiffuse[] = { 1.0f, 1.0f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiffuse);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    GLfloat position0[] = { 0, 3, 0, 1 };
    GLfloat position1[] = { 0, -3, 0, 1 };
    GLfloat position2[] = { 0, 0, -3, 1 };
    GLfloat position3[] = { 0, 0, 3, 1 };
    GLfloat position4[] = { 3, 0, 0, 1 };
    GLfloat position5[] = { -3, 0, 0, 1 };
    //расстановка по позициям
    glLightfv(GL_LIGHT0, GL_POSITION, position0);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);
    glLightfv(GL_LIGHT3, GL_POSITION, position3);
    glLightfv(GL_LIGHT4, GL_POSITION, position4);
    glLightfv(GL_LIGHT5, GL_POSITION, position5);
    glEnable(GL_LIGHTING);
}
/* скорость вращения (при изменении пропорции сохраняются) */
GLfloat speed = 1.0;
GLfloat MAX = 15.0;
GLfloat MIN = 0.1;

void finalRENDER(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawdefPlanetE();
    DrawMerc();
    DrawVen();
    DrawMars();
    DrawJup();
    DrawSat();
    DrawUrn();
    DrawNep();
    DrawSun();
    // свет
    setLight();

    // Условно-пропорциональная скорость зависит от Земли
    Merca = fmod((Merca + speed * (defPlanetEv / Mercv)), 360);
    Vena = fmod((Vena + speed * (defPlanetEv / Venv)), 360);
    defPlanetEa = fmod((defPlanetEa + speed * (defPlanetEv / defPlanetEv)), 360);
    Marsa = fmod((Marsa + speed * (defPlanetEv / Marsv)), 360);
    Jupa = fmod((Jupa + speed * (defPlanetEv / Jupv)), 360);
    Sata = fmod((Sata + speed * (defPlanetEv / Satv)), 360);
    Urna = fmod((Urna + speed * (defPlanetEv / Urnv)), 360);
    Nepa = fmod((Nepa + speed * (defPlanetEv / Nepv)), 360);
    glutSwapBuffers();
    glutPostRedisplay();
}
/* скорость вращения (при изменении пропорции сохраняются) */

/*
 j>понизить скорость вращения
 k>повысить скорость вращения
 Раскладка только на английском :)
 */
void speedKeys(unsigned char key, int x, int y) {
    if (key == 'k' && speed <= MAX) {
        speed += .1;
    }
    else if (key == 'j' && speed >= MIN) {
        speed -= .1;
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    glutCreateWindow("solar");

    init();
    glutDisplayFunc(finalRENDER);
    glutKeyboardFunc(speedKeys);
    glutMainLoop();
}