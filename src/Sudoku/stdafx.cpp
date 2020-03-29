#include<iostream>//iostream.h是input output stream的简写，意思为标准的输入输出流头文件。它包含：（1）cin >> "要输入的内容"（2）cout << "要输出的内容"
#include<string>
using namespace std;
//后缀为.h的头文件C++标准已经明确提出不支持了，早些的实现将标准库功能定义在全局空间里，声明在带.h后缀的头文件里，C++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用后缀.h。因此，当使用<iostream.h>时，相当于在c中调用库函数，使用的是全局命名空间，也就是早期的c++实现；当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std；这样才能正确使用cout。
string num[10];
bool check(int x, int y, int n) {
//编写check （x,y,n）函数,如果x,y,都落在0到n-1之间，那么使得check函数返回1，否则返回0。
		for (int i = 0; i < 9; i++) {
		if (num[x][i] - '0' == n)return false;//p[i]-'0'表示数字0~9，如'7'-'0'=7
		if (num[i][y] - '0' == n)return false;
	}
	//开始判断同色九宫格
	int a = x / 3 * 3;//九宫格在程序内是由一个二维数组a[3][3]组成，二维数组的值的变化则可表示九宫格数字位置的变化！利用x，y标记二维数组中空的位置
	int b = a + 3;
	int c = y / 3 * 3;
	int d = c + 3;
	for (int i = a; i < b; i++) {
		for (int j = c; j < d; j++) {
			if (num[i][j] - '0' == n)return false;
		}
	}
	return true;
}

void DFS(int x, int y) { //深度优先搜索
	if (x > 8) { //排除不符合条件的   
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << num[i][j];  //满足条件输出   
			}
			cout << endl;
		}
		return;
	}

	if (num[x][y] != '0') {
		DFS(x + (y + 1) / 9, (y + 1) % 9);

	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check(x, y, i)) {
				num[x][y] = i + '0';
				DFS(x + (y + 1) / 9, (y + 1) % 9);
				num[x][y] = '0';
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> num[i]; //输入文件（数字）
	}
	DFS(0, 0); //从左上角开始搜索  
	return 0;
}