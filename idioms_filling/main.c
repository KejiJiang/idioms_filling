#include "ChengYu.h"

//int end = 1;//��endȫ�ֱ�����ʾ��Ϸ״̬
//int flag=0;//����Ѷȣ�0Ϊ�򵥣�1Ϊ����

int main()
{
    /* �������������,��ʾ�Ե�ǰʱ���Ӧ��intֵΪ���������㣬
       ����ÿ�����г���������㲻ͬ�ſ��Եõ���ͬ�������   */
    srand((unsigned int)time(0));
    int result;
    //��end��֤ÿ�����ֽ������ܻص��˵�����
    while (end)//end��ʼֵΪ1
	{
		result = Menu();//ͨ��resultѡ����һ��
		switch (result)
		{
            case 1:
                Init();//��Ϸ��ʼ��
                break;
            case 2:
                Help();//��ȡ������Ϣ
                break;
            case 3:
                About();//��ȡ������Ϣ
                break;
            case 0:
                end = 0;
                break;
		}
	}
}

void setcolor(int color)//�ı�������ɫ
{
    //�����׼�����Ļ�ľ������ֵ
    HANDLE hc=GetStdHandle(STD_OUTPUT_HANDLE);

    /*���ÿ���̨������ɫ�ͱ���ɫ�ĺ�����
    ��һ��������ָ���׼�����Ļ�ľ����
    �ڶ�������Ϊ����ֵ��Ӻ����ɫ��ֵ*/
    SetConsoleTextAttribute(hc,0|color);
}

int Menu()
{
	GotoXY(45,10);
	setcolor(4);//����������ɫΪ��ɫ
	printf("��ӭ����������������Ϸ");
	GotoXY(50, 13);
	setcolor(12);//����������ɫΪ�Ⱥ�
	printf("1.��ʼ��Ϸ");
	GotoXY(50, 15);
	setcolor(6);//����������ɫΪ��ɫ
	printf("2.����");
	GotoXY(50, 17);
	setcolor(13);//����������ɫΪǳ��
	printf("3.����");
	GotoXY(47, 21);
	setcolor(9);//����������ɫΪ����
	printf("����������˳���Ϸ");
	setcolor(7);//��������Ϊ��ɫ
	Hide();//���ع��
	char ch;
	int result = 0;
	ch = _getch();/* getch()��������ͷ�ļ���conio.h���䲻���Ժ�����
                     ���û����°���ʱ���谴�س��������Զ���ȡ     */
	switch (ch)
	{
	case'1':
		result = 1;
		break;
	case'2':
		result = 2;
		break;
	case'3':
		result = 3;
		break;
	}
	system("cls");  //����ϵͳ����cls�����������
	return result;
}

void GotoXY(int x,int y)//��궨λ����
{
	HANDLE hout;//��������ڱ����Դ
	COORD cor; //Window.h�ж��������ṹ�壬������ʾ��һ���ַ��ڿ���̨��Ļ�ϵ�����

	/*GetStdHandle������һ��Windows API������
	�����ڴ�һ���ض��ı�׼�豸����׼���롢��׼������׼����
	��ȡ��һ�������������ʶ��ͬ�豸����ֵ��*/
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	cor.X = x;
	cor.Y = y;//���������ڽ�����Ĳ������ݸ���һ���ַ�������

	/*SetConsoleCursorPosition��API�ж�λ���λ�õĺ�����
	��һ�������Ǿ�����ڶ��������������λ��*/
	SetConsoleCursorPosition(hout, cor);
}

void Hide()//���ع�꺯��
{
    /*GetStdHandle����һ��ָ���׼���룬����������ľ��.
    STD_OUTPUT_HANDLE : ͨ��Ϊ��׼�������Ļ�����õ�����̨�������ľ����*/
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	/*ʵ���������Ϣ�ṹ��cor_info��
	�����е�1��ʾ��������ַ���Ԫ��ٷֱ�Ϊ1%����ʾ�����ǳ�΢С��
	����0��ʾ�α�Ŀɼ���Ϊ0��������ʾ�α�*/
	CONSOLE_CURSOR_INFO cor_info = { 1,0 };

	/*����������ָ������̨��Ļ�������Ĺ���С�Ϳɼ��Ե���Ϣ����䣬
	����ĵ�һ��Ԫ�ر�����GENERIC_READ����Ȩ�ޣ�
	�ڶ�������Ϊָ������Ϣ��ָ��*/
	SetConsoleCursorInfo(hout, &cor_info);
}

