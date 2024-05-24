#include "ChengYu.h"

//int end = 1;//用end全局变量表示游戏状态
//int flag=0;//标记难度，0为简单，1为困难

int main()
{
    /* 生成随机数种子,表示以当前时间对应的int值为随机序列起点，
       这样每次运行程序，由于起点不同才可以得到不同的随机数   */
    srand((unsigned int)time(0));
    int result;
    //用end保证每个部分结束后都能回到菜单界面
    while (end)//end初始值为1
	{
		result = Menu();//通过result选择下一步
		switch (result)
		{
            case 1:
                Init();//游戏初始化
                break;
            case 2:
                Help();//获取帮助信息
                break;
            case 3:
                About();//获取关于信息
                break;
            case 0:
                end = 0;
                break;
		}
	}
}

void setcolor(int color)//改变字体颜色
{
    //定义标准输出屏幕的句柄并赋值
    HANDLE hc=GetStdHandle(STD_OUTPUT_HANDLE);

    /*设置控制台背景颜色和背景色的函数，
    第一个参数是指向标准输出屏幕的句柄，
    第二个参数为属性值相加后的颜色数值*/
    SetConsoleTextAttribute(hc,0|color);
}

int Menu()
{
	GotoXY(45,10);
	setcolor(4);//设置字体颜色为红色
	printf("欢迎来到成语填填乐游戏");
	GotoXY(50, 13);
	setcolor(12);//设置字体颜色为橙红
	printf("1.开始游戏");
	GotoXY(50, 15);
	setcolor(6);//设置字体颜色为黄色
	printf("2.帮助");
	GotoXY(50, 17);
	setcolor(13);//设置字体颜色为浅紫
	printf("3.关于");
	GotoXY(47, 21);
	setcolor(9);//设置字体颜色为中蓝
	printf("其他任意键退出游戏");
	setcolor(7);//重新设置为白色
	Hide();//隐藏光标
	char ch;
	int result = 0;
	ch = _getch();/* getch()函数所需头文件：conio.h。其不会显函数，
                     当用户按下按键时无需按回车，函数自动读取     */
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
	system("cls");  //调用系统命令cls完成清屏操作
	return result;
}

void GotoXY(int x,int y)//光标定位函数
{
	HANDLE hout;//句柄，用于标记资源
	COORD cor; //Window.h中定义的坐标结构体，用来表示第一个字符在控制台屏幕上的坐标

	/*GetStdHandle（）是一个Windows API函数。
	它用于从一个特定的标准设备（标准输入、标准输出或标准错误）
	中取得一个句柄（用来标识不同设备的数值）*/
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	cor.X = x;
	cor.Y = y;//这两句用于将传入的参数传递给第一个字符的坐标

	/*SetConsoleCursorPosition是API中定位光标位置的函数，
	第一个参数是句柄，第二个参数是坐标的位置*/
	SetConsoleCursorPosition(hout, cor);
}

void Hide()//隐藏光标函数
{
    /*GetStdHandle返回一个指向标准输入，输出或错误处理的句柄.
    STD_OUTPUT_HANDLE : 通常为标准输出的屏幕。（得到控制台缓冲区的句柄）*/
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	/*实例化光标信息结构体cor_info，
	参数中的1表示光标填充的字符单元格百分比为1%，显示出来非常微小；
	参数0表示游标的可见性为0，即不显示游标*/
	CONSOLE_CURSOR_INFO cor_info = { 1,0 };

	/*是用来设置指定控制台屏幕缓冲区的光标大小和可见性的信息的语句，
	传入的第一个元素必须有GENERIC_READ访问权限，
	第二个参数为指向光标信息的指针*/
	SetConsoleCursorInfo(hout, &cor_info);
}

void About()//获取关于信息
{
	GotoXY(36, 10);
	setcolor(4);//设置颜色为红色
	printf("杭州电子科技大学--程序设计综合实践大作业");
	GotoXY(48, 13);
	setcolor(11);//设置颜色为超浅蓝色
	printf("成语填填乐游戏");
	GotoXY(48, 15);
	setcolor(2);//设置颜色为深绿色
	printf("编写组：斗地组");
	GotoXY(46,17);
	printf("（按1查看组员名单）");
	GotoXY(45, 21);
	setcolor(9);//设置颜色为中蓝色
	printf("其他任意键返回上级菜单");
	setcolor(7);//重新设置为白色
	Hide();
	char ch = _getch();
	if(ch=='1'){
        About2();//二级关于信息
	}
	system("cls");
}

