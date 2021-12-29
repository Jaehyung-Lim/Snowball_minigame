#pragma once
#pragma comment(lib,"winmm.lib")
#include "bmpfuncs.h"
#include "ObjParser.h"
#include <gl/glut.h>
#include <GL/glext.h>
#include <gl/freeglut.h>
#include <stdio.h.>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <mmsystem.h>

#define SOUND_FILE_NAME_GET_COIN "sound/DM-CGS-45.wav"
#define SOUND_FILE_NAME_GET_MAGNET "sound/DM-CGS-26.wav"
#define SOUND_FILE_NAME_BOMB "sound/DM-CGS-10.wav"
#define SOUND_FILE_NAME_HEART "sound/DM-CGS-07.wav"
#define SOUND_FILE_NAME_CRASH "sound/crash.wav"
#define SOUND_FILE_NAME_WIN "sound/win.wav"

#define PI 3.141592653589
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600
double Cam_radius = 13 * sqrt(3);
double theta = 80, pi = 270;
double BallAngle = 0;
double cam[3] = { Cam_radius * sin(theta * PI / 180) * sin(pi * PI / 180),Cam_radius * cos(theta * PI / 180),
Cam_radius * sin(theta * PI / 180) * cos(pi * PI / 180) };//카메라의 좌표


float floorSize = 200;
int floorSize_int = 200; 
//double ball[3] = { -floorSize+10,0,-floorSize+10 };//카메라가 보는 물체의 좌표
double ball[3] = { 0,0,0 };//카메라가 보는 물체의 좌표
double ball_eye[3] = { 0,0,0 };
double up = 1;	 //카메라의 방향
double size = 3;//눈덩이의 크기 
double detect = size;
//시작 크기는 3, 최소: 1, 최대 10: 템 먹을 때마다 0.5 증가
double spin_x = 360;
double spin_z = 360;
double spin_coin = 0;
double spin_magnet = 0;

bool jump_state = false;
bool jump_up = false;
bool jump_down = false;

bool front_press = false;
bool back_press = false;
bool right_press = false;
bool left_press = false;