void About()//��ȡ������Ϣ
{
	GotoXY(36, 10);
	setcolor(4);//������ɫΪ��ɫ
	printf("���ݵ��ӿƼ���ѧ--��������ۺ�ʵ������ҵ");
	GotoXY(48, 13);
	setcolor(11);//������ɫΪ��ǳ��ɫ
	printf("������������Ϸ");
	GotoXY(48, 15);
	setcolor(2);//������ɫΪ����ɫ
	printf("��д�飺������");
	GotoXY(46,17);
	printf("����1�鿴��Ա������");
	GotoXY(45, 21);
	setcolor(9);//������ɫΪ����ɫ
	printf("��������������ϼ��˵�");
	setcolor(7);//��������Ϊ��ɫ
	Hide();
	char ch = _getch();
	if(ch=='1'){
        About2();//����������Ϣ
	}
	system("cls");
}

void About2()//����������Ϣ
{
    system("cls");
    GotoXY(38,8);
    setcolor(4);//������ɫΪ��ɫ
    printf("С���Ա������");
    setcolor(7);//��������Ϊ��ɫ
    GotoXY(50,11);
    printf("������");
    GotoXY(50,13);
    printf("����");
    GotoXY(50,15);
    printf("����");
    GotoXY(50,17);
    printf("������");
    GotoXY(50,19);
    printf("�����");
    GotoXY(42,21);
    setcolor(12);//������ɫΪ�Ⱥ�ɫ
    printf("������ƿγ��飬�ر���л��");
    GotoXY(45,25);
    setcolor(9);//��������Ϊ��ɫ
    printf("��������������˵�");
    setcolor(7);//��������Ϊ��ɫ
    Hide();
    char ch=_getch();
    system("cls");
}

void Help()//��ȡ������Ϣ
{
	GotoXY(48, 12);
	printf("Ŭ����Դ���ɣ�");
	GotoXY(45, 19);
	setcolor(9);//����������ɫΪ����ɫ
	printf("������������ϼ��˵�");
	setcolor(7);//��������Ϊ��ɫ
	Hide();
	char ch = _getch();
	system("cls");
}

void Init()//��Ϸ��ʼ��
{
    ReadIn();//��ȡ�ı��ļ�
    number = 0;//��ʼ����������
    right = 0;//��ʼ��������ȷ��
    wrong  = 0;//��ʼ�����������
    score = 0;//��ʼ������
    diff_t = 0.0;//��ʼ��ʼĩʱ���
    lastTest_t = 0.0;//��ʼ����һ������Ҫ��ʱ��
    for(int i=0;i<50;i++){
       rightstore[i]=0;//��ʼ�������ȷ����Ŀ������
       wrongstore[i]=0;//��ʼ����Ǵ������Ŀ������
    }
    random();//ʵ�ְ�50������ҵĹ���
    GotoXY(45, 12);
	printf("ѡ�������Ϸ�Ѷȣ�");
	GotoXY(48, 14);
	printf("��1��");
	setcolor(10);//������ɫΪǳ��ɫ
    printf("��");
	GotoXY(48, 16);
	setcolor(7);//��������Ϊ��ɫ
	printf("��2��");
	setcolor(4);//������ɫΪ��ɫ
	printf("����");
	GotoXY(43, 19);
	setcolor(9);//������ɫΪ����ɫ
	printf("������������ص�������");
	setcolor(7);//��������Ϊ��ɫ
	char ch = _getch();//��ȡ�����ַ�
	switch(ch)
	{
	    case '1':
                GameStartCommon();//��ͨ�Ѷ�
                break;
        case '2':
                GameStartHard();//�����Ѷ�
                break;
	}
    system("cls");//����
    return;
}

