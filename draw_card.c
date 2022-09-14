#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

char *fivestar[] = {"�µ�", "����", "Ī��", "����", "��¬��", "��"};
char *fourstar[] = {"����","�ϰ���","ɰ��","����","ŵ����","������","��л��","����","����","����","����","����","����","����","�Ű���","��ɯ", \
					"����","����","����","�����Թ�","����","�������","��������","�����ص�","���糤ǹ","ϻ����","���","�����","�ӽ�", \
					"�����","ϻ������","����","�ѽ�","���罣"};
char *threestar[] = {"�Ի��㵶","������","���н�","������","����","��������","������","��Ӱ����","���������","�������","��ԡ��Ѫ�Ľ�", \
					"����","������","������֮��","ѻ��","��ʹ","������","�׼�����","ħ������","����Ӣ��̷","�������м�","��ӧǹ","��ì","��ӧǹ"};
					
int all_count = 0;
int big_count = 0;
int small_count = 0;
int five_star_cnt = 0;

void drawfivestarpool(int *flag)
{
	int up, wai;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(*flag == 1)
	{
		printf("%d: %s\n",all_count,fivestar[0]);
		*flag = 0;
	}
	else if(*flag == 0)
	{
		up=rand()%2+0;
		if(up)
		{
			printf("%d: %s\n",all_count,fivestar[0]);
		}
		else
		{
			wai=rand()%5+1;
			printf("%d: %s\n",all_count,fivestar[wai]);
		}	
		*flag = 1;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	five_star_cnt++;
	big_count = 0;
	small_count = 0;
}

void drawfourstarpool()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	int up, wai;
	up=rand()%2+0;
	if(up)
	{
		wai=rand()%3+0;
		printf("%d: %s\n",all_count,fourstar[wai]);
	}
	else
	{
		wai=rand()%31+2;
		printf("%d: %s\n",all_count,fourstar[wai]);
	}
	small_count =0;	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

void drawthreestarpool()
{
	int wai;
	wai=rand()%24+0;
	printf("%d: %s\n",all_count,threestar[wai]);
}

void singledraw(int *upflag)
{
	int pool, up;
	int wai;
	all_count++;
	big_count++;
	small_count++;
			
	if(big_count==90)
	{
		drawfivestarpool(upflag);
		return;
	}
			
	if(small_count==10)
	{
		pool=rand()%1000+1;
		/* 0.6% 5 star pool*/
		if(pool<=6)
		{		
			drawfivestarpool(upflag);
		}
		else
		{
			drawfourstarpool();
		}
		return;
	}
			
	pool=rand()%1000+1;
	/* 0.6% 5 star pool*/
	if(pool<=6)
	{		
		drawfivestarpool(upflag);
	}
	
	/* 5.1% 4 star pool*/
	else if(pool>6 && pool<58)
	{
		drawfourstarpool();		
	}	
	
	/* 94.3% 3 star pool*/
	else
	{
		drawthreestarpool();	
	}
}

int main()
{
	SetConsoleTitle("��Զ����");
	int i,draw_num,upflag;
	upflag=0;
	srand(time(0));
	printf("up���ǣ��µ�	up���ǣ����͡��ϰ��ȡ�ɰ��\n");
	printf("0������		1��ʮ��\n");
	while(1)
	{
		scanf("%d",&draw_num);
		if(draw_num==0)
		{
			singledraw(&upflag);
		}
		else if(draw_num==1)
		{
			for(i=0;i<10;i++)
			{
				singledraw(&upflag);
			}
		}
	}
}

