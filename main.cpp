#include <iostream>
#include "vector.h"
#include "colorfig.h"
#include "group.h"
#include "GL/glut.h"
#include <ctime>
#include "random.h"
#include <vector>
#include <conio.h>
using namespace std;
const float v = 1;
Car static car2({-95,65});
void door(){
    Rec static doors({-75,-80},{-115,-80.5},{-75,-80.5},{-75,-79.5},{-115,-79.5},1.0,0.0,0.0);
    float static theta=0;
    doors.draw();
    if (theta <90 ) {
        doors.rotate(-2);
        theta+=2;
    }
}
void random1() {
    srand(time(NULL));
    int static carPool=rand() % 10;
    Vec v0;
    //  int static carPool =
//    double static width = 10, height = 20, owidth= 10;
//    float static A = 50;
    int static c[10] = {rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3, rand() % 3};
    int static b[10] = {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2};
    for (int i = 0; i < 10; i++) {
        if (i != carPool) {
            if (b[i] == 1) {
                switch (c[i]) {
                    case 0: //Bling
                        v0 = randomPool(i);
                        drawBling(v0);
                        break;

                    case 1: //spaceship
                        v0 = randomPool(i);
                        drawSpace(v0);
                        break;

                    case 2: //UFO
                        v0 = randomPool(i);
                        drawUFO(v0);
                        break;
                }
            }
        }
    }
    int static a =carPool;
    int static flag = 0;
    int static flag1=0;
    Vec dis = randomPool(a);
    const float angle = 2;
    Vec static vec = Vec(0, 0);
    Car static car({-100,-85});
    if (flag1==0){
        car.CarR(90);
        flag1=1;
    }
    static vector<Vec> points;
    points.push_back(car.getAnchor());
    vector<Vec>:: iterator it;
    for (it=points.begin();it!=points.end();it++){
        glPointSize(3);

        glColor3f((float)rand()/RAND_MAX/2+0.5,(float)rand()/RAND_MAX/2+0.5,(float)rand()/RAND_MAX/2+0.5);
        glBegin(GL_POINTS);
        glVertex3f((*it).getX(),(*it).getY(),0.0);
        glEnd();
    }
    car.CarD();




    if (car.getAnchor().getX() == -100 && car.getAnchor().getY() <= -50) {
        vec = Vec(0, 1);
    } else if (car.getAnchor().getX() <= -74 && flag == 0) {
        vec = (Vec(car.getAnchor().getX() + 75.0, car.getAnchor().getY() + 50) >> angle) -
              Vec(car.getAnchor().getX() + 75.0, car.getAnchor().getY() + 50);
        car.CarR(-angle * v);
    } else if (a < 5) {
        if (car.getAnchor().getX() < dis.getX() + 20 && flag == 0) {
            vec = Vec(1, 0);
        } else if (car.getAnchor().getX() - 0.01 >= dis.getX()) {
            flag = 1;
            float static y = car.getAnchor().getY();
            vec = (Vec(car.getAnchor().getX() - dis.getX() - 20, car.getAnchor().getY() - y + 20) << angle) -
                  Vec(car.getAnchor().getX() - dis.getX() - 20, car.getAnchor().getY() - y + 20);
            car.CarR(angle * v);
        } else if (car.getAnchor().getY() >= -65) {
            vec = Vec(0, -1);
        } else { vec = {0, 0}; }
    } else {
        if (car.getAnchor().getX() <= 65 && flag == 0) {
            vec = {1, 0};
        } else {
            if (car.getAnchor().getX() >= 65) {
                flag = 1;
                vec = (Vec(car.getAnchor().getX() - 65.0, car.getAnchor().getY()) << angle) -
                      Vec(car.getAnchor().getX() - 65.0, car.getAnchor().getY());
                car.CarR(angle * v);
            } else {
                if (car.getAnchor().getX() > dis.getX() - 20 && flag == 1) {
                    vec = Vec(-1, 0);
                } else if (car.getAnchor().getX() +0.001 <= dis.getX()) {
                    flag = 2;
                    float static y = car.getAnchor().getY();
                    vec = (Vec(car.getAnchor().getX() - dis.getX() + 20, car.getAnchor().getY() - y - 20) << angle) -
                          Vec(car.getAnchor().getX() - dis.getX() + 20, car.getAnchor().getY() - y - 20);
                    car.CarR(angle * v);
                } else if (car.getAnchor().getY() <= 65) {
                    vec = Vec(0, 1);
                } else { vec = {0, 0}; }
            }
        }
    }
    int static ii=0;
    ii+=2;
    if (ii>90)
    car.CarM(vec);

}