double coin_x[15] = { -180, -150, -120, -50, -10, 10, 50, 120, 150, 180, 143,112,-19, -30,87};
double coin_y[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
double coin_z[15] = { -182, -150, -50, -40, 30, 45, 98, 119, 150 , 180, 87, -30, 0, -10, 160 };
double MAG_x[5] = { 20,143,-118,63,-47 }, MAG_z[5] = {20,-87,129,36,-12};
double MAG_y[5] = { 3,3,3,3,3 };
double bomb_x[10] = {31,89,115,-65,-142,-40,175,-153,104,193};
double bomb_z[10] = { 70,-71,116,-105,-136,153,75,-8,93,57 };
double bomb_y[10] = { 3,3,3,3,3,3,3,3,3,3 };
double heart_x[3] = {117, -169, 86};
double heart_y[3] = { 3,3,3 };
double heart_z[3] = {-35,-132, 100 };

bool rnd_coin[15];
bool rnd_mag[5]; 
bool rnd_bomb[10];
bool rnd_heart[3];
bool mag_effect = false;
int mag_timer = 0;
//충돌 발생시에 rnd 값이 true로 바뀌고, 이에 해당하는 것은 이제 못 먹음.

int coin_cnt = 15;
int coin_get = 0;
int tick = 0;
int score = 0;
int view_point = 3;//3인칭 시점
int Life = 3;


bool crash_wall = false;
bool game_over = false;
bool start_display = true; //맨 처음엔 얘가 true, 나머지는 모두 false
bool how_to_play = false;
double start_angle = 0;
bool game_win = false;

int color = 1; //1,2,3  

double velocity = 0.15;

GLUquadricObj* qobj = gluNewQuadric();
GLUquadricObj* qobj1 = gluNewQuadric();
GLuint textName[6]; // cube
GLuint textWall[4]; //wall
GLuint* textBall = new GLuint();	//sphere
GLuint* textFloor = new GLuint();	//floor
GLuint* textWin = new GLuint();	//floor
GLuint* textSky = new GLuint();		//sky
GLuint textureCoin;
GLuint textureMagnet;
GLuint textureMountain;
GLuint textureBomb;
GLuint textureCrack;
GLuint textureCrashed;
GLuint textureHeart;
GLuint textureTrophy;
GLuint textureIcewall;
GLuint textureDom;

ObjParser* coin;
ObjParser* magnet;
ObjParser* mountain;
ObjParser* bomb;
ObjParser* crack;
ObjParser* crashed;
ObjParser* heart;
ObjParser* trophy;
ObjParser* icewall;
ObjParser* dom;

void printInstruction();
/*텍스쳐 맵핑*/
void sphereTextureMapping();
void floorTextureMapping();
void coinTextureMapping();
void magnetTextureMapping();
void mountainTextureMapping();
void bombTextureMapping();
void crackTextureMapping();
void crashedTextureMapping();
void heartTextureMapping();
void trophyTextureMapping();
void icewallTextureMapping();
void domTextureMapping();
/*init*/
void init(void);

void color_menu(int);

/*draw*/
void draw_floor();	//바닥, 벽, 천장
void draw_axis();
void draw_ball();	//공의 움직임도 모두 포함
void draw_item();
void draw_map();
void draw_string(void*, const char*, int, int);
void draw_miniball(int,int);
void draw_COIN_with_texture(ObjParser*);
void draw_MAGNET_with_texture(ObjParser*);
void draw_ice_mountain_with_texture(ObjParser* );
void draw_bomb_with_texture(ObjParser*);
void draw_crack_with_texture(ObjParser*);
void draw_crashed_with_texture(ObjParser*);
void draw_heart_with_texture(ObjParser*);
void draw_trophy_with_texture(ObjParser*);
void draw_icewall_with_texture(ObjParser*);
void draw_dom_with_texture(ObjParser*);
void draw(void);
void draw_start();
void draw_how_to_play();
void draw_end();
void draw_win();
void draw_disk();
void draw_time();
void draw_coin_magnet_bomb();
void draw_bomb();
void draw_mountain_wall();

/*resize*/
void resize(int, int);

/*키보드*/
void special_keyboard(int, int, int);
void keyboard_p(unsigned char, int, int);
void keyboard_r(unsigned char, int, int);
void move();

void mouseWheel(int buotton, int dir, int x, int y);
void main_menu(int option);
void idle();

void get_resource(const char*);
double radian(double x);

/*마우스*/
void mouse(int, int, int, int);

clock_t start, end;
clock_t start_mag, end_mag; //자석 효과 실행시간
int main(int argc, char** argv) {
	//start = clock();
	int menu, submenu;						

	/*Window 초기화*/
	glutInit(&argc, argv);					//윈도우 초기화 함수
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);	//디스플레이 모드 설정
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);			
	glutInitWindowPosition(350, 200);		
	glutCreateWindow("12171841 임재형 ");	
	init();									

	coin = new ObjParser("game/BITCOIN.obj");
	magnet = new ObjParser("game/mag2.obj");
	mountain = new ObjParser("game/ice_mt.obj");
	bomb = new ObjParser("game/bomb_flat.obj");
	crack = new ObjParser("game/crack.obj");
	crashed = new ObjParser("game/crashed_snow.obj");
	heart = new ObjParser("game/heart.obj");
	trophy = new ObjParser("game/trophy.obj");
	icewall = new ObjParser("game/ice_wall.obj");
	dom = new ObjParser("game/dom.obj");

	submenu = glutCreateMenu(color_menu);
	glutAddMenuEntry("White snow ball", 1);
	glutAddMenuEntry("Red ball", 2);
	glutAddMenuEntry("Blue ball", 3);

	/*Poup menu 생성 및 추가*/
	glutCreateMenu(main_menu);
	glutAddMenuEntry("Quit", 1);
	glutAddSubMenu("Color",submenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	/* call back 함수 정의*/
	
	glutDisplayFunc(draw);			//draw() -> 실제 그리기 함수

	glutSpecialFunc(special_keyboard);		//방향키 입력
	glutReshapeFunc(resize);				//resize 함수
	glutMouseWheelFunc(mouseWheel);			//mouseWheel
	glutKeyboardFunc(keyboard_p);
	glutKeyboardUpFunc(keyboard_r);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	/*Looping 시작*/
	glutMainLoop();

	return 0;
}

