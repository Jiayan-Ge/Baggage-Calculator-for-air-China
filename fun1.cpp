#include "head1.h"
using namespace std;

// ��ʼ�˵���ʾ����
vector<int> menu() {      
	vector<int> a;

	cout << STARS << STARS << endl;
	cout << "#                 Baggage Calculator                   #" << endl;
	cout << STARS << STARS << endl;

	string tempinput;
	int isabroad;
	do {
		cout << endl << ">�������ͣ�1.���ں��ߣ��۰�̨���⣩         2.���ʺ���" << endl;
		cout << "�������Ӧ������ţ�";
		cin >> tempinput;
		isabroad = atoi(tempinput.c_str());
	} while ((! isnumber(tempinput, 0)) || input_verify(1, 2, isabroad));
	a.push_back(isabroad);

	int region = 0;
	if (isabroad == 2) {
		do{
			cout << endl << ">��������" << endl;
			cout << "  1-����1�����ޣ�������/���ô��⣩/���ձȺ�������ŷ��/����/�ж�/����/����̫ƽ��֮��ĺ���" << endl;
			cout << "  2-����2��ŷ��/�ж������/����/����̫ƽ��֮�亽�ߣ��ձ�������̫ƽ��֮�亽�ߣ��ձ� / ����̫ƽ�������ޣ������ձ�������̫ƽ��"
				"/ ����֮�亽��" << endl;
			cout << "  3-����3�����ô������ޣ�������/���ô��⣩/���ձȺ�����/ŷ��/����/�ж�/����/����̫ƽ��֮�亽��" << endl;
			cout << "  4-����4���������������ģ������ޣ��������⣩/���ձȺ�����/ŷ��/����/�ж�/����/����̫ƽ��֮�亽��" << endl;
			cout << "  5-����5�����������ޣ����ձ���)֮�亽�ߣ�ŷ�����ж�֮�亽�ߣ����ޣ����ձ�)�ں��ߣ����ޣ������� / ���ô󣩼����ձȺ������ں�"
				"�ߣ�����δ�����ĺ���; " << endl;
			cout << "�������Ӧ������ţ�";
			cin >> tempinput;
			region = atoi(tempinput.c_str());
		} while ((!isnumber(tempinput, 0)) || input_verify(1, 5, region));
	}
	else if (isabroad == 1) {
		do {
			cout << endl << ">�������� 0-���ڣ��۰�̨���⣩" << endl;
			cout << "�������Ӧ������ţ�";
			cin >> tempinput;
			region = atoi(tempinput.c_str());
			if (region != 0) {
				cout << "��������������������ȷ������" << endl;
			}
		} while ((!isnumber(tempinput, 0)) || region != 0);
	}
	a.push_back(region);

	int isbaby = 0;
	do {
		cout << endl << ">��Ʊ���ͣ�1.����/��ͯ��Ʊ�ÿ�              2.Ӥ����Ʊ�ÿ�" << endl;
		cout << "�������Ӧ������ţ�";
		cin >> tempinput;
		isbaby = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 2, isbaby));
	a.push_back(isbaby);

	int level = 0;
	do {
		cout << endl << ">��λ���ͣ�1.ͷ�Ȳ�        2.�����        3.����/�������ò�        4.���ò�" << endl;
		cout << "�������Ӧ������ţ�";
		cin >> tempinput;
		level = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 4, level));
	a.push_back(level);

	int vip = 0;
	do {
		cout << endl << ">������ͣ�1.��ͨ�ÿ�        2.���֪������׽𿨡��׽��ÿ�        3.���֪���𿨡������ÿ�        4.�ǿ����˽��ÿ�" << endl;
		cout << "�������Ӧ������ţ�";
		cin >> tempinput;
		vip = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 4, vip));
	a.push_back(vip);

	float ticket = 0;
	do {
		cout << endl << ">����ֱ�ﾭ�ò���ͨƱ�ۣ�Ԫ����";
		cin >> tempinput;
	} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
	ticket = stof(tempinput);
	a.push_back(ticket);

	return a;
}

