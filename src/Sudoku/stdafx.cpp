#include<iostream>//iostream.h��input output stream�ļ�д����˼Ϊ��׼�����������ͷ�ļ�������������1��cin >> "Ҫ���������"��2��cout << "Ҫ���������"
#include<string>
using namespace std;
//��׺Ϊ.h��ͷ�ļ�C++��׼�Ѿ���ȷ�����֧���ˣ���Щ��ʵ�ֽ���׼�⹦�ܶ�����ȫ�ֿռ�������ڴ�.h��׺��ͷ�ļ��C++��׼Ϊ�˺�C���𿪣�ҲΪ����ȷʹ�������ռ䣬�涨ͷ�ļ���ʹ�ú�׺.h����ˣ���ʹ��<iostream.h>ʱ���൱����c�е��ÿ⺯����ʹ�õ���ȫ�������ռ䣬Ҳ�������ڵ�c++ʵ�֣���ʹ��<iostream>��ʱ�򣬸�ͷ�ļ�û�ж���ȫ�������ռ䣬����ʹ��namespace std������������ȷʹ��cout��
string num[10];
bool check(int x, int y, int n) {
//��дcheck ��x,y,n������,���x,y,������0��n-1֮�䣬��ôʹ��check��������1�����򷵻�0��
		for (int i = 0; i < 9; i++) {
		if (num[x][i] - '0' == n)return false;//p[i]-'0'��ʾ����0~9����'7'-'0'=7
		if (num[i][y] - '0' == n)return false;
	}
	//��ʼ�ж�ͬɫ�Ź���
	int a = x / 3 * 3;//�Ź����ڳ���������һ����ά����a[3][3]��ɣ���ά�����ֵ�ı仯��ɱ�ʾ�Ź�������λ�õı仯������x��y��Ƕ�ά�����пյ�λ��
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

void DFS(int x, int y) { //�����������
	if (x > 8) { //�ų�������������   
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << num[i][j];  //�����������   
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
		cin >> num[i]; //�����ļ������֣�
	}
	DFS(0, 0); //�����Ͻǿ�ʼ����  
	return 0;
}