/*init*/
void init(void) {

	glClearColor(1, 1, 1, 1.0f);

	printInstruction();

	gluQuadricTexture(qobj, GL_TRUE);

	sphereTextureMapping();
	floorTextureMapping();
	coinTextureMapping();
	magnetTextureMapping();
	mountainTextureMapping();
	bombTextureMapping();
	crackTextureMapping();
	crashedTextureMapping();
	heartTextureMapping();
	trophyTextureMapping();
	icewallTextureMapping();
	domTextureMapping();

	glDisable(GL_BLEND);
	glFrontFace(GL_CW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}
/*화면 설명*/
void printInstruction() {
	printf("w, s, a, d: 상, 하, 좌, 우\n");
	printf("[: zoom in\n]: zoom out\n");
	printf("마우스 휠: zoom in/out\n");
	printf("방향키: 시점 조절\n");
	printf("마우스 우클릭 메뉴: 게임 강제 종료 및 색 변경\n");
}

/*텍스쳐 매핑*/
const char* COLOR[3] = {"game/SNOW.bmp","game/red.bmp","game/blue.bmp" };
void sphereTextureMapping() {
	glGenTextures(1, textBall);
	uchar* img;
	int imgX, imgY, channels;

	glBindTexture(GL_TEXTURE_2D, *textBall);
	img = readImageData(COLOR[color-1], &imgX, &imgY, &channels);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgX, imgY, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}
void floorTextureMapping() {
	glGenTextures(1, textFloor);
	uchar* img;
	int imgX, imgY, channels;

	glBindTexture(GL_TEXTURE_2D, *textFloor);
	img = readImageData("game/ice.bmp", &imgX, &imgY, &channels);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgX, imgY, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glGenTextures(1, textSky);
	glBindTexture(GL_TEXTURE_2D, *textSky);
	img = readImageData("game/sky.bmp", &imgX, &imgY, &channels);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgX, imgY, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glGenTextures(4, textWall);
	for (int i = 0; i < 4; i++) {
		char buf[100];
		sprintf(buf, "game/wall%d.bmp", i);
		buf[strlen(buf)] = 0;
		glBindTexture(GL_TEXTURE_2D, textWall[i]);
		img = readImageData(buf, &imgX, &imgY, &channels);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, imgX, imgY, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}
}
void coinTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/BITCOIN.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureCoin);
	glBindTexture(GL_TEXTURE_2D, textureCoin);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, img);
}
void magnetTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/mag2.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureMagnet);
	glBindTexture(GL_TEXTURE_2D, textureMagnet);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, img);
}
void mountainTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/ice_tex.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureMountain);
	glBindTexture(GL_TEXTURE_2D, textureMountain);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, img);
}
void bombTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/bomb.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureBomb);
	glBindTexture(GL_TEXTURE_2D, textureBomb);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, img);
}
void crackTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/crack.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureCrack);
	glBindTexture(GL_TEXTURE_2D, textureCrack);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void crashedTextureMapping() {
	int imgWidth, imgHeight, channels;
	//uchar* img = readImageData("game/crashed_snow.bmp", &imgWidth, &imgHeight, &channels);
	uchar* img = readImageData(COLOR[color-1], &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureCrashed);
	glBindTexture(GL_TEXTURE_2D, textureCrashed);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void heartTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/heart.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureHeart);
	glBindTexture(GL_TEXTURE_2D, textureHeart);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void trophyTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/gold.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureTrophy);
	glBindTexture(GL_TEXTURE_2D, textureTrophy);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void icewallTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/ice_wall.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureIcewall);
	glBindTexture(GL_TEXTURE_2D, textureIcewall);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void domTextureMapping() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("game/dom.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &textureDom);
	glBindTexture(GL_TEXTURE_2D, textureDom);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

/*Display 콜백 함수 만들기*/
void draw_floor() {
	glFrontFace(GL_CW);
	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, *textFloor);
	glBegin(GL_QUADS);				//사각형 그리기 함수
	glTexCoord2f(0, 0); glVertex3f(-floorSize, 0, -floorSize);
	glTexCoord2f(0, 10); glVertex3f(-floorSize, 0, floorSize);
	glTexCoord2f(10, 10); glVertex3f(floorSize, 0, floorSize);
	glTexCoord2f(10, 0); glVertex3f(floorSize, 0, -floorSize);
	glEnd();
	glFlush();
} //바닥, 천장, 벽
void draw_axis() {
	glLineWidth(3); // 좌표축의 두께
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); // X축은 red
	glVertex3f(0, 0, 0); glVertex3f(4, 0, 0);

	glColor3f(0, 1, 0); // Y축은 green
	glVertex3f(0, 0, 0); glVertex3f(0, 4, 0);

	glColor3f(0, 0, 1); // Z축은 blue
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 4);
	glEnd();
	glLineWidth(1); // 두께 다시 환원
}
void draw_ball(){
	glPushMatrix();
	glTranslatef(0, -5 + size, 0); //땅이 y=-5에 있으니까, y좌표는 결국 -5 만큼 내리고 그 다음에 이 좌표를 설정해야함. 
	glTranslatef(ball[0], ball[1], ball[2]);
	glRotatef(BallAngle, 0, 1, 0);
	if (front_press) {
		glTranslatef(velocity, 0, 0);
		ball[0] += velocity * cos(radian(BallAngle));
		ball[2] -= velocity * sin(radian(BallAngle));
	}
	else if (back_press) {
		glTranslatef(-velocity, 0, 0);
		ball[0] -= velocity * cos(radian(BallAngle));
		ball[2] += velocity * sin(radian(BallAngle));
	}
	else if (left_press) {
		glTranslatef(0, 0, -velocity);
		ball[0] -= velocity * sin(radian(BallAngle));
		ball[2] -= velocity * cos(radian(BallAngle));
	}
	else if (right_press) {
		glTranslatef(0, 0, velocity);
		ball[0] += velocity * sin(radian(BallAngle));
		ball[2] += velocity * cos(radian(BallAngle));
	}
	glRotatef(spin_x, 0, 0, 1);
	glRotatef(spin_z, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, *textBall);
	gluSphere(qobj, size, 100, 100);
	glPopMatrix();

	if (ball[0] + size >= floorSize-2 || ball[0]-size <= -floorSize+2 || ball[2]+size >= floorSize-2 || ball[2]-size <= -floorSize+2) {
		PlaySound(TEXT(SOUND_FILE_NAME_CRASH), NULL, SND_ASYNC);
		game_over = true;
	}
} 
void draw_map() {
	glPushMatrix();
	glTranslatef(0, -5, 0);//y축으로 일단 5 내림-> 근데 사실상 계산시에는 바닥이 0임.
	draw_floor();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-15, 0);
	glScalef(250*sqrt(2), 250 * sqrt(2), 250 * sqrt(2));
	draw_dom_with_texture(dom);
	glPopMatrix();
}
void draw_string(void* font, const char* str, int x, int y) {
	glPushAttrib(GL_LIGHTING_BIT); //light에 관한 상태를 저장합니다.
	glDisable(GL_LIGHTING);//text에 생기는 그림자 효과를 지워줍니다
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0, 0, 0);
	glRasterPos3f(x, y, 0);
	for (unsigned int i = 0; i < strlen(str); i++) {
		glutBitmapCharacter(font, str[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}
void draw_coin_cnt() {
	char buf[50];
	sprintf(buf, "Remaining Coin: %d", coin_cnt);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -9.5, 7);

	sprintf(buf, "My Coin: %d", coin_get);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -9.5, 6);

	sprintf(buf, "SCORE: %d", score);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -9.5, 8);

	char life[10];
	int i;
	for (i = 0; i < Life; i++) life[i] = 'O';
	life[i] = 0;
	
	sprintf(buf, "LIFE: %s", life);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, 6, 6);

	sprintf(buf, "Velocity: %.2f", velocity);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -9.5, 5);

	sprintf(buf, "Ball size: %2.1f", size);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, 6, 8);

}
void draw_miniball(int x, int y) {
	glPushAttrib(GL_LIGHTING_BIT); //light에 관한 상태를 저장합니다.
	glDisable(GL_LIGHTING);//text에 생기는 그림자 효과를 지워줍니다.
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1, 1, 0);
	
	glutWireCube(10);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}
