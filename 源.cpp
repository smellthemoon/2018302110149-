#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#define NULL 0

struct spcb
{
	char name;
	char state;
	char waitreason;
	int  dd;                   //初始化pc
};

typedef struct spcb pcb;
pcb producter, consumer, current, * process, * process1;
int s1, s2;                   //s1为空缓冲区数量，s2为满缓冲区数量
int i, j, in, in2, out, out2, pc;
char array[10];               //临时存放
char array1[10];              //缓冲区
int pa[5], sa[5];             //分为五个线程

void init()                                            //初始化程序
{
	s1 = 10;                                          //s1表示空缓冲区的数量
	s2 = 0;                                           //s2表示满缓冲区的数量
	producter.name = 'p';                             //对生产者进程初始化
	producter.state = 'Y';
	producter.waitreason = ' ';
	producter.dd = 0;
	consumer.name = 'c';                            //对消费者进程初始化
	consumer.state = 'Y';
	consumer.waitreason = ' ';
	consumer.dd = 0;
	for (int k = 0; k < 10; k++)
	{
		array[k] = ' ';
	}
	for (int k = 0; k < 10; k++)
	{
		array1[k] = ' ';
	}
}
int p(int s1)
{
	s1 = s1 - 1;
	if (s1 < 0)
	{
		process->state = 'N';
		//std::cout << "发生阻塞\n" ;            //N表示阻塞
		process->waitreason = 's';
	}
	else
	{
		process->state = 'Y';                 // Y表示就绪
	}
	return(s1);
}
/*void P() {
	if (current == producter)
	{
		int a = s1;
		if (a <= 0)
		{
			std::cout << "生产者执行P操作---生产者进入等待状态！(等待原因：S1)---生产者执行完P操作后，s1 = " << s1 << "、s2 = " << s2 << std::endl;
			std::cout << "----------------------------------" << std::endl;
			process->state = 'Y';
			producter.waitreason = 's';
		}
		else
		{
			cout << "生产者执行P操作---生产者进程未被阻塞，继续执行---生产者执行完P操作后，s1 = " << s1 << "、s2 = " << s2 << std::endl;
			cout << "----------------------------------" << endl;
		}
	}
	else if (Current == Consumer)
	{
		int b = s2;
		if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0 && B[4] == 0
			B[5] == 0 && B[6] == 0 && B[7] == 0 && B[8] == 0 && B[9] == 0)
		{
			cout << "消费者执行P操作---消费者进入等待状态！(等待原因：S2)---消费者执行完P操作后，s1=" << s1 << "、s2=" << s2 << endl;
			cout << "----------------------------------" << endl;
			Consumer.state = Waiting;
			Consumer.reason = S2;
		}
		else
		{
			cout << "消费者执行P操作---消费者进程未被阻塞，继续执行---消费者执行完P操作后，s1=" << s1 << "、s2=" << s2 << endl;
		}
	}
}*/
int v(int s2)
{
	s2 = s2 + 1;
	if (s2 <= 0)
	{
		process1->state = 'Y';
	}
	process->state = 'Y';
	return(s2);
}

char RanChar()
{
	char arr[10] = { 'Z','U','R','I','N','I','S','E','A','N' };
	return arr[abs(rand() % 10)];                      //随机抽取其中一个
}
void produce()
{
	Sleep(1005);                                      //减缓输出速度
	array[in] = RanChar();
	in = (in + 1) % 10;
	std::cout << " 生产一个字符： " << array[in - 1] << std::endl;
}
void consume()
{
	Sleep(1005);
	char x;
	int m;
	x = array1[out2];
	std::cout << "消耗" << x << "字符";
	array1[out2] = ' ';
	out2 = (out2 + 1) % 10;
	int k = 0;
	for (m = 0; m < 10; m++)
	{
		if (array1[m] != ' ')
		{
			k = k + 1;
		}

	}
	std::cout << ",消耗后缓冲池中有" << k << "个产品\n";
}
void put()
{
	Sleep(1005);
	int m;
	array1[in2] = array[in - 1];
	in2 = (in2 + 1) % 10;
	int k = 0;
	for (m = 0; m < 10; m++)
	{
		if (array1[m] != ' ') {

			k = k + 1;
		}

	}
	std::cout << "放入缓冲池,放入后缓冲池中有" << k << "个产品\n";
	array[out] = ' ';
	out = (out + 1) % 10;
}
void get()
{
	char x;
	Sleep(1005);
	x = array1[out2];
	std::cout << "从缓冲区中得到一个字符 ：" << x << std::endl;
}
void GOTO()                    //goto后命令重置
{
	pc = 0;
}
void bornpa()                  //将生产者程序装入pa[]中
{
	for (i = 0; i <= 4; i++)
	{
		pa[i] = i;
	}
}
void bornsa()                 //将消费者程序装入sa[]中
{
	for (i = 0; i <= 4; i++)
	{
		sa[i] = i;
	}
}
void diaodu()                 //处理器调度程序
{
	int y = 1;
	char x;
	init();
	while ((producter.state == 'Y') || (consumer.state == 'Y'))
	{
		x = rand();//x随机获得一个数
		x = x % 2;//对X取余
		if (x == 0)//若X等于零，则执行生产者进程，反之执行消费者进程
		{
			process = &producter;//process表示现行进程，将现行进程置为生产者进程
			process1 = &consumer;
		}
		else
		{
			process = &consumer;
			process1 = &producter;
		}
		pc = process->dd;
		i = pc;//此时把PC的值付给i
		if ((process->name == 'p') && (process->state == 'Y') && y <= 50)
		{

			j = pa[i];
			pc = i + 1;
			switch (j)
			{
			case 0: produce(); process->state = 'Y'; process->dd = pc;
				break;
			case 1: s1 = p(s1); process->dd = pc;
				break;
			case 2: std::cout << "生产者执行P操作" << std::endl;
				put();
				process->state = 'Y';
				process->dd = pc;
				break;
			case 3: s2 = v(s2);
				process->dd = pc;
				std::cout << "生产者执行V操作\n";
				break;
			case 4: GOTO();
				process->state = 'Y';
				process->dd = pc;
				std::cout << "生产者执行goto操作\n";
				break;
			}
			y++;
		}
		else if ((process->name == 'c') && (process->state == 'Y') && y <= 50)//执行消费者进程且该进程处于就绪状态
		{
			process->state = 'Y';
			j = sa[i];
			pc = i + 1;
			switch (j)
			{
			case 0: s2 = p(s2); process->dd = pc;
				break;//申请资源，若没有申请到则跳转
			case 1: std::cout << "消费者执行P操作\n"; get(); process->dd = pc;
				break;
			case 2: s1 = v(s1); process->dd = pc; std::cout << "消费者执行V操作\n";
				break;
			case 3: consume(); process->dd = pc;
				break;
			case 4: GOTO(); process->state = 'Y'; process->dd = pc; std::cout << "消费者执行goto操作\n";
				break;
			}
			y++;
		}
		//y++;
	}
}
void disp() //建立进程显示函数,用于显示当前进程
{
	std::cout << "\n name \t state \t waitreason \t dd  \n";
	std::cout << process->name << "   " << process->state << "   " << process->waitreason << "   " << process->dd << std::endl;
}
int main()
{
	init();
	bornpa();
	bornsa();
	diaodu();
	disp();
}