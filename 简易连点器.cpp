#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define START (GetKeyState(VK_MENU)<0)
#define STOP (GetKeyState(VK_SPACE)<0)
#define END (GetKeyState(VK_ESCAPE)<0)
#define SET (GetKeyState('S')<0 && GetKeyState('E')<0 && GetKeyState('T')<0)

void go(int i,int j);//光标定位
void color(int i);//设置文本颜色

void setRate();//设置点击频率

void closed();//状态显示 未开始
void run();//开始运行
void setting();//设置频率
void stop();//停止

int rate;//点击频率
int times=0;//点击次数

int main(){
    system("mode con cols=40 lines=10");//设置窗口的行数和列数
    CONSOLE_CURSOR_INFO consoleCursorInfo = {1,0};//隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorInfo);
    SetWindowPos(GetForegroundWindow(),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);//将窗口置顶
    SetConsoleTitle("简易连点器");//设置窗口标题

    color(15);
    go(1,1);
        cout<<"按下[Alt]开始点击";
    go(1,2);
        cout<<"按下[Space]暂停点击";
    go(1,3);
        cout<<"按下[S][E][T]更改频率: "<<rate<<"次/s ";
    go(1,4);
        cout<<"按下[Esc]显示点击次数";
    go(1,7);
        cout<<"当前状态: ";
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
    cout<<"(请输入)";
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
    cout<<"按下[S][E][T]更改频率: "<<rate<<"次/s ";
}

void closed(){
    go(6,7);
    color(175);
    cout<<"未开始点击";
}

void run(){
    go(6,7);
    color(79);
    cout<<"点击中";
    color(15);
    cout<<" ";
}

void setting(){
    go(6,7);
    color(159);
    cout<<"设置中";
}

void stop(){
    go(6,7);
    color(240);
    cout<<"程序结束";
    color(15);
    cout<<" ";
    go(1,8);
	color(15);
	cout<<"共点击"<<times<<"次"<<endl<<"   ";
	color(8);
	system("pause");

}

void go(int x,int y){
    COORD coord; //COORD 是表示一个字符在控制台屏幕上的坐标 
    coord.X = x*2;
    coord.Y = y;
    HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);//句柄 
    SetConsoleCursorPosition(a,coord);
}

void color(int a){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}