void draw_time() {
	char buf_time[30],time_bar[30], time_pic[20];
	int tmp_time = (end - start) / CLOCKS_PER_SEC;
	int mm = tmp_time / 60;
	int ss = tmp_time - mm;
	if (mm == 1) {//게임 제한 시간 1분
		game_over = true;
	}
	sprintf(buf_time, "Time:%d:%d", mm, ss);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf_time, -1, 9);

	if (mag_effect) {
		tmp_time = (end_mag - start_mag) / CLOCKS_PER_SEC;
		int mm = tmp_time / 60;
		int ss = tmp_time - mm;

		if (ss - tick == 1 || tick - ss == 59) {
			mag_timer--;	//시간초 감소
		}
		tick = ss;
		
		int i ;

		for (i = 0; i < mag_timer; i++) {
			time_bar[i] = 'O';
		}
		time_bar[mag_timer] = 0;
		sprintf(buf_time, "Magnet Time:%d", mag_timer);
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf_time, -9.5, -8);

		sprintf(time_pic, "Magnet Time:%s", time_bar);
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, time_pic, -9.5, -9);

		//if (ss >= mag_timer) mag_effect = false;
		if (mag_timer == 0) { 
			tick = 0;
			mag_effect = false; 
			detect = size;
		}
	}
}
void draw_COIN_with_texture(ObjParser* objParser){
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureCoin);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_MAGNET_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureMagnet);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_ice_mountain_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureMountain);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_bomb_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureBomb);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_crack_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureCrack);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_crashed_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureCrashed);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_heart_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureHeart);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_trophy_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureTrophy);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_icewall_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureIcewall);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
}
void draw_dom_with_texture(ObjParser* objParser) {
	glDisable(GL_BLEND);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, textureDom);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	//glEnable(GL_BLEND);
	glDisable(GL_CULL_FACE);
}
void draw_coin_magnet_bomb() {
	for (int i = 0; i < 15; i++) { //coin
		if (!rnd_coin[i]) {
			glPushMatrix();
			glTranslatef(coin_x[i], coin_y[i], coin_z[i]);
			glRotatef(90, 1, 0, 0);
			glRotatef(spin_coin, 0, 0, 1);
			draw_COIN_with_texture(coin);
			glPopMatrix();
		}
	}
	for (int i = 0; i < 5; i++) {  //magent
		if (!rnd_mag[i]) {
			glPushMatrix();
			glTranslatef(MAG_x[i], MAG_y[i], MAG_z[i]);
			glScalef(0.3, 0.3, 0.3);
			glRotatef(spin_magnet, 0, 1, 0);
			draw_MAGNET_with_texture(magnet);
			glPopMatrix();
		}
	}
	for (int i = 0; i < 10; i++) {
		if (!rnd_bomb[i]) {
			glPushMatrix();
			glTranslatef(bomb_x[i], bomb_y[i], bomb_z[i]);
			glScalef(3, 3, 3);
			draw_bomb_with_texture(bomb);
			glPopMatrix();
		}
	}
	for (int i = 0; i < 3; i++) {
		if (!rnd_heart[i]) {
			glPushMatrix();
			glTranslatef(heart_x[i], heart_y[i], heart_z[i]);
			glScalef(3, 3, 3);
			draw_heart_with_texture(heart);
			glPopMatrix();
		}
	}
	int i=0;
	if (front_press || right_press || left_press || back_press) {
		for (i = 0; i < 15; i++) {	
			if (!rnd_coin[i]) {//아직 있음
				double x = coin_x[i], y = coin_y[i], z = coin_z[i];
				double tmp = sqrt((ball[0] - x) * (ball[0] - x) + (ball[1] + detect - y) * (ball[1] + detect -y) + (ball[2] - z) * (ball[2] - z));
				if (tmp < detect + 1) {
					PlaySound(TEXT(SOUND_FILE_NAME_GET_COIN), NULL, SND_ASYNC);
					size += 0.2; //사이즈 커짐
					if (mag_effect) detect = 3 * size;
					else detect = size;
					rnd_coin[i] = true;
					coin_cnt--;
					coin_get++;
					score += 100;
					velocity += 0.03;
				}
			}
		}
		for (i = 0; i < 5; i++) {
			if (!rnd_mag[i]) {
				double x = MAG_x[i], y = MAG_y[i], z = MAG_z[i];
				double tmp = sqrt((ball[0] - x) * (ball[0] - x) + (ball[1] + detect - y) * (ball[1] + size - y) + (ball[2] - z) * (ball[2] - z));
				if (tmp < detect + 1) {
					PlaySound(TEXT(SOUND_FILE_NAME_GET_MAGNET), NULL, SND_ASYNC);
					if (!mag_effect) { //현재 자석효과가 활성화되지 않은 상태였을 때 
						detect = size * 3; //범위가 넓어지는 효과를 주게됨.
						mag_timer += 6;	//시간을 10초 증가시켜 
						start_mag = clock(); //시간초를 on
						mag_effect = true;//자석 효과를 켜줌
					}
					else {	//자석 효과가 커진 상태로 자석을 먹었을 경우
						mag_timer += 6;		//타이머만 증가시켜 
					}
					score += 50;
					rnd_mag[i] = true;	//해당 자석은 먹었다는 것을 표시
				}
			}
		}
		for (i = 0; i < 10; i++) {
			if (!rnd_bomb[i]) {//아직 있음
				double x = bomb_x[i], y = bomb_y[i], z = bomb_z[i];
				double tmp = sqrt((ball[0] - x) * (ball[0] - x) + (ball[1] + detect - y) * (ball[1] + size - y) + (ball[2] - z) * (ball[2] - z));
				if (tmp < size + 2) {
					PlaySound(TEXT(SOUND_FILE_NAME_BOMB), NULL, SND_ASYNC);
					size -= 0.2; //사이즈 커짐
					if (mag_effect)detect = 3 * size;
					else detect = size;
					rnd_bomb[i] = true;
					score -= 100;
					Life -= 1;
					velocity -= 0.01;
					if (Life == 0)game_over = true;
				}
			}
		}
		for (i = 0; i < 3; i++) {
			if (!rnd_heart[i]) {
				double x = heart_x[i], y = heart_y[i], z = heart_z[i];
				double tmp = sqrt((ball[0] - x) * (ball[0] - x) + (ball[1] + detect - y) * (ball[1] + size - y) + (ball[2] - z) * (ball[2] - z));
				if (tmp < detect + 2) {
					PlaySound(TEXT(SOUND_FILE_NAME_HEART), NULL, SND_ASYNC);
					rnd_heart[i] = true;
					score += 100;
					Life += 1;
				}
			}
		}
	}
	if (coin_get == 15) { 
		game_win = true; 
		PlaySound(TEXT(SOUND_FILE_NAME_WIN), NULL, SND_ASYNC);
	}
}
void draw_bomb() {
	for (int i = 0; i < 5; i++) {
		if (!rnd_bomb[i]) {
			glPushMatrix();
			glTranslatef(bomb_x[i], bomb_y[i], bomb_z[i]);
			glScalef(3, 3, 3);
			draw_bomb_with_texture(bomb);
			glPopMatrix();
		}
	}
	int i = 0;
	if (front_press || right_press || left_press || back_press) {
		for (i = 0; i < 5; i++) {
			if (!rnd_bomb[i]) {//아직 있음
				double x = bomb_x[i], y = bomb_y[i], z = bomb_z[i];
				double tmp = sqrt((ball[0] - x) * (ball[0] - x) + (ball[1] + detect - y) * (ball[1] + size - y) + (ball[2] - z) * (ball[2] - z));
				if (tmp < size + 2) {
					size -= 0.2; //사이즈 커짐
					detect = size;
					if (mag_effect)detect = 3 * size;
					rnd_bomb[i] = true;
					score -= 100;
					velocity -= 0.01;
					PlaySound(TEXT(SOUND_FILE_NAME_BOMB), NULL, SND_ASYNC);
				}
			}
		}
	}
}
void draw_mountain_wall() {

	for (int i = 1; i <= 5; i++) {
		glPushMatrix();
		glTranslatef(floorSize + 50, 0.5, -floorSize+80*i);
		glRotatef(90, 0, 1, 0);
		glScalef(35, 40+8* pow(-1,i), 50);
		draw_ice_mountain_with_texture(mountain);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-floorSize - 50, 0.5, -floorSize + 80 * i);
		glRotatef(90, 0, 1, 0);
		glScalef(40, 40 + 8 * pow(-1, i), 45);
		draw_ice_mountain_with_texture(mountain);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-floorSize + 80 * i, 0.5, floorSize + 50);
		glScalef(40, 40 + 10 * pow(-1, i), 35);
		draw_ice_mountain_with_texture(mountain);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-floorSize + 80 * i, 0.5, -floorSize - 50);
		glScalef(20, 30 + 5 * pow(-1, i), 35);
		draw_ice_mountain_with_texture(mountain);
		glPopMatrix();
	}
	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glTranslatef(-floorSize-10, 0.5, -160 + 81 * i);
		glRotatef(90, 0, 1, 0);
		glScalef(10, 10, 12);
		draw_icewall_with_texture(icewall);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(floorSize+10, 0.5, -160 + 81 * i);
		glRotatef(90, 0, 1, 0);
		glScalef(10, 10, 12);
		draw_icewall_with_texture(icewall);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-160 + 81 * i, 0.5, floorSize+10);
		glScalef(10, 10, 12);
		draw_icewall_with_texture(icewall);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-160 + 81 * i, 0.5, -floorSize-10);
		glScalef(10, 10, 12);
		draw_icewall_with_texture(icewall);
		glPopMatrix();
	}
	
	double pos_x[7] = {-105,111,-55, 165,1,78,-26}, pos_z[7] = {-122,85,138,-158,-8,30,53};
	double ang[7] = { 254,0,166,187,36,115,90 };
	for (int i = 0; i < 7; i++) {
		glPushMatrix();
		glTranslatef(pos_x[i], 0.5, pos_z[i]);
		glScalef(5+2*i, 25, 8+3*i);
		glRotatef(ang[i], 0, 1, 0);
		draw_crack_with_texture(crack);
		glPopMatrix();
	}
	//glutPostRedisplay();
}
void draw_start() {
	Cam_radius = 10;
	pi = 270;
	theta = 90;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (theta > 0 && theta <= 180)up = 1;
	if (theta > 180 && theta <= 360)up = -1;

	cam[0] = Cam_radius * sin(radian(theta)) * sin(radian(pi));
	cam[1] = Cam_radius * cos(radian(theta));
	cam[2] = Cam_radius * sin(radian(theta)) * cos(radian(pi));

	gluLookAt(cam[0] + ball[0], cam[1] + ball[1], cam[2] + ball[2], ball[0], ball[1], ball[2], 0, up, 0);


	glPushMatrix();
	glRotatef(start_angle, 0, 1, 0);
	draw_map();
	glPopMatrix();

	char buf[50];
	sprintf(buf, "Snowballing Adventure");
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -2, 5);

	sprintf(buf, "Start game!!!!!");
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -1, 0);

	sprintf(buf, "How to play?");
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buf, -1, -4);

	glRotatef(-270, 0, 1, 0);
	
	glPushAttrib(GL_LIGHTING_BIT); //light에 관한 상태를 저장합니다.
	glDisable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glPushMatrix();
	gluOrtho2D(-10, 10, -10, 10);
	glFrontFace(GL_CW);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);				//사각형 그리기 함수
		glVertex2f(-35.0f, 6.0f);
		glVertex2f(30.0f, 6.0f);
		glVertex2f(30.0f, -4.0f);
		glVertex2f(-35.0f, -4.0f);
	glEnd();
	glBegin(GL_QUADS);				//사각형 그리기 함수
	glVertex2f(-35.0f, -11.0f);
	glVertex2f(30.0f, -11.0f);
	glVertex2f(30.0f, -21.0f);
	glVertex2f(-35.0f, -21.0f);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glPopAttrib();


	glFlush();
	glutSwapBuffers();

}
void draw_how_to_play() {
	Cam_radius = 10;
	pi = 270;
	theta = 90;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (theta > 0 && theta <= 180)up = 1;
	if (theta > 180 && theta <= 360)up = -1;

	cam[0] = Cam_radius * sin(radian(theta)) * sin(radian(pi));
	cam[1] = Cam_radius * cos(radian(theta));
	cam[2] = Cam_radius * sin(radian(theta)) * cos(radian(pi));

	gluLookAt(cam[0] + ball[0], cam[1] + ball[1], cam[2] + ball[2], ball[0], ball[1], ball[2], 0, up, 0);


	glPushMatrix();
	glTranslatef(0, -5, 0);//y축으로 일단 5 내림-> 근데 사실상 계산시에는 바닥이 0임.
	glRotatef(start_angle, 0, 1, 0);
	draw_map();
	glPopMatrix();

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "HOW TO PLAY", -1, 5);

	char buf[50];

	sprintf(buf, " < keyboard >");
	draw_string(GLUT_BITMAP_HELVETICA_18, buf, 1, 3);

	sprintf(buf, " 'W':Forward 'S': Backward 'A': Left 'D': Right");
	draw_string(GLUT_BITMAP_HELVETICA_18, buf, 1, 2);

	sprintf(buf, " 'Space Bar': Jump");
	draw_string(GLUT_BITMAP_HELVETICA_18, buf, 1, 1);

	sprintf(buf, " [ , wheel up : Zoom in");
	draw_string(GLUT_BITMAP_HELVETICA_18, buf, 1, 0);

	sprintf(buf, " ] , wheel down : Zoom out");
	draw_string(GLUT_BITMAP_HELVETICA_18,buf, 1, -1);

	char tmp[100];
	
	draw_string(GLUT_BITMAP_HELVETICA_18, "< preview >", -9, 3);
	draw_string(GLUT_BITMAP_HELVETICA_18, "=>You have to go 'Goal In Area' with over score 2500.", -9, 2);
	draw_string(GLUT_BITMAP_HELVETICA_18, "=>If you  bump into a coin, you will get 100 points.",-9, 1);
	draw_string(GLUT_BITMAP_HELVETICA_18, "=>If you  bump into a magnet, your coin detectioning range", -9, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, "widens for 6 seconds each magnet.", -9, -1);
	draw_string(GLUT_BITMAP_HELVETICA_18, "=>Don't move to Bombs! Your will lose your life.", -9, -2);
	draw_string(GLUT_BITMAP_HELVETICA_18, "=>Avoid obstacles and complete your mission!", -9, -3);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Press G to start ", -1, -5);

	glFlush();
	glutSwapBuffers();
}
void draw_end() {
	Cam_radius = 10;
	pi = 270;
	theta = 90;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (theta > 0 && theta <= 180)up = 1;
	if (theta > 180 && theta <= 360)up = -1;

	cam[0] = Cam_radius * sin(radian(theta)) * sin(radian(pi));
	cam[1] = Cam_radius * cos(radian(theta));
	cam[2] = Cam_radius * sin(radian(theta)) * cos(radian(pi));
	ball[0] = 0, ball[1] = 3, ball[2] = 0;
	gluLookAt(cam[0] + ball[0], cam[1] + ball[1], cam[2] + ball[2], ball[0], ball[1], ball[2], 0, up, 0);

	glPushMatrix();
	glTranslatef(0, -5, 0);//y축으로 일단 5 내림-> 근데 사실상 계산시에는 바닥이 0임.
	glRotatef(start_angle, ball[0], ball[1], ball[2]);
	draw_map();
	draw_coin_magnet_bomb();
	draw_mountain_wall();
	glPopMatrix();

	glPushMatrix();
	glTranslated(ball[0], ball[1], ball[2]);
	glRotatef(2*start_angle, 0, 1, 0);
	glRotatef(60, 0, 0, 1);
	draw_crashed_with_texture(crashed);
	glPopMatrix();

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ">>>>Game Over<<<<", -2, 5);

	char tmp[100];
	sprintf(tmp, "Final Score: %d", score);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, tmp, -2, 3);

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Press R to restart ", -2, 1);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Press ESC to end the game.", -2, -2);

	glFlush();
	glutSwapBuffers();
}
void draw_win() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (theta > 0 && theta <= 180)up = 1;
	if (theta > 180 && theta <= 360)up = -1;

	cam[0] = Cam_radius * sin(radian(theta)) * sin(radian(pi));
	cam[1] = Cam_radius * cos(radian(theta));
	cam[2] = Cam_radius * sin(radian(theta)) * cos(radian(pi));

	gluLookAt(cam[0] ,cam[1], cam[2], 0, 0, 0, 0, up, 0);

	glPushMatrix();
	glTranslatef(0, -5, 0);//y축으로 일단 5 내림-> 근데 사실상 계산시에는 바닥이 0임.
	glRotatef(start_angle+60, 0, 1, 0);
	draw_map();
	glScalef(2.5, 2.5, 2.5);
	draw_trophy_with_texture(trophy);
	glPopMatrix();

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ">>>>Game Win<<<<", -2, 5);

	char tmp[100];

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Press R to restart ", -2, 1);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Press ESC to end the game.", -2, -2);

	glFlush();
	glutSwapBuffers();
}
void draw(void) {
	if (start_display) {
		draw_start();
		return;
	}
	else if (how_to_play) {
		draw_how_to_play();
		return;
	}
	else if (game_over) {
		draw_end();
		return;
	}
	else if (game_win) {
		draw_win();
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (theta > 0 && theta <= 180)up = 1;
	if (theta > 180 && theta <= 360)up = -1;

	cam[0] = Cam_radius * sin(radian(theta)) * sin(radian(pi));
	cam[1] = Cam_radius * cos(radian(theta));
	cam[2] = Cam_radius * sin(radian(theta)) * cos(radian(pi));

	gluLookAt(cam[0] + ball[0], cam[1] + ball[1], cam[2] + ball[2], ball[0], ball[1], ball[2], 0, up, 0);

	draw_time();
	draw_coin_cnt();

	draw_ball(); //motion 포함
	draw_map();
	glPushMatrix();
	glTranslatef(0, -5, 0);
	draw_coin_magnet_bomb();
	draw_mountain_wall();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

/*resize*/
void resize(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, (float)width / (float)height, 1, 500);
	//glOrtho(-15, 15, -15, 15, -15, 15);//육면체 형식의 가시부피를 설정 -> 중심은 0,0,0
	//glFrustum(-10, 10, -15, 15, 1, 500);

	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

/*키보드 입력 콜백 함수*/
void special_keyboard(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		pi += 5;
		if (pi >= 360)pi = 0;
		BallAngle += 5;
		if (BallAngle >= 360) BallAngle = 0;
	}
	else if (key == GLUT_KEY_RIGHT) {pi -= 5;
		if (pi < 0)pi = 355;
		
		BallAngle -= 5;
		if (BallAngle < 0) BallAngle = 355;
	}
	else if (key == GLUT_KEY_UP) {
		if(theta<100)theta += 5;
	}
	else if (key == GLUT_KEY_DOWN) {
		if(theta>35)theta -= 5;
	}
	glutPostRedisplay();
}
void keyboard_p(unsigned char key, int x, int y) {
	if (key == 'w') {//앞
		front_press = true;
	}
	else if (key == 'a') { //왼
		left_press = true;
	}
	else if (key == 'd') { //오른쪽
		right_press = true;	
	}
	else if (key == 's') {//뒤로 
		back_press = true;
	}
	else if (key == ' ') {
		if (!jump_state) {
			jump_state = true;
			jump_up = true;
		}
	}
	else if (key == ']') {//zoom in
		Cam_radius *= 0.9;
	}
	else if (key == '[') {//zoom out
		Cam_radius = Cam_radius * 10 / 9;
	}
	else if (key == '1') { 
		view_point = 1; 
	}
	else if (key == '3') { 
		view_point = 3; 
	}
	if (how_to_play && key == 'g') {
		how_to_play = false;
		Cam_radius = 13 * sqrt(3);
		pi = 270;
		theta = 80;
	}
	if (game_over || game_win) {
		if (key == 'r') {
			game_over = false;
			game_win = false;
			start_display = true;
			Cam_radius = 13 * sqrt(3);
			pi = 270;
			theta = 80;
			ball[0] = 0, ball[1] = 0, ball[2] = 0;
			BallAngle = 0;
			start = clock();
			for (int i = 0; i < 15; i++)rnd_coin[i] = false;
			for (int i = 0; i < 10; i++) rnd_bomb[i] = false;
			for (int i = 0; i < 5; i++) rnd_mag[i] = false;
			for (int i = 0; i < 3; i++) rnd_heart[i] = false;
			Life = 3;
			coin_get = 0;
			coin_cnt = 15;
			size = 3;
			detect = size;
			score = 0;
		}
		else if (key == 27) {
			printf("게임 종료\n");
			exit(0);
		}
	}
	glutPostRedisplay();
}
void keyboard_r(unsigned char key, int x, int y) {
	if (key == 'w') {//앞
		front_press = false;
	}
	else if (key == 'a') { //왼
		left_press = false;
	}
	else if (key == 'd') { //오른쪽
		right_press = false;
	}
	else if (key == 's') {//뒤로 
		back_press = false;
	}
}
/*마우스*/
void mouseWheel(int buotton, int dir, int x, int y) {
	if (dir > 0) { //가까워 지는 것
		Cam_radius *= 0.9;
	}
	else {
		Cam_radius = Cam_radius * 10 / 9;
	}
	cam[2] = Cam_radius * sin(theta * PI / 180) * cos(pi * PI / 180);
	cam[0] = Cam_radius * sin(theta * PI / 180) * sin(pi * PI / 180);
	cam[1] = Cam_radius * cos(theta * PI / 180);
	glutPostRedisplay();
}
void main_menu(int option) {
	if (option == 1) {
		printf("종료합니다!\n");
		exit(0);
	}
}
void color_menu(int option) {
	if (option == 1) {
		printf("white snow ball\n");
		color = 1;
	}
	else if (option == 2) {
		printf("red ball\n");
		color = 2;
	}
	else if (option == 3) {
		printf("blue ball\n");
		color = 3;
	}
	sphereTextureMapping();
	crashedTextureMapping();
	glutPostRedisplay();
}

/*idle*/
int cnt = 100;
void idle() {
	end = clock();
	if (mag_effect) {
		end_mag = clock();	//자석 시간 체크용
	}
	if (jump_state) {
		if (jump_up) {
			if (cnt > 0) {
				ball[1] += 0.1;
				cnt--;
				//glutPostRedisplay();
			}
			else if (cnt == 0) {
				cnt = 100;
				jump_up = false;
				jump_down = true;
			}
		}
		else if (jump_down) {
			if (cnt > 0) {
				ball[1] -= 0.1;
				cnt--;
				//glutPostRedisplay();
			}
			else if (cnt == 0) {
				cnt = 100;
				jump_state = false;
				jump_down = false;
			}
		}
	}
	spin_coin += 0.2;
	if (spin_coin > 360) spin_coin -= 360;
	spin_magnet += 0.2;
	if (spin_magnet > 360) spin_magnet -= 360;

	if (front_press) {
		spin_x -= 0.5;
		if (spin_x <= 0)spin_x += 360;
	}
	else if (back_press) {
		spin_x += 0.5;
		if (spin_x >= 360)spin_x -= 360;
	}
	else if (right_press) {
		spin_z += 0.5;
		if (spin_z >= 360)spin_z -= 360;
	}
	else if (left_press) {
		spin_z -= 0.5;
		if (spin_z <= 0)spin_z += 360;
	}

	if (start_display || how_to_play || game_over || game_win) {
		start_angle += 0.005;
		if (start_angle >= 360)start_angle -= 360;
	}
	glutPostRedisplay();
}
double radian(double x) {
	return x * PI / 180;
}
void mouse(int button, int state, int x, int y) {
	if (start_display) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			printf("x: %d, y: %d\n", x, y);

			/*시작 화면에서 게임 진행화면으로 넘어감*/
			if ((283 <= x && x <= 751) && (257 <= y && y <= 326)) {
				start_display = false;
				Cam_radius = 13 * sqrt(3);
				pi = 270;
				theta = 80;
				start = clock();
			}

			/*시작화면에서 어떻게 플레이하는지 알려주는 화면으로 넘어감*/
			if ((364 <= x && x <= 751) && (380 <= y && y <= 448)) {
				start_display = false;
				how_to_play = true;
			}
		}
	}
		
	glutPostRedisplay();
}