void GameOver()//��Ϸ�������ӡ�����Ϣ
{
    system("cls");
    GotoXY(48,8);
    if(flag==0){
        printf("��ģʽ����");
    }else if(flag==1){
        printf("����ģʽ����");
    }
    GotoXY(83,2);
    printf("������Ϸ��ʱ��%.f��",diff_t);
    GotoXY(83,4);
    printf("ƽ��ÿ����ʱ��%.2f��",(float)diff_t/number);
    GotoXY(42,10);
    printf("����ȷ��%d���⣬������%d����",right,wrong);
    GotoXY(48, 12);
	printf("�÷�Ϊ��");
	setcolor(4);//����������ɫΪ��ɫ
	printf("%d",score);
	setcolor(7);//��������Ϊ��ɫ
    //�����г��ش���ȷ�Ĵ���
    printf("\n\n  ��ȷ����Ϊ��");
    setcolor(10);
    for(int i=0;i<right;i++){
        for(int j=0;j<4;j++){
            printf("%s",TestBank[rightstore[i]].a[j]);
        }
        printf(" ");
        if((i+1)%8==0){
            printf("\n\n              ");
        }
    }
    //�����г��ش����Ĵ���
    setcolor(7);
    printf("\n\n  �������Ϊ��");
    setcolor(4);//����������ɫΪ��ɫ
    for(int i=0;i<wrong;i++){
        for(int j=0;j<4;j++){
            printf("%s",TestBank[wrongstore[i]].a[j]);
        }
        printf(" ");
        if((i+1)%8==0){
            printf("\n\n              ");
        }
    }
    setcolor(4);//����������ɫΪ��ɫ
	printf("\n\n\n                                               ��Ϸ������!!!");
	setcolor(9);
	printf("\n\n                                            ����������ص�������");
	setcolor(7);
	Hide();
    char ch = _getch();
    system("cls");
    return ;
}

void ReadIn()//ʵ�ִ��ı��ж�ȡ��Ŀ�Ĺ���
{
     for(int i =1;i<TestSum+1;i++){
        char *c1 = ".txt";//�ַ���ָ�룬ָ���ı��ĺ�׺
        char c[16];
        sprintf(c,"%d",i);//������i��ӡ���ַ�����
        //���ַ���ƴ�ӣ��õ�����1.txt���ַ�������Ϊ��������Ҫ��ȡ���ļ���
        char *ph = strcat(c,c1);
        FILE *p1;//����ָ���ļ���ָ��
        p1 = fopen(ph,"r");//ָ����Ϊph���ļ���rΪֻ��
        for(int j =0;j<4;j++){
            /*���ļ�ָ��pl��ָ����ı��ж�ȡ3���ֽ�
            ��TestBank�ṹ�������е�ָ���ṹ��ĳ�Ա����
            �����ַ�������a[4][4]�ĵ�j+1���ַ����У�
            һ���ַ����к���һ�����ֺ�һ��'\0'�������ֽ�*/
            fgets(TestBank[i-1].a[j],3,p1);
        }
        fgetc(p1);//��ȡpl����һ���ַ������ո�
        /*ָ��pl��ָ����ļ��е���һ���ַ�������ȡ1000���ֽڵ�
        TestBank�ṹ�������е�ĳһ���ṹ��ĳ�Ա����story�ַ�������*/
        fgets(TestBank[i-1].story,1000,p1);
    }
}