void About2()//二级关于信息
{
    system("cls");
    GotoXY(38,8);
    setcolor(4);//设置颜色为红色
    printf("小组成员名单：");
    setcolor(7);//重新设置为白色
    GotoXY(50,11);
    printf("蒋艺宣");
    GotoXY(50,13);
    printf("陈琦");
    GotoXY(50,15);
    printf("李腾");
    GotoXY(50,17);
    printf("陈子坤");
    GotoXY(50,19);
    printf("赵文韬");
    GotoXY(42,21);
    setcolor(12);//设置颜色为橙红色
    printf("程序设计课程组，特别鸣谢！");
    GotoXY(45,25);
    setcolor(9);//重新设置为白色
    printf("按任意键返回主菜单");
    setcolor(7);//重新设置为白色
    Hide();
    char ch=_getch();
    system("cls");
}

void Help()//获取帮助信息
{
	GotoXY(48, 12);
	printf("努力填对词语吧！");
	GotoXY(45, 19);
	setcolor(9);//设置字体颜色为白蓝色
	printf("按任意键返回上级菜单");
	setcolor(7);//重新设置为白色
	Hide();
	char ch = _getch();
	system("cls");
}

void Init()//游戏初始化
{
    ReadIn();//读取文本文件
    number = 0;//初始化答题总数
    right = 0;//初始化答题正确数
    wrong  = 0;//初始化答题错误数
    score = 0;//初始化分数
    diff_t = 0.0;//初始化始末时间差
    lastTest_t = 0.0;//初始化上一题所需要的时间
    for(int i=0;i<50;i++){
       rightstore[i]=0;//初始化标记正确的题目的数组
       wrongstore[i]=0;//初始化标记错误的题目的数组
    }
    random();//实现把50道题打乱的功能
    GotoXY(45, 12);
	printf("选择你的游戏难度：");
	GotoXY(48, 14);
	printf("按1：");
	setcolor(10);//设置颜色为浅绿色
    printf("简单");
	GotoXY(48, 16);
	setcolor(7);//重新设置为白色
	printf("按2：");
	setcolor(4);//设置颜色为红色
	printf("困难");
	GotoXY(43, 19);
	setcolor(9);//设置颜色为中蓝色
	printf("按其他任意键回到主界面");
	setcolor(7);//重新设置为白色
	char ch = _getch();//获取输入字符
	switch(ch)
	{
	    case '1':
                GameStartCommon();//普通难度
                break;
        case '2':
                GameStartHard();//困难难度
                break;
	}
    system("cls");//清屏
    return;
}

void GameOver()//游戏结束后打印相关信息
{
    system("cls");
    GotoXY(48,8);
    if(flag==0){
        printf("简单模式结束");
    }else if(flag==1){
        printf("困难模式结束");
    }
    GotoXY(83,2);
    printf("本局游戏用时：%.f秒",diff_t);
    GotoXY(83,4);
    printf("平均每题用时：%.2f秒",(float)diff_t/number);
    GotoXY(42,10);
    printf("你正确了%d道题，错误了%d道题",right,wrong);
    GotoXY(48, 12);
	printf("得分为：");
	setcolor(4);//设置字体颜色为红色
	printf("%d",score);
	setcolor(7);//重新设置为白色
    //以下列出回答正确的词语
    printf("\n\n  正确词语为：");
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
    //以下列出回答错误的词语
    setcolor(7);
    printf("\n\n  错误词语为：");
    setcolor(4);//设置字体颜色为红色
    for(int i=0;i<wrong;i++){
        for(int j=0;j<4;j++){
            printf("%s",TestBank[wrongstore[i]].a[j]);
        }
        printf(" ");
        if((i+1)%8==0){
            printf("\n\n              ");
        }
    }
    setcolor(4);//设置字体颜色为红色
	printf("\n\n\n                                               游戏结束啦!!!");
	setcolor(9);
	printf("\n\n                                            输入任意键回到主界面");
	setcolor(7);
	Hide();
    char ch = _getch();
    system("cls");
    return ;
}

void ReadIn()//实现从文本中读取题目的功能
{
     for(int i =1;i<TestSum+1;i++){
        char *c1 = ".txt";//字符串指针，指向文本的后缀
        char c[16];
        sprintf(c,"%d",i);//把整型i打印到字符串中
        //将字符串拼接，得到例如1.txt的字符串，即为我们所需要读取的文件名
        char *ph = strcat(c,c1);
        FILE *p1;//定义指向文件的指针
        p1 = fopen(ph,"r");//指向名为ph的文件，r为只读
        for(int j =0;j<4;j++){
            /*从文件指针pl所指向的文本中读取3个字节
            到TestBank结构体数组中的指定结构体的成员变量
            ——字符串数组a[4][4]的第j+1个字符串中，
            一个字符串中含有一个汉字和一个'\0'，三个字节*/
            fgets(TestBank[i-1].a[j],3,p1);
        }
        fgetc(p1);//读取pl的下一个字符，即空格
        /*指向pl所指向的文件中的下一个字符，并读取1000个字节到
        TestBank结构体数组中的某一个结构体的成员变量story字符数组中*/
        fgets(TestBank[i-1].story,1000,p1);
    }
}

