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
	int  dd;                   //��ʼ��pc
};

typedef struct spcb pcb;
pcb producter, consumer, current, * process, * process1;
int s1, s2;                   //s1Ϊ�ջ�����������s2Ϊ������������
int i, j, in, in2, out, out2, pc;
char array[10];               //��ʱ���
char array1[10];              //������
int pa[5], sa[5];             //��Ϊ����߳�

void init()                                            //��ʼ������
{
	s1 = 10;                                          //s1��ʾ�ջ�����������
	s2 = 0;                                           //s2��ʾ��������������
	producter.name = 'p';                             //�������߽��̳�ʼ��
	producter.state = 'Y';
	producter.waitreason = ' ';
	producter.dd = 0;
	consumer.name = 'c';                            //�������߽��̳�ʼ��
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
		//std::cout << "��������\n" ;            //N��ʾ����
		process->waitreason = 's';
	}
	else
	{
		process->state = 'Y';                 // Y��ʾ����
	}
	return(s1);
}
/*void P() {
	if (current == producter)
	{
		int a = s1;
		if (a <= 0)
		{
			std::cout << "������ִ��P����---�����߽���ȴ�״̬��(�ȴ�ԭ��S1)---������ִ����P������s1 = " << s1 << "��s2 = " << s2 << std::endl;
			std::cout << "----------------------------------" << std::endl;
			process->state = 'Y';
			producter.waitreason = 's';
		}
		else
		{
			cout << "������ִ��P����---�����߽���δ������������ִ��---������ִ����P������s1 = " << s1 << "��s2 = " << s2 << std::endl;
			cout << "----------------------------------" << endl;
		}
	}
	else if (Current == Consumer)
	{
		int b = s2;
		if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0 && B[4] == 0
			B[5] == 0 && B[6] == 0 && B[7] == 0 && B[8] == 0 && B[9] == 0)
		{
			cout << "������ִ��P����---�����߽���ȴ�״̬��(�ȴ�ԭ��S2)---������ִ����P������s1=" << s1 << "��s2=" << s2 << endl;
			cout << "----------------------------------" << endl;
			Consumer.state = Waiting;
			Consumer.reason = S2;
		}
		else
		{
			cout << "������ִ��P����---�����߽���δ������������ִ��---������ִ����P������s1=" << s1 << "��s2=" << s2 << endl;
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
	return arr[abs(rand() % 10)];                      //�����ȡ����һ��
}
void produce()
{
	Sleep(1005);                                      //��������ٶ�
	array[in] = RanChar();
	in = (in + 1) % 10;
	std::cout << " ����һ���ַ��� " << array[in - 1] << std::endl;
}
void consume()
{
	Sleep(1005);
	char x;
	int m;
	x = array1[out2];
	std::cout << "����" << x << "�ַ�";
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
	std::cout << ",���ĺ󻺳������" << k << "����Ʒ\n";
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
	std::cout << "���뻺���,����󻺳������" << k << "����Ʒ\n";
	array[out] = ' ';
	out = (out + 1) % 10;
}
void get()
{
	char x;
	Sleep(1005);
	x = array1[out2];
	std::cout << "�ӻ������еõ�һ���ַ� ��" << x << std::endl;
}
void GOTO()                    //goto����������
{
	pc = 0;
}
void bornpa()                  //�������߳���װ��pa[]��
{
	for (i = 0; i <= 4; i++)
	{
		pa[i] = i;
	}
}
void bornsa()                 //�������߳���װ��sa[]��
{
	for (i = 0; i <= 4; i++)
	{
		sa[i] = i;
	}
}
void diaodu()                 //���������ȳ���
{
	int y = 1;
	char x;
	init();
	while ((producter.state == 'Y') || (consumer.state == 'Y'))
	{
		x = rand();//x������һ����
		x = x % 2;//��Xȡ��
		if (x == 0)//��X�����㣬��ִ�������߽��̣���ִ֮�������߽���
		{
			process = &producter;//process��ʾ���н��̣������н�����Ϊ�����߽���
			process1 = &consumer;
		}
		else
		{
			process = &consumer;
			process1 = &producter;
		}
		pc = process->dd;
		i = pc;//��ʱ��PC��ֵ����i
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
			case 2: std::cout << "������ִ��P����" << std::endl;
				put();
				process->state = 'Y';
				process->dd = pc;
				break;
			case 3: s2 = v(s2);
				process->dd = pc;
				std::cout << "������ִ��V����\n";
				break;
			case 4: GOTO();
				process->state = 'Y';
				process->dd = pc;
				std::cout << "������ִ��goto����\n";
				break;
			}
			y++;
		}
		else if ((process->name == 'c') && (process->state == 'Y') && y <= 50)//ִ�������߽����Ҹý��̴��ھ���״̬
		{
			process->state = 'Y';
			j = sa[i];
			pc = i + 1;
			switch (j)
			{
			case 0: s2 = p(s2); process->dd = pc;
				break;//������Դ����û�����뵽����ת
			case 1: std::cout << "������ִ��P����\n"; get(); process->dd = pc;
				break;
			case 2: s1 = v(s1); process->dd = pc; std::cout << "������ִ��V����\n";
				break;
			case 3: consume(); process->dd = pc;
				break;
			case 4: GOTO(); process->state = 'Y'; process->dd = pc; std::cout << "������ִ��goto����\n";
				break;
			}
			y++;
		}
		//y++;
	}
}
void disp() //����������ʾ����,������ʾ��ǰ����
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