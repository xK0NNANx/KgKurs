#include "prism.h"
#include "Render.h"
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include "GUItextRectangle.h"

class point {
	
	double x, y, z;
};

void PrintNormalVector(double* point1, double* point2, double* point3, float N_x, float N_y, float N_z) {
	double center[] = { (point1[0] + point2[0] + point3[0]) / 3,
						(point1[1] + point2[1] + point3[1]) / 3,
						(point1[2] + point2[2] + point3[2]) / 3 };
	double N_end[] = { center[0] + N_x,
						center[1] + N_y,
						center[2] + N_z };

	bool b_light = glIsEnabled(GL_LIGHTING);
	if (b_light)
		glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex3dv(center);
	glVertex3dv(N_end);
	glEnd();

	if (b_light)
		glEnable(GL_LIGHTING);
}

double* CountNormal(double A[], double B[], double C[]) {
	double BA[3] = { A[0] - B[0],A[1] - B[1],A[2] - B[2]};
	double BC[3] = { C[0] - B[0],C[1] - B[1],C[2] - B[2]};

	double N[3] = { BA[1] * BC[2] - BA[2] * BC[1],
	-BA[0] * BC[2] + BA[2] * BC[0],
	 BA[0] * BC[1] - BA[1] * BC[0]};

	double l = sqrt(N[0] * N[0] + N[1] * N[1] + N[2] * N[2]);
	N[0] /= l;
	N[1] /= l;
	N[2] /= l;
	return N;
}

void wall(int seed) {
	std::mt19937 gen(seed);

	double point1[]{ 1,2,0 };
	double point2[]{ 6,5,0 };
	double point3[]{ 8,-2,0 };
	double point4[]{ 0,-1,0 };
	double point5[]{ -2,-8,0 };
	double point6[]{ -4,-3,0 };
	double point7[]{ -1,0,0 };
	double point8[]{ -5,7,0 };

	double point1up[]{ 1,2,1.5 };
	double point2up[]{ 6,5,1.5 };
	double point3up[]{ 8,-2,1.5 };
	double point4up[]{ 0,-1,1.5 };
	double point5up[]{ -2,-8,1.5 };
	double point6up[]{ -4,-3,1.5 };
	double point7up[]{ -1,0,1.5 };
	double point8up[]{ -5,7,1.5 };

	std::uniform_real_distribution<double> r(0, 1);

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	double* normal = CountNormal(point1, point2, point2up);
	glNormal3dv(normal);
	glVertex3dv(point1);
	glVertex3dv(point2);
	glVertex3dv(point2up);
	glVertex3dv(point1up);
	glEnd();

	//glBegin(GL_QUADS);
	//glColor3d(r(gen), r(gen), r(gen));
	//glVertex3dv(point2);
	//glVertex3dv(point3);
	//glVertex3dv(point3up);
	//glVertex3dv(point2up);
	//glEnd();

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	normal = CountNormal(point3, point4, point4up);
	glNormal3dv(normal);
	glVertex3dv(point3);
	glVertex3dv(point4);
	glVertex3dv(point4up);
	glVertex3dv(point3up);
	glEnd();

	glBegin(GL_QUADS);
	normal = CountNormal(point4, point5, point5up);
	glNormal3dv(normal);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(point4);
	glVertex3dv(point5);
	glVertex3dv(point5up);
	glVertex3dv(point4up);
	glEnd();

	/*glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(point5);
	glVertex3dv(point6);
	glVertex3dv(point6up);
	glVertex3dv(point5up);
	glEnd();*/

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	normal = CountNormal(point6, point7, point7up);
	glNormal3dv(normal);
	glVertex3dv(point6);
	glVertex3dv(point7);
	glVertex3dv(point7up);
	glVertex3dv(point6up);
	glEnd();

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	normal = CountNormal(point7, point8, point8up);
	glNormal3dv(normal);
	glVertex3dv(point7);
	glVertex3dv(point8);
	glVertex3dv(point8up);
	glVertex3dv(point7up);
	glEnd();

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	normal = CountNormal(point8, point1, point1up);
	glNormal3dv(normal);
	glVertex3dv(point8);
	glVertex3dv(point1);
	glVertex3dv(point1up);
	glVertex3dv(point8up);
	glEnd();



}

void prism(int seed, float high) {
	double point1[]{ 1,2,high };
	double point2[]{ 6,5,high };
	double point3[]{ 8,-2,high };
	double point4[]{ 0,-1,high };
	double point5[]{ -2,-8,high };
	double point6[]{ -4,-3,high };
	double point7[]{ -1,0,high };
	double point8[]{ -5,7,high };

	std::mt19937 gen(seed);

	std::uniform_real_distribution<double> r(0, 1);
	//glBegin(GL_QUADS);
	//	glColor3d(r(gen), r(gen), r(gen));
	//	glVertex3dv(point1);
	//	glVertex3dv(point2);
	//	glVertex3dv(point3);
	//	glVertex3dv(point4);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//	glColor3d(r(gen), r(gen), r(gen));
	//	glVertex3dv(point1);
	//	glVertex3dv(point4);
	//	glVertex3dv(point3);
	//glEnd();

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	glVertex3dv(point1);
	glVertex3dv(point8);
	glVertex3dv(point7);
	glVertex3dv(point4);

	glEnd();

	glBegin(GL_QUADS);
	glColor3d(r(gen), r(gen), r(gen));
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	glVertex3dv(point7);
	glVertex3dv(point4);
	glVertex3dv(point5);
	glVertex3dv(point6);

	glEnd();

}

