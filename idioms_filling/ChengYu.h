#ifndef CHENGYU_H_INCLUDED//条件编译
#define CHENGYU_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>//要用到用户界面函数，Kernel函数，还有系统休眠，清屏
#include<conio.h>//控制台输入输出文件头
#include<time.h>//日期和时间文件头
#include<string.h>

void GotoXY(int x, int y);//光标定位函数
void Hide();			   //隐藏光标函数
void setcolor(int color); //改变字体颜色函数
void ReadIn();             //读入游戏成语库
void random();             //实现50个不重复随机数
void Help();			   //帮助信息函数
void About();		       //关于信息函数
void About2();             //二级关于信息
void printScore(int score,int right,int wrong);//打印分数信息
void Init();               //游戏初始化
void GameStartCommon();    //游戏开始(普通模式)
void GameStartHard();      //游戏开始(困难模式)
void GameOver();           //游戏结束后打印相关信息
int Menu();			       //主菜单函数

int right=0;//记录答题正确数
int wrong=0;//记录答题错误数
int score=0;//纪录分数

#define TestSum 50//定义题目总数为50

struct game{
    char a[4][4];
    char story[1000];
}TestBank[TestSum];//存储着题目信息的结构体数组

int number=0;//表示回答过的题目数量
int randomnumber[TestSum];//表示从结构体中随机抽到的题目

int rightstore[50];//存储标记着回答正确的题目的数组
int wrongstore[50];//存储标记着回答错误的题目的数组

int rightrecord=0;//标记回答正确数的数组索引
int wrongrecord=0;//标记回答错误数的数组索引

int end=1;//用end全局变量表示游戏状态
int flag=0;//标记难度，0为简单，1为困难

time_t this_t , next_t ;//记录当前题目开始时间与当前题目回答完的时间
double lastTest_t;//纪录一题用时
double diff_t ;//纪录游戏总时长

#endif // CHENGYU_H_INCLUDED
