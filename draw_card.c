#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

char *fivestar[] = {"ÎÂµÏ", "¿ÌÇç", "ÄªÄÈ", "ÆßÆß", "µÏÂ¬¿Ë", "ÇÙ"};
char *fourstar[] = {"ĞÁìÍ","µÏ°ÂÄÈ","É°ÌÇ","ÖØÔÆ","Åµ°¬¶û","°àÄáÌØ","·ÆĞ»¶û","Äı¹â","ĞĞÇï","±±¶·","ÏãÁâ","°²°Ø","À×Ôó","¿­ÑÇ","°Å°ÅÀ­","ÀöÉ¯", \
					"¹­²Ø","¼ÀÀñ¹­","¾øÏÒ","Î÷·çÁÔ¹­","ÕÑĞÄ","¼ÀÀñ²ĞÕÂ","Á÷ÀËÀÖÕÂ","Î÷·çÃØµä","Î÷·ç³¤Ç¹","Ï»ÀïÃğ³½","Óê²Ã","¼ÀÀñ´ó½£","ÖÓ½£", \
					"Î÷·ç´ó½£","Ï»ÀïÁúÒ÷","¼ÀÀñ½£","µÑ½£","Î÷·ç½£"};
char *threestar[] = {"³Ô»¢Óãµ¶","ÀèÃ÷Éñ½£","ÂÃĞĞ½£","°µÌú½£","ÀäÈĞ","·ÉÌìÓù½£","°×Ìú´ó½£","ÌúÓ°À«½£","·ÉÌì´óÓù½£","ÒÔÀí·şÈË","ãåÔ¡ÁúÑªµÄ½£", \
					"µ¯¹­","·´Çú¹­","ÉñÉäÊÖÖ®ÊÄ","Ñ»Óğ¹­","ĞÅÊ¹","ôäÓñ·¨Çò","¼×¼¶±¦çå","Ä§µ¼Ğ÷ÂÛ","ÌÖÁúÓ¢½ÜÌ·","ÒìÊÀ½çĞĞ¼Ç","ºÚÓ§Ç¹","îáÃ¬","°×Ó§Ç¹"};
					
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
	SetConsoleTitle("ÓÀÔ¶±£µ×");
	int i,draw_num,upflag;
	upflag=0;
	srand(time(0));
	printf("upÎåĞÇ£ºÎÂµÏ	upËÄĞÇ£ºĞÁìÍ¡¢µÏ°ÂÄÈ¡¢É°ÌÇ\n");
	printf("0£ºµ¥³é		1£ºÊ®Á¬\n");
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