// ��������������������ߴ硢���ͺ���
vector<luggage> sizeweight(int& outrule) {
	string tempinput;
	int num = 0;
	do {
		cout << endl << ">���������������";
		cin >> tempinput;
		num = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(0, 0, num));
	vector<luggage> bags;

	cout << endl << "*�������ͣ�" << endl <<
		"  0-��ͨ����" << endl <<
		"  1-�綯���Ρ��綯�������ߡ��ֶ��۵����Ρ���е��֫��ר��С����ƿ����������������ֲ�������װ�á���Яʽ����Ũ������POC����"
		"������ѹ��������CPAP���������ں�﮵�صĸ����豸�ȡ��۵�ʽӤ������ҡ����Ӥ��������ȫ���η���Ȯ������ר��ѵ��Ϊ�м�������"
		"�͹����ṩЭ��������Ȯ����������äȮ������Ȯ������Ȯ��" << endl <<
		"  2-�߶�������������򡢻���ɡ/����ɡ����ѩ/��ˮ�þߣ�������ѩ�� / ˮ�ˣ����ֻ� / �����þߡ�Ǳˮ�þߡ�����þߡ��������þߡ�����"
		"�þߡ������þߡ���ɽ�þߡ����г���" << endl <<
		"  3-Ƥ��ͧ/��ľ�ۡ�����ʽ�����˶��þߡ�ѩ��/ˮ�ˡ����˰塢�緫�����þߡ���Ƥͧ�򴬡�" << endl <<
		"  4-�Ÿˡ���ǹ��������װ�Ļ����þ߻򽬡������þߡ�" << endl <<
		"  5-˯����������ҰӪ�þߡ���ߡ������������豸���ǲм����ˡ����ÿ����ˣ������۵�Ӥ���������۵�Ӥ������Ӥ��ҡ����Ӥ��������ȫ��"
		"�Σ���Ӥ���ÿ����ˣ���" << endl <<
		"  6-С�͵�����������ý���豸��" << endl <<
		"  7-����Ϊ���������ǹ֧��" << endl <<
		"  8-����Ϊ����������ӵ���" << endl <<
		"  9-С������޼�ͥѱ����è��������}"
		<< endl;

	for (int i = 0; i < num; i++) {
		luggage  cur;
		do {
			cout << "����" << i + 1 << ":" << endl;
			cout << "	  �������������Ͷ�Ӧ���֣�";
			cin >> tempinput;
			cur.kind = atoi(tempinput.c_str());
		} while ((!isnumber(tempinput, 0)) || input_verify(0, 9, cur.kind));
		do {
			cout << "	  ������������kg����";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.wt = stof(tempinput);
		if ((cur.kind == 0 || cur.kind == 6 || cur.kind == 7 || cur.kind == 9) && (cur.wt < 2 || cur.wt > 32)) {
			cout << "����" << i + 1 << "���������Ϲ涨���޷�����" << endl;
			outrule = 1;
			return bags;
		}
		else if ((cur.kind == 3 || cur.kind == 4) && (cur.wt < 2 || cur.wt > 45)) {
			cout << "����" << i + 1 << "���������Ϲ涨���޷�����" << endl;
			outrule = 1;
			return bags;
		}
		else if ((cur.kind == 8) && (cur.wt < 2 || cur.wt > 5)) {
			cout << "����" << i + 1 << "���������Ϲ涨���޷�����" << endl;
			outrule = 1;
			return bags;
		}
		do {
			cout << "	  �����������cm����";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.a = stof(tempinput);
		do {
			cout << "          �����������cm����";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.b = stof(tempinput);
		do {
			cout << "	  ����������ߣ�cm����";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.c = stof(tempinput);
		if (cur.a + cur.b + cur.c < 60 || cur.a + cur.b + cur.c > 203) {
			cout << "����" << i+1 << "�ߴ粻���Ϲ涨���޷�����" << endl;
			outrule = 1;
			break;
		}
		bags.push_back(cur);
	}
	return bags;
}

//�ж������Ƿ�Ϊ����, isfloatΪ1�ж������Ƿ�Ϊ������
bool isnumber(string str, bool isfloat) {
	if (str[0] != 45)    // Ҫ�Ѹ���ժ��
	{
		for (int i = 0; i < str.length(); i++)    // ��һ�ַ�����
		{
			if (isfloat && str[i] != '.') {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "��������ȷ������" << endl;
					return false;
				}
			}
			else if (!isfloat) {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "��������ȷ������" << endl;
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		for (int i = 1; i < str.length(); i++)
		{
			if (isfloat && str[i] != '.') {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "��������ȷ������" << endl;
					return false;
				}
			}
			else if (!isfloat) {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "��������ȷ������" << endl;
					return false;
				}
			}
		}
		return true;
	}
}

//�жϵ��������Ƿ��ں���Χ��
bool input_verify(int min,	int max, int value) {
	if (value < min || (min != max && value > max)) {
		cout << "��������������������ȷ������" << endl;
		return true;
	}
	return false;
}

//���ں��߼Ƽ�
float inchina(vector<int> a, vector<luggage> bags) {
	int num = bags.size();
	float price = 0;
	float sumwt0 = 0;   // ���������������������
	float sumwt1 = 0;   // ���������в�������������֣�ֱ�Ӽ��뵽�������
	float overwt = 0;    // �����ܳ������
	for (int i = 0; i < num; i++) {   // ���������������ȵ�����������
		if (bags[i].kind == 0 || bags[i].kind == 2 || bags[i].kind == 5) {
			sumwt0 += bags[i].wt;
		}
		else if (bags[i].kind == 1) {
			sumwt0 += 0;
		}
		else {
			sumwt1 += bags[i].wt;
		}
	}

	if (a[2] == 1) {    // ����/��ͯƱ
		if (a[3] == 1) {      // ͷ�Ȳ�
			if (a[4] == 1) {     // ��ͨ�ÿ�
				overwt += (sumwt0 - 40);
			}
			else if(a[4] == 2) {      // ��˰׽�
				overwt += (sumwt0 - 70);
			}
			else if (a[4] == 3 || a[4] == 4) {   //���֪����/�ǿ����˽�
				overwt += (sumwt0 - 60);
			}
		}
		else if (a[3] == 2) {   // �����
			if (a[4] == 1) {     // ��ͨ�ÿ�
				overwt += (sumwt0 - 30);
			}
			else if (a[4] == 2) {      // ��˰׽�
				overwt += (sumwt0 - 60);
			}
			else if (a[4] == 3 || a[4] == 4) {   //���֪����/�ǿ����˽�
				overwt += (sumwt0 - 50);
			}
		}
		else if (a[3] == 3 || a[3] == 4) {   // �����òա����ò�
			if (a[4] == 1) {     // ��ͨ�ÿ�
				overwt += (sumwt0 - 20);
			}
			else if (a[4] == 2) {      // ��˰׽�
				overwt += (sumwt0 - 50);
			}
			else if (a[4] == 3 || a[4] == 4) {   //���֪����/�ǿ����˽�
				overwt += (sumwt0 - 40);
			}
		}
	}
	else if (a[2] == 2) {     // Ӥ��Ʊ
		if (a[4] == 1) {     // ��ͨ�ÿ�
			overwt += (sumwt0 - 10);
		}
		else if (a[4] == 2) {      // ��˰׽�
			overwt += (sumwt0 - 40);
		}
		else if (a[4] == 3 || a[4] == 4) {   //���֪����/�ǿ����˽�
			overwt += (sumwt0 - 30);
		}
	}
	overwt = (overwt > 0 ? overwt + sumwt1 : sumwt1);
	price = overwt * 0.015 * a[5];
	return price;
}

// �������շѺ���
float overnum(int num, int limit, int region) {   // num-�ܼ�����limit-��Ѷ�ȣ�region-����
	float cost = 0;
	int over1 = 0, over2 = 0, over3 = 0;
	switch (region) {
	case 1:
		cost += (num >= limit + 3 ? 3000 * (num - limit - 2) : 0);
		cost += (num >= limit + 2 ? 2000 : 0);
		cost += (num >= limit + 1 ? 1400 : 0);
		break;
	case 2:
		cost += (num >= limit + 3 ? 1590 * (num - limit - 2) : 0);
		cost += (num >= limit + 2 ? 1100 : 0);
		cost += (num >= limit + 1 ? 1100 : 0);
		break;
	case 3:
		cost += (num >= limit + 3 ? 1590 * (num - limit - 2) : 0);
		cost += (num >= limit + 2 ? 1170 : 0);
		cost += (num >= limit + 1 ? 1170 : 0);
		break;
	case 4:
		cost += (num >= limit + 3 ? 1590 * (num - limit - 2) : 0);
		cost += (num >= limit + 2 ? 1380 : 0);
		cost += (num >= limit + 1 ? 1380 : 0);
		break;
	case 5:
		cost += (num >= limit + 3 ? 1590 * (num - limit - 2) : 0);
		cost += (num >= limit + 2 ? 1100 : 0);
		cost += (num >= limit + 1 ? 830 : 0);
		break;
	default:
		cost += 0;
		break;
	}
	return cost;
}

// ���ʺ���������ͨ�����Լ����ּ��������ĳ��س��ߴ��շѺ���
float overwtsize(vector<luggage> bags, int wlimit, int region) {   // bags-�������wlimit-�������ƣ�region-����
	float cost = 0;
	int num = bags.size();
	int sumsize = 0;
	for (int i = 0; i < num; i++) {
		if (bags[i].kind == 0 || bags[i].kind == 2 || bags[i].kind == 5) {
			sumsize = bags[i].a + bags[i].b + bags[i].c;
			switch (region) {
			case 1:
				cost += (bags[i].wt > wlimit && bags[i].wt <= 28 && sumsize <= 158) ? 380 : 0;
				cost += (bags[i].wt > wlimit && bags[i].wt > 28 && sumsize <= 158) ? 980 : 0;
				cost += (bags[i].wt <= wlimit && sumsize > 158) ? 980 : 0;
				cost += (bags[i].wt > wlimit && sumsize > 158) ? 1400 : 0;
				break;
			case 2:
				cost += (bags[i].wt > wlimit && bags[i].wt <= 28 && sumsize <= 158) ? 280 : 0;
				cost += (bags[i].wt > wlimit && bags[i].wt > 28 && sumsize <= 158) ? 690 : 0;
				cost += (bags[i].wt <= wlimit && sumsize > 158) ? 690 : 0;
				cost += (bags[i].wt > wlimit && sumsize > 158) ? 1100 : 0;
				break;
			case 3:
				cost += (bags[i].wt > wlimit || sumsize > 158) ? 520 : 0;
				break;
			case 4:
				cost += (bags[i].wt > wlimit && bags[i].wt <= 28 && sumsize <= 158) ? 690 : 0;
				cost += (bags[i].wt > wlimit && bags[i].wt > 28 && sumsize <= 158) ? 1040 : 0;
				cost += (bags[i].wt <= wlimit && sumsize > 158) ? 1040 : 0;
				cost += (bags[i].wt > wlimit && sumsize > 158) ? 2050 : 0;
				break;
			case 5:
				cost += (bags[i].wt > wlimit && bags[i].wt <= 28 && sumsize <= 158) ? 210 : 0;
				cost += (bags[i].wt > wlimit && bags[i].wt > 28 && sumsize <= 158) ? 520 : 0;
				cost += (bags[i].wt <= wlimit && sumsize > 158) ? 520 : 0;
				cost += (bags[i].wt > wlimit && sumsize > 158) ? 830 : 0;
				break;
			}
		}
	}
	return cost;
}

// ���⺽����������Ƽ�
float speccost(luggage bag) {
	float cost = 0;
	switch (bag.kind) {
	case 3:
		cost += (bag.wt <= 23 ? 2600 : 0);
		cost += (bag.wt > 23 && bag.wt <= 32 ? 3900 : 0);
		cost += (bag.wt > 32 ? 3900 : 0);
		break;
	case 4:
		cost += (bag.wt <= 23 ? 1300 : 0);
		cost += (bag.wt > 23 && bag.wt <= 32 ? 2600 : 0);
		cost += (bag.wt > 32 ? 3900 : 0);
		break;
	case 6:
		cost += (bag.wt <= 23 ? 490 : 0);
		cost += (bag.wt > 23 ? 3900 : 0);
		break;
	case 7:
		cost += (bag.wt <= 23 ? 1300 : 0);
		cost += (bag.wt > 23 ? 2600 : 0);
		break;
	case 8:
		cost += 1300;
		break;
	case 9:
		cost += (bag.wt <= 8 ? 3900 : 0);
		cost += (bag.wt > 8 && bag.wt <= 23 ? 5200 : 0);
		cost += (bag.wt > 23 ? 7800 : 0);
		break;
	}
	return cost;
}

// ���⺽�߼Ƽ�
float interfly(vector<int> a, vector<luggage> bags) {
	float cost = 0;
	int num = bags.size(), ordnum = 0, spenum = 0;
	for (int i = 0; i < num; i++) {
		if (bags[i].kind == 0 || bags[i].kind == 2 || bags[i].kind == 5) {
			ordnum += 1;
		}
		if (bags[i].kind == 3 || bags[i].kind == 4 || bags[i].kind == 6 || bags[i].kind ==7  || bags[i].kind == 8 || bags[i].kind == 9) {
			cost += speccost(bags[i]);         // ��������Ƽ�
		}
	}
	if (a[2] == 1) {    // ����/��ͯƱ
		if (a[3] == 1 || a[3] == 2) {      // ͷ�Ȳ�/�����
			if (a[4] == 1) {     // ��ͨ�ÿ�
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3) {      // ��˰׽�/���֪����
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 4) {   // �ǿ����˽�
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
		}
		else if (a[3] == 3) {   // ����/�������ò�
			if (a[4] == 1) {     // ��ͨ�ÿ�
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3 || a[4] == 4) {      // ��˰׽�/���֪����/�ǿ����˽�
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
		else if (a[3] == 4) {   // ���ò�
			if (a[4] == 1) {     // ��ͨ�ÿ�
				if (a[1] == 1 || a[1] == 5) {
					cost += overnum(ordnum, 1, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
				else {
					cost += overnum(ordnum, 2, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
			}
			else if (a[4] == 2) {      // ��˰׽�/���֪����/�ǿ����˽�
				if (a[1] == 1 || a[1] == 5) {
					cost += overnum(ordnum, 2, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
				else {
					cost += overnum(ordnum, 3, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
			}
		}
	}
	else if (a[2] == 2) {     // Ӥ��Ʊ
		if (a[3] == 1 || a[3] == 2) {      // ͷ�Ȳ�/�����
			if (a[4] == 1) {     // ��ͨ�ÿ�
				cost += overnum(ordnum, 1, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3) {      // ��˰׽�/���֪����
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 4) {   // �ǿ����˽�
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
		else if (a[3] == 3 || a[3] == 4) {   // ����/�������òա����ò�
			if (a[4] == 1) {     // ��ͨ�ÿ�
				cost += overnum(ordnum, 1, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3 || a[4] == 4) {      // ��˰׽�/���֪����/�ǿ����˽�
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
	}
	return cost;
}