#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define STARS "############################"

struct luggage {
	int kind;
	float wt;
	float a;
	float b;
	float c;
};

// 开始菜单显示、获取客票属性函数
vector<int> menu();

// 获取行李件数、重量、尺寸、类型函数
vector<luggage> sizeweight(int& outrule);

//判断输入是否为数字
bool isnumber(string str, bool isfloat);

//判断单个输入是否在合理范围内
bool input_verify(int min, int max, int value);

//国内航线计价
float inchina(vector<int> a, vector<luggage> bags);

// 国际航线计算超件数收费
float overnum(int num, int limit, int region);

// 国际航线所有普通行李超重超尺寸收费
float overwtsize(vector<luggage> bags, int wlimit, int region);

// 国外航线特殊行李计价
float speccost(luggage bag);

// 国外航线计价
float interfly(vector<int> a, vector<luggage> bags);