void GameStartCommon()//��ģʽ
{
    flag=0;//��Ǽ�ģʽ
    system("cls");
    time(&this_t);//��ȡ��ǰʱ��
    GotoXY(85,2);
    printf("��һ����ʱ��%.f��",lastTest_t);
    number++;//��������һ
    srand((unsigned)time(NULL));//��ʱ��������ʵ��ÿ��������Ĳ�ͬ�����ı�rand()
    int temp = rand()%4;//�������[0,3]֮�������
    char compareanswer[4];//compareanswerΪ��׼���Ǹ���
    char standardanswer[4][4];//standardanswerΪ��ȷ��
    printScore(score,right,wrong);//��ӡ������Ϣ
    //����ȷ�ĳ��︴�Ƶ��ַ�������standardanswer[i]�У�����洢�ű�׼�ĳ���
    for(int i=0;i<4;i++){
        strcpy(standardanswer[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    char tempChengYu[4][4];//��ʱ�洢���飬��֤ԭ���鲻�޸�
    for(int i=0;i<4;i++){//����ȷ�ĳ��︴�Ƶ���ʱ�ַ�����ά����tempChengYu��
        strcpy(tempChengYu[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    //����ȷ�ĳ����е����һ���ָ��Ƶ��ַ�����compareanswer�����У�����洢�ű�׼��
    strcpy(compareanswer,TestBank[randomnumber[number-1]-1].a[temp]);
    strcpy(tempChengYu[temp],"_");//����ʱ�ַ�����ά���������Ӧ�������»���_�����
    GotoXY(47,10);
    for(int i=0;i<4;i++){
        printf("%s",tempChengYu[i]);
    }//��ӡ��ʱ�ַ�����ά���飬����Ϊ����һ���ֵĳ���
    GotoXY(45,12);
    printf("������𰸣�");
    char insertanswer[100];//insertanswer��������Ĵ�
    scanf("%s",insertanswer);
    if(strcmp(insertanswer,compareanswer)==0)//�������Ĵ����׼����ͬ
    {
        GotoXY(45,14);
        setcolor(10);//������ɫΪǳ��
        printf("�ش���ȷ���������\n\n\n\n");
        setcolor(7);//������ɫΪ��ɫ
        printf("���£�\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);//��ӡ��Ӧ�Ĺ���
        rightstore[rightrecord]=randomnumber[number-1]-1;//��Ǹ�����ȷ
        rightrecord++;//�����ȷ���������������һ
        GotoXY(38,16);
        setcolor(9);//������ɫΪ����ɫ
        printf("��1������һ�⣬��������������Ϸ");
        setcolor(7);//��������Ϊ��ɫ
        right++;//�����ȷ����һ
        switch(right/10){//���մ�ԵĴ������з������ӣ����Խ�࣬����ӷ�Խ��
            case 0:score+=5;break;
            case 1:score+=10;break;
            case 2:score+=15;break;
            case 3:score+=20;break;
            case 4:score+=25;break;
            case 5:score+=100;break;//ȫ�����һ���100��
        }
    }
    else{
        GotoXY(45,14);
        setcolor(4);//������ɫΪ��ɫ
        printf("�ش�����ٽ�����");
        setcolor(7);//��������Ϊ��ɫ
        GotoXY(45,16);
        printf("��ȷ����:");
        for(int i=0;i<4;i++){
            printf("%s",standardanswer[i]);
        }//�ش�������ԭ������ȷ��
        printf("\n\n\n\n���£�\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);//��ӡ��Ӧ�Ĺ���
        wrongstore[wrongrecord]=randomnumber[number-1]-1;//��Ǹ������
        wrongrecord++;//��Ǵ������������������һ
        GotoXY(40,18);
        setcolor(9);//������ɫΪ����ɫ
        printf("��1������һ�⣬��������������Ϸ");
        setcolor(7);//��������Ϊ��ɫ
        wrong++;//��Ǵ�������һ
    }
    printScore(score,right,wrong);//��ӡ���������Ϣ
    time(&next_t);//��ǻش����ʱ��
    diff_t+=difftime(next_t,this_t);//�ۼ�ÿ�������ʱ��
    //�л�����һ��
    if(number==TestSum){//��Ŀȫ��������
       GameOver();
    }
    else{
        char ch = _getch();
        switch(ch){
            case'1':
                //��һ��
                lastTest_t = difftime(next_t,this_t);//������һ�������ĵ�ʱ��
                GameStartCommon();//������һ��
                return;
        }
        GameOver();
    }
}

void GameStartHard()//����ģʽ
{
    flag=1;//�������ģʽ
    system("cls");
    time(&this_t);
    GotoXY(85,2);
    printf("��һ����ʱ��%.f��",lastTest_t);//�����һ����ʱ
    number++;//��������һ
    srand((unsigned)time(NULL));//��ʱ��������ʵ��ÿ��������Ĳ�ͬ
    int temp1 = rand()%4;//�������m��n��Χ�������int a=m+rand()%(n-m+1)
    int temp2= rand()%4;
    while(temp2 ==temp1){
        temp2= rand()%4;
    }
    if(temp2<temp1)//��֤temp1��ԶС��temp2
    {
         int store;
         store=temp2;
         temp2=temp1;
         temp1=store;
    }
    char compareanswer1[4],compareanswer2[4];//�ֱ�Ϊ��׼������������
    char standardanswer[4][4];//Ϊ��ȷ��
    printScore(score,right,wrong);
    for(int i=0;i<4;i++){
        strcpy(standardanswer[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    char tempChengYu[4][4];//��֤�ṹ���еĳ��ﲻ���޸ģ�����������
    for(int i=0;i<4;i++){
        strcpy(tempChengYu[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    strcpy(compareanswer1,TestBank[randomnumber[number-1]-1].a[temp1]);
    strcpy(compareanswer2,TestBank[randomnumber[number-1]-1].a[temp2]);
    strcpy(tempChengYu[temp1],"_");
    strcpy(tempChengYu[temp2],"_");
    GotoXY(50,10);
    for(int i=0;i<4;i++){
        printf("%s ",tempChengYu[i]);
    }
    GotoXY(45,12);
    printf("������𰸵ĵ�һ���֣�");
    char insertanswer1[100],insertanswer2[100];//c��������Ĵ𰸵ĵ�һ���֣�f�ǵڶ�����
    scanf("%s",insertanswer1);
    GotoXY(45,14);
    printf("������𰸵ĵڶ����֣�");
    scanf("%s",insertanswer2);
    if(strcmp(insertanswer1,compareanswer1)==0&&strcmp(insertanswer2,compareanswer2)==0){
       GotoXY(47,16);
       setcolor(10);//����������ɫΪǳ��ɫ
       printf("�ش���ȷ���������\n\n\n\n");
       setcolor(7);//��������Ϊ��ɫ
       printf("���£�\n\n    ");
       printf("%s",TestBank[randomnumber[number-1]-1].story);
       rightstore[rightrecord]=randomnumber[number-1]-1;
       rightrecord++;
       GotoXY(42,18);
       setcolor(9);//����������ɫΪ����ɫ
       printf("��1������һ�⣬��������������Ϸ");
       setcolor(7);//��������Ϊ��ɫ
       right++;
       switch(right/10){//���մ�ԵĴ������з������ӣ����Խ�࣬����ӷ�Խ��
            case 0:score+=10;break;
            case 1:score+=20;break;
            case 2:score+=30;break;
            case 3:score+=50;break;
            case 4:score+=100;break;
            case 5:score+=500;break;//ȫ�����һ���500��
        }
    }
    else{
        GotoXY(45,16);
        setcolor(4);//��������Ϊ��ɫ
        printf("�ش�����ٽ�����");
        GotoXY(46,18);
        setcolor(7);//��������Ϊ��ɫ
        printf("��ȷ����:");
        for(int i=0;i<4;i++){
            printf("%s",standardanswer[i]);
        }
        wrongstore[wrongrecord]=randomnumber[number-1]-1;
        wrongrecord++;
        GotoXY(42,20);
        setcolor(9);//����������ɫΪ����ɫ
        printf("��1������һ�⣬��������������Ϸ");
        setcolor(7);//��������Ϊ��ɫ
        printf("\n\n���£�\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);
        wrong++;
    }
    time(&next_t);
    diff_t+=difftime(next_t,this_t);//�ۼ�ÿ�������ʱ��
    printScore(score,right,wrong);
    //�л�����һ��
    if(number==TestSum){
        GameOver();
    }else{
        char ch = _getch();
        switch(ch){
        case'1':
            //��һ��
            lastTest_t = difftime(next_t,this_t);
            GameStartHard();
            return;
        }
        GameOver();
    }
}

void printScore(int score,int right,int wrong)
{
    GotoXY(3,1);
    setcolor(12);//����������ɫΪ�Ⱥ�ɫ
    printf("����:%d",score);
    GotoXY(3,3);
    setcolor(10);//����������ɫΪǳ��ɫ
    printf("��ȷ����:%d ",right);
    GotoXY(3,5);
    setcolor(4);//����������ɫΪ��ɫ
    printf("��������:%d",wrong);
    GotoXY(3,7);
    setcolor(13);//����������ɫΪǳ��ɫ
    printf("��%d/%d����",number,TestSum);
    setcolor(7);//��������Ϊ��ɫ
}

void random()//ʵ��50�����ظ������
{
    int i=0,j=0,r=0;
    srand((int)time(0));   //�õ�ǰʱ����Ϊ�������
    while(i<TestSum)
    {
        r=rand() % TestSum+ 1;//����һ��1-50�������([0,49]+1=[1,50])
        for(j=i;j>=0;j--)
        {
            //��֮ǰ�Ѵ��������Ƚ�,�������ظ��ģ�������ѭ������ʱj����0
            if(r==randomnumber[j])
                break;
        }
        /*û���ظ������浽�����У����ظ��򲻱��棬
        ������һ��whileѭ����ȥ�����Һ�����鵱ǰ�����Ķ���δ��ȡ�ɹ�*/
        if(j<0)
        {
            randomnumber[i]=r;
            i++;
        }
    }
}
