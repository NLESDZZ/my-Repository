#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define START (GetKeyState(VK_MENU)<0)
#define STOP (GetKeyState(VK_SPACE)<0)
#define END (GetKeyState(VK_ESCAPE)<0)
#define SET (GetKeyState('S')<0 && GetKeyState('E')<0 && GetKeyState('T')<0)

void go(int i,int j);//��궨λ
void color(int i);//�����ı���ɫ

void setRate();//���õ��Ƶ��

void closed();//״̬��ʾ δ��ʼ
void run();//��ʼ����
void setting();//����Ƶ��
void stop();//ֹͣ

int rate;//���Ƶ��
int times=0;//�������

int main(){
    system("mode con cols=40 lines=10");//���ô��ڵ�����������
    CONSOLE_CURSOR_INFO consoleCursorInfo = {1,0};//���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorInfo);
    SetWindowPos(GetForegroundWindow(),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);//�������ö�
    SetConsoleTitle("����������");//���ô��ڱ���

    color(15);
    go(1,1);
        cout<<"����[Alt]��ʼ���";
    go(1,2);
        cout<<"����[Space]��ͣ���";
    go(1,3);
        cout<<"����[S][E][T]����Ƶ��: "<<rate<<"��/s ";
    go(1,4);
        cout<<"����[Esc]��ʾ�������";
    go(1,7);
        cout<<"��ǰ״̬: ";
    while (!START){
        Sleep(100);
        closed();
        if(SET){
            setRate();
            closed();
        }
        if(END){
            stop();
            return 0;
        }
    }
    run();
    while(!END){
        if(STOP){
            closed();
            while(!START){
                if(SET){
                    setRate();
                    closed();
                }
                if(END){
                    stop();
                    return 0;
                }
                Sleep(100);
            }
            run();
        }
        if(SET){
            setRate();
            run();
        }
        mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
        Sleep(500/rate);
        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        Sleep(500/rate);
        times++;
    }
    stop();
    return 0;
}

void setRate(){
    setting();
    CONSOLE_CURSOR_INFO consoleCursorInfo = {1,1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorInfo);
    go(15,3);
    color(8);
    cout<<"(������)";
    go(15,3);
    color(15);
    rate = 0;
    char a;
    a=getchar();
    while(a!='\n'){
        if(a<='9' && a>='0')
            rate = rate*10 + (a-'0');
        a=getchar();
    }
    CONSOLE_CURSOR_INFO consoleCursorInfo1 = {1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorInfo1);
    if(rate > 500){
        setRate();
        return;
    }
    go(1,3);
    cout<<"����[S][E][T]����Ƶ��: "<<rate<<"��/s ";
}

void closed(){
    go(6,7);
    color(175);
    cout<<"δ��ʼ���";
}

void run(){
    go(6,7);
    color(79);
    cout<<"�����";
    color(15);
    cout<<" ";
}

void setting(){
    go(6,7);
    color(159);
    cout<<"������";
}

void stop(){
    go(6,7);
    color(240);
    cout<<"�������";
    color(15);
    cout<<" ";
    go(1,8);
	color(15);
	cout<<"�����"<<times<<"��"<<endl<<"   ";
	color(8);
	system("pause");

}

void go(int x,int y){
    COORD coord; //COORD �Ǳ�ʾһ���ַ��ڿ���̨��Ļ�ϵ����� 
    coord.X = x*2;
    coord.Y = y;
    HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);//��� 
    SetConsoleCursorPosition(a,coord);
}

void color(int a){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}