void DrawHalfCircle40point(float high)
{
	glBegin(GL_TRIANGLE_FAN);
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	double seed = 10;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3f(0, 0, high);
	int number = 20;
	float radius = sqrt(29) / 2;
	float pi = 3.14159;
	for (int i = 0; i <= number; i++) {
		double point1[] = { radius * cosf(i * pi / number), radius * sinf(i * pi / number), high };
		glVertex3dv(point1);
	}
	glEnd();
}

void DrawHalfWallCircle40point(double seed = 0) {
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);
	int number = 20;
	double* point1time = 0;
	double* point2time = 0;
	float radius = sqrt(29) / 2;
	float pi = 3.14159;
	glBegin(GL_TRIANGLE_STRIP);
	glColor3d(r(gen), r(gen), r(gen));
	for (int i = 0; i <= number; i++) {
		double angle = i * pi / number;
		double x = radius * cos(angle);
		double y = radius * sin(angle);

		double point1[] = { x, y, 0 };
		double point2[] = { x, y, 1.5 };

		double normal[] = { x, y, 0 };
		double length = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
		if (length > 0) {
			normal[0] /= length;
			normal[1] /= length;
			normal[2] /= length;
		}

		glNormal3dv(normal);
		glVertex3dv(point1);
		glVertex3dv(point2);
	}
	glEnd();
}

void DrawHalfCircle50point(float high) {
	double seed = 10;
	double* p = &seed;
	float pi = 3.14159;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);
	glBegin(GL_TRIANGLE_FAN);
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	glVertex3d(1, 2, high);
	glColor3d(r(gen), r(gen), r(gen));
	int number = 15000;
	float radius = 4.314591809121557;
	for (int i = 0; i <= number; i++) {
		double c = cos(i * 2 * pi / number);
		double s = sin(i * 2 * pi / number);
		if ((radius * c + 9.227272727272727) <= 8 && radius * s + 2.1363636363636362 <= 5 && radius * s + 2.1363636363636362 >= 1) {
			double point1[] = { radius * c + 9.227272727272727, radius * s + 2.1363636363636362, high };
			glVertex3dv(point1);
			p = point1;
		}
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	glVertex3d(0, -1, high);
	glColor3d(r(gen), r(gen), r(gen));
	for (int i = 0; i <= number; i++) {
		double c = cos(i * 2 * pi / number);
		double s = sin(i * 2 * pi / number);
		if ((radius * c + 9.227272727272727) <= 8 && radius * s + 2.1363636363636362 <= 1 && radius * s + 2.1363636363636362 >= -2) {
			double point1[] = { radius * c + 9.227272727272727, radius * s + 2.1363636363636362, high };
			glVertex3dv(point1);
		}
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	if (high == 0) {
		glNormal3d(0, 0, -1);
	}
	else {
		glNormal3d(0, 0, 1);
	}
	glColor3d(r(gen), r(gen), r(gen));
	glVertex3dv(p);
	glVertex3d(0, -1, high);
	glVertex3d(1, 2, high);
	glEnd();
}

void DrawHalfCircleWall50point(double seed = 0) {
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);
	int number = 15000;
	float radius = 4.314591809121557;
	float pi = 3.14159;
	glBegin(GL_TRIANGLE_STRIP);
	glColor3d(r(gen), r(gen), r(gen));
	for (int i = 0; i <= number; i++) {
		double angle = i * 2 * pi / number;
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		double world_x = x + 9.227272727272727;  
		double world_y = y + 2.1363636363636362;
		if (world_x <= 8 && world_y <= 5) {
			double point1[] = { world_x, world_y, 0 };
			double point2[] = { world_x, world_y, 1.5 };

			double nx = x;
			double ny = y;
			double nz = 0;

			
			double length = sqrt(nx * nx + ny * ny + nz * nz);
			if (length > 0) {
				nx /= length * -1;
				ny /= length * -1;
				nz /= length * -1;
			}

			glNormal3d(nx, ny, nz);
			glVertex3dv(point1);
			glVertex3dv(point2);
		}
	}
	glEnd();
}

void PrintPrism() {
	double seed = 10;
	float pi = 3.14159;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> r(0, 1);

	prism(0, 0);
	wall(10);
	//glPushMatrix();
	//prism(1, 1.5);
	//glPopMatrix();

	glPushMatrix();
	glTranslated(-3, -5.5, 0);
	glRotated(111.80140948635182, 0, 0, 1);
	DrawHalfCircle40point(0);
	DrawHalfWallCircle40point();
	//DrawHalfCircle40point(1.5);
	glPopMatrix();

	glPushMatrix();
	DrawHalfCircle50point(0);
	//DrawHalfCircle50point(1.5);
	glPopMatrix();
	DrawHalfCircleWall50point();
	glPopMatrix();
}