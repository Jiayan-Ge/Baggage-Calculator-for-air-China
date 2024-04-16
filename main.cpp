#include "head1.h"
using namespace std;


int main() {
	//cout << isnumber("12.3", 0) << endl;
	vector<int> a;        // 客户机票属性向量[航班类型，区域，客票类型，舱位，身份，票价]
	vector<luggage> bags;     // 客户行李数组
	int outrule = 0;      // 判断行李重量尺寸是否符合规定
	float cost = 0;          // 需额外支付的费用
	a = menu();
	bags = sizeweight(outrule);
	if (outrule) {
		system("pause");
		return 0;           // 有行李不符合规定，直接退出
	}
	if (a[0] == 1) {
		cost = round(inchina(a, bags));      // 国内航线计算
	}
	else if (a[0] == 2) {
		cost = interfly(a, bags);      // 国际航线计算
	}

	cout << endl << "您需要支付额外托运费用：" << cost << "元" << endl;
	

	system("pause");
	return 0;
}