void GameStartCommon()//简单模式
{
    flag=0;//标记简单模式
    system("cls");
    time(&this_t);//获取当前时间
    GotoXY(85,2);
    printf("上一题用时：%.f秒",lastTest_t);
    number++;//答题数加一
    srand((unsigned)time(NULL));//用时间做种子实现每次随机数的不同，即改变rand()
    int temp = rand()%4;//随机生成[0,3]之间的整数
    char compareanswer[4];//compareanswer为标准答案那个字
    char standardanswer[4][4];//standardanswer为正确答案
    printScore(score,right,wrong);//打印分数信息
    //把正确的成语复制到字符串数组standardanswer[i]中，里面存储着标准的成语
    for(int i=0;i<4;i++){
        strcpy(standardanswer[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    char tempChengYu[4][4];//临时存储数组，保证原数组不修改
    for(int i=0;i<4;i++){//将正确的成语复制到临时字符串二维数组tempChengYu中
        strcpy(tempChengYu[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    //将正确的成语中的随机一个字复制到字符数组compareanswer数组中，里面存储着标准答案
    strcpy(compareanswer,TestBank[randomnumber[number-1]-1].a[temp]);
    strcpy(tempChengYu[temp],"_");//把临时字符串二维数组中相对应的字用下划线_替代掉
    GotoXY(47,10);
    for(int i=0;i<4;i++){
        printf("%s",tempChengYu[i]);
    }//打印临时字符串二维数组，表现为少了一个字的成语
    GotoXY(45,12);
    printf("请输入答案：");
    char insertanswer[100];//insertanswer是你输入的答案
    scanf("%s",insertanswer);
    if(strcmp(insertanswer,compareanswer)==0)//如果输入的答案与标准答案相同
    {
        GotoXY(45,14);
        setcolor(10);//设置颜色为浅绿
        printf("回答正确，你真棒！\n\n\n\n");
        setcolor(7);//设置颜色为白色
        printf("故事：\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);//打印对应的故事
        rightstore[rightrecord]=randomnumber[number-1]-1;//标记该题正确
        rightrecord++;//标记正确数的数组的索引加一
        GotoXY(38,16);
        setcolor(9);//设置颜色为中蓝色
        printf("按1进入下一题，按其他键结束游戏");
        setcolor(7);//重新设置为白色
        right++;//标记正确数加一
        switch(right/10){//按照答对的次数进行分数叠加，答得越多，单题加分越多
            case 0:score+=5;break;
            case 1:score+=10;break;
            case 2:score+=15;break;
            case 3:score+=20;break;
            case 4:score+=25;break;
            case 5:score+=100;break;//全对最后一题加100分
        }
    }
    else{
        GotoXY(45,14);
        setcolor(4);//设置颜色为红色
        printf("回答错误，再接再厉");
        setcolor(7);//重新设置为白色
        GotoXY(45,16);
        printf("正确答案是:");
        for(int i=0;i<4;i++){
            printf("%s",standardanswer[i]);
        }//回答错误，输出原来的正确答案
        printf("\n\n\n\n故事：\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);//打印对应的故事
        wrongstore[wrongrecord]=randomnumber[number-1]-1;//标记该题错误
        wrongrecord++;//标记错误数的数组的索引加一
        GotoXY(40,18);
        setcolor(9);//设置颜色为中蓝色
        printf("按1进入下一题，按其他键结束游戏");
        setcolor(7);//重新设置为白色
        wrong++;//标记错误数加一
    }
    printScore(score,right,wrong);//打印分数相关信息
    time(&next_t);//标记回答完的时间
    diff_t+=difftime(next_t,this_t);//累计每道题的总时间
    //切换到下一步
    if(number==TestSum){//题目全都答完了
       GameOver();
    }
    else{
        char ch = _getch();
        switch(ch){
            case'1':
                //下一题
                lastTest_t = difftime(next_t,this_t);//计算上一题所消耗的时间
                GameStartCommon();//进入下一题
                return;
        }
        GameOver();
    }
}

void GameStartHard()//困难模式
{
    flag=1;//标记困难模式
    system("cls");
    time(&this_t);
    GotoXY(85,2);
    printf("上一题用时：%.f秒",lastTest_t);//输出上一题用时
    number++;//答题数加一
    srand((unsigned)time(NULL));//用时间做种子实现每次随机数的不同
    int temp1 = rand()%4;//随机生成m，n范围内随机数int a=m+rand()%(n-m+1)
    int temp2= rand()%4;
    while(temp2 ==temp1){
        temp2= rand()%4;
    }
    if(temp2<temp1)//保证temp1永远小于temp2
    {
         int store;
         store=temp2;
         temp2=temp1;
         temp1=store;
    }
    char compareanswer1[4],compareanswer2[4];//分别为标准答案那两个个字
    char standardanswer[4][4];//为正确答案
    printScore(score,right,wrong);
    for(int i=0;i<4;i++){
        strcpy(standardanswer[i],TestBank[randomnumber[number-1]-1].a[i]);
    }
    char tempChengYu[4][4];//保证结构体中的成语不被修改，方便后续输出
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
    printf("请输入答案的第一个字：");
    char insertanswer1[100],insertanswer2[100];//c是你输入的答案的第一个字，f是第二个字
    scanf("%s",insertanswer1);
    GotoXY(45,14);
    printf("请输入答案的第二个字：");
    scanf("%s",insertanswer2);
    if(strcmp(insertanswer1,compareanswer1)==0&&strcmp(insertanswer2,compareanswer2)==0){
       GotoXY(47,16);
       setcolor(10);//设置字体颜色为浅绿色
       printf("回答正确，你真棒！\n\n\n\n");
       setcolor(7);//重新设置为白色
       printf("故事：\n\n    ");
       printf("%s",TestBank[randomnumber[number-1]-1].story);
       rightstore[rightrecord]=randomnumber[number-1]-1;
       rightrecord++;
       GotoXY(42,18);
       setcolor(9);//设置字体颜色为中蓝色
       printf("按1进入下一题，按其他键结束游戏");
       setcolor(7);//重新设置为白色
       right++;
       switch(right/10){//按照答对的次数进行分数叠加，答得越多，单题加分越多
            case 0:score+=10;break;
            case 1:score+=20;break;
            case 2:score+=30;break;
            case 3:score+=50;break;
            case 4:score+=100;break;
            case 5:score+=500;break;//全对最后一题加500分
        }
    }
    else{
        GotoXY(45,16);
        setcolor(4);//设置字体为红色
        printf("回答错误，再接再厉");
        GotoXY(46,18);
        setcolor(7);//重新设置为白色
        printf("正确答案是:");
        for(int i=0;i<4;i++){
            printf("%s",standardanswer[i]);
        }
        wrongstore[wrongrecord]=randomnumber[number-1]-1;
        wrongrecord++;
        GotoXY(42,20);
        setcolor(9);//设置字体颜色为中蓝色
        printf("按1进入下一题，按其他键结束游戏");
        setcolor(7);//重新设置为白色
        printf("\n\n故事：\n\n    ");
        printf("%s",TestBank[randomnumber[number-1]-1].story);
        wrong++;
    }
    time(&next_t);
    diff_t+=difftime(next_t,this_t);//累计每道题的总时间
    printScore(score,right,wrong);
    //切换到下一步
    if(number==TestSum){
        GameOver();
    }else{
        char ch = _getch();
        switch(ch){
        case'1':
            //下一题
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
    setcolor(12);//设置字体颜色为橙红色
    printf("分数:%d",score);
    GotoXY(3,3);
    setcolor(10);//设置字体颜色为浅绿色
    printf("正确题数:%d ",right);
    GotoXY(3,5);
    setcolor(4);//设置字体颜色为红色
    printf("错误题数:%d",wrong);
    GotoXY(3,7);
    setcolor(13);//设置字体颜色为浅紫色
    printf("第%d/%d道题",number,TestSum);
    setcolor(7);//重新设置为白色
}

void random()//实现50个不重复随机数
{
    int i=0,j=0,r=0;
    srand((int)time(0));   //用当前时间作为随机种子
    while(i<TestSum)
    {
        r=rand() % TestSum+ 1;//生成一个1-50的随机数([0,49]+1=[1,50])
        for(j=i;j>=0;j--)
        {
            //与之前已存的随机数比较,若已有重复的，则跳过循环，此时j大于0
            if(r==randomnumber[j])
                break;
        }
        /*没有重复即保存到数组中，有重负则不保存，
        即到下一个while循环中去，打乱后的数组当前索引的对象未获取成功*/
        if(j<0)
        {
            randomnumber[i]=r;
            i++;
        }
    }
}