void TimeStep(int n)
{
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}

void drawScene()
{
    //black
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-120.0f, 80.0f);glVertex2f(120.0f, 80.0f);glVertex2f(-75.0f, -80.0f);glVertex2f(120.0f, -80.0f);
    glVertex2f(-120.0f, -80.0f);glVertex2f(-120.0f, 80.0f);glVertex2f(120.0f, -80.0f);glVertex2f(120.0f, 80.0f);
    glLineWidth(3);
    //up
    glVertex2f(-15.0f, 50.0f);glVertex2f(-15.0f, 80.0f);glVertex2f(15.0f, 50.0f);glVertex2f(15.0f, 80.0f);
    glVertex2f(-45.0f, 50.0f);glVertex2f(-45.0f, 80.0f);glVertex2f(45.0f, 50.0f);glVertex2f(45.0f, 80.0f);
    glVertex2f(-75.0f, 50.0f);glVertex2f(-75.0f, 80.0f);glVertex2f(75.0f, 50.0f);glVertex2f(75.0f, 80.0f);
    //down
    glVertex2f(-15.0f, -50.0f);glVertex2f(-15.0f, -80.0f);glVertex2f(15.0f, -50.0f);glVertex2f(15.0f, -80.0f);
    glVertex2f(-45.0f, -50.0f);glVertex2f(-45.0f, -80.0f);glVertex2f(45.0f, -50.0f);glVertex2f(45.0f, -80.0f);
    glVertex2f(-75.0f, -50.0f);glVertex2f(-75.0f, -80.0f);glVertex2f(75.0f, -50.0f);glVertex2f(75.0f, -80.0f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-65.0f, 7.0f);glVertex2f(-65.0f, -7.0f);glVertex2f(65.0f, -7.0f);glVertex2f(65.0f, 7.0f);
    glEnd();
}

void ChangeSize(int w, int h)
{
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho (-100.0f, 100.0f, -100.0f*h/w, 100.0f*h/w, -100.0f, 100.0f);
    else
        glOrtho (-100.0f*w/h, 100.0f*w/h, -100.0f, 100.0f, -100.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void processNormalKeys(unsigned char key, int x, int y)
{

    if (key == 27)  //按ESC退出
        exit(0);
}

void processSpecialKeys(int key, int x, int y)
{
    float static A2 = 10;
    Vec static dir2 = {1, 1};
    switch (key) {
        //up
        case GLUT_KEY_UP:
            dir2 = {0, 2};
            car2.CarM(dir2);
            cout << "up" << endl;
            break;
            //left
        case GLUT_KEY_LEFT:
            dir2 = {-2,0};
            car2.CarM(dir2);
            break;
            //right
        case GLUT_KEY_RIGHT:
            dir2 = {2,0};
            car2.CarM(dir2);
            break;
            // down
        case GLUT_KEY_DOWN:
            dir2 = {0,-1};
            car2.CarM(dir2);
            break;

        case GLUT_KEY_PAGE_UP:
            car2.CarR(A2);
            break;
        case GLUT_KEY_PAGE_DOWN:
            car2.CarR(-A2);
            break;
        default:
            break;
    }
}

void glDraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    /*清楚屏幕和深度缓存。 */
//    glLoadIdentity();    /*重置当前的模型观察矩阵。 */
    door();
    drawScene();
    random1();

//    Vec static dir = {1,1};
//    float static A = 10;
//    Car static car1({0,0});
//    car1.CarM(dir);
//    car1.CarR(A);
//    car1.CarD();

    car2.CarD();
    glutSwapBuffers();
    glFlush();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB|GLUT_DOUBLE);    //使用双缓存技术
    glutInitWindowSize(2000,1500);    //调整窗口大小
    glutInitWindowPosition(300,150);    //调整窗口位置
    glutCreateWindow("parking lot");
    glClearColor(1.0, 1.0, 1.0, 0.0);   //设置窗口清除色为白色
    glClear(GL_COLOR_BUFFER_BIT);
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(glDraw);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutTimerFunc(25,TimeStep,0); //定时器
    glutMainLoop();
}
