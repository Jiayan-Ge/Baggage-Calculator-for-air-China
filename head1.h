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

// ��ʼ�˵���ʾ����ȡ��Ʊ���Ժ���
vector<int> menu();

// ��ȡ����������������ߴ硢���ͺ���
vector<luggage> sizeweight(int& outrule);

//�ж������Ƿ�Ϊ����
bool isnumber(string str, bool isfloat);

//�жϵ��������Ƿ��ں���Χ��
bool input_verify(int min, int max, int value);

//���ں��߼Ƽ�
float inchina(vector<int> a, vector<luggage> bags);

// ���ʺ��߼��㳬�����շ�
float overnum(int num, int limit, int region);

// ���ʺ���������ͨ����س��ߴ��շ�
float overwtsize(vector<luggage> bags, int wlimit, int region);

// ���⺽����������Ƽ�
float speccost(luggage bag);

// ���⺽�߼Ƽ�
float interfly(vector<int> a, vector<luggage> bags);