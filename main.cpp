#include "head1.h"
using namespace std;


int main() {
	//cout << isnumber("12.3", 0) << endl;
	vector<int> a;        // �ͻ���Ʊ��������[�������ͣ����򣬿�Ʊ���ͣ���λ����ݣ�Ʊ��]
	vector<luggage> bags;     // �ͻ���������
	int outrule = 0;      // �ж����������ߴ��Ƿ���Ϲ涨
	float cost = 0;          // �����֧���ķ���
	a = menu();
	bags = sizeweight(outrule);
	if (outrule) {
		system("pause");
		return 0;           // ��������Ϲ涨��ֱ���˳�
	}
	if (a[0] == 1) {
		cost = round(inchina(a, bags));      // ���ں��߼���
	}
	else if (a[0] == 2) {
		cost = interfly(a, bags);      // ���ʺ��߼���
	}

	cout << endl << "����Ҫ֧���������˷��ã�" << cost << "Ԫ" << endl;
	

	system("pause");
	return 0;
}