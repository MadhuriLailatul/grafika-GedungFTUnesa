#include <GL/glut.h>

void drawRect(int x, int y, int width, int height, int r, int g, int b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);

    // Bangunan Utama 
    drawRect(-90, -60, 180, 120, 245, 222, 178);

    // Lantai hijau 
    for (int i = 0; i < 6; i++) {
        drawRect(-90, -55 + i * 20, 180, 5, 46, 204, 125);
    }

    // Jendela 
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            drawRect(-85 + j * 24, -50 + i * 20, 18, 10, 230, 230, 230);
        }
    }

    // tiang papan tengah
    drawRect(-40, -60, 80, 60, 245, 222, 178);
    drawRect(-35, -60, 70, 55, 230, 230, 230);

    // Papan tengah
    drawRect(-45, 0, 90, 10, 245, 222, 178);

    // Pintu 
    drawRect(-15, -45, 30, 30, 245, 222, 178);
    drawLine(0, -45, 0, -15, 0, 0, 0);

    // Engsel pintu
    drawRect(-5, -30, 2, 2, 0, 0, 0);
    drawRect(3, -30, 2, 2, 0, 0, 0);

    // Tangga 
    for (int i = 0; i < 5; i++) {
        drawRect(-20 - i * 5, -45 - i * 5, 40 + i * 10, 5, 46, 204, 125);
    }

    // Kotak hijau di atas balok
    drawRect(-35, 10, 70, 30, 46, 204, 125);

    // Garis abu-abu dari balok ke pintu
    drawLine(-35, -5, -15, -15, 102, 102, 102);
    drawLine(35, -5, 15, -15, 102, 102, 102);

    // Atap di atas bangunan
    drawRect(-90, 55, 180, 10, 245, 222, 178);

    // Atap
    for (int i = 0; i < 8; i++) {
        drawRect(-85 + i * 22, 45, 5, 10, 245, 222, 178);
    }

    glFlush();  
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);  
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Gedung FT Unesa dari sisi depan");
    init();
    glutDisplayFunc(display);  
    glutMainLoop();  
    return 0;
}