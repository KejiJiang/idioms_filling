#ifndef CHENGYU_H_INCLUDED//��������
#define CHENGYU_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>//Ҫ�õ��û����溯����Kernel����������ϵͳ���ߣ�����
#include<conio.h>//����̨��������ļ�ͷ
#include<time.h>//���ں�ʱ���ļ�ͷ
#include<string.h>

void GotoXY(int x, int y);//��궨λ����
void Hide();			   //���ع�꺯��
void setcolor(int color); //�ı�������ɫ����
void ReadIn();             //������Ϸ�����
void random();             //ʵ��50�����ظ������
void Help();			   //������Ϣ����
void About();		       //������Ϣ����
void About2();             //����������Ϣ
void printScore(int score,int right,int wrong);//��ӡ������Ϣ
void Init();               //��Ϸ��ʼ��
void GameStartCommon();    //��Ϸ��ʼ(��ͨģʽ)
void GameStartHard();      //��Ϸ��ʼ(����ģʽ)
void GameOver();           //��Ϸ�������ӡ�����Ϣ
int Menu();			       //���˵�����

int right=0;//��¼������ȷ��
int wrong=0;//��¼���������
int score=0;//��¼����

#define TestSum 50//������Ŀ����Ϊ50

struct game{
    char a[4][4];
    char story[1000];
}TestBank[TestSum];//�洢����Ŀ��Ϣ�Ľṹ������

int number=0;//��ʾ�ش������Ŀ����
int randomnumber[TestSum];//��ʾ�ӽṹ��������鵽����Ŀ

int rightstore[50];//�洢����Żش���ȷ����Ŀ������
int wrongstore[50];//�洢����Żش�������Ŀ������

int rightrecord=0;//��ǻش���ȷ������������
int wrongrecord=0;//��ǻش����������������

int end=1;//��endȫ�ֱ�����ʾ��Ϸ״̬
int flag=0;//����Ѷȣ�0Ϊ�򵥣�1Ϊ����

time_t this_t , next_t ;//��¼��ǰ��Ŀ��ʼʱ���뵱ǰ��Ŀ�ش����ʱ��
double lastTest_t;//��¼һ����ʱ
double diff_t ;//��¼��Ϸ��ʱ��

#endif // CHENGYU_H_INCLUDED
