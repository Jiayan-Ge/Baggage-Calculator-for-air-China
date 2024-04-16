#include "head1.h"
using namespace std;

// 开始菜单显示函数
vector<int> menu() {      
	vector<int> a;

	cout << STARS << STARS << endl;
	cout << "#                 Baggage Calculator                   #" << endl;
	cout << STARS << STARS << endl;

	string tempinput;
	int isabroad;
	do {
		cout << endl << ">航班类型：1.国内航线（港澳台除外）         2.国际航线" << endl;
		cout << "请输入对应数字序号：";
		cin >> tempinput;
		isabroad = atoi(tempinput.c_str());
	} while ((! isnumber(tempinput, 0)) || input_verify(1, 2, isabroad));
	a.push_back(isabroad);

	int region = 0;
	if (isabroad == 2) {
		do{
			cout << endl << ">航班区域：" << endl;
			cout << "  1-区域1：美洲（除美国/加拿大外）/加勒比海地区与欧洲/非洲/中东/亚洲/西南太平洋之间的航线" << endl;
			cout << "  2-区域2：欧洲/中东与非洲/亚洲/西南太平洋之间航线；日本与西南太平洋之间航线；日本 / 西南太平洋与亚洲（不含日本及西南太平洋）"
				"/ 非洲之间航线" << endl;
			cout << "  3-区域3：加拿大与美洲（除美国/加拿大外）/加勒比海地区/欧洲/非洲/中东/亚洲/西南太平洋之间航线" << endl;
			cout << "  4-区域4：美国（含夏威夷）与美洲（除美国外）/加勒比海地区/欧洲/非洲/中东/亚洲/西南太平洋之间航线" << endl;
			cout << "  5-区域5：非洲与亚洲（除日本外)之间航线；欧洲与中东之间航线；亚洲（除日本)内航线；美洲（除美国 / 加拿大）及加勒比海地区内航"
				"线；上述未列明的航线; " << endl;
			cout << "请输入对应数字序号：";
			cin >> tempinput;
			region = atoi(tempinput.c_str());
		} while ((!isnumber(tempinput, 0)) || input_verify(1, 5, region));
	}
	else if (isabroad == 1) {
		do {
			cout << endl << ">航班区域： 0-国内（港澳台除外）" << endl;
			cout << "请输入对应数字序号：";
			cin >> tempinput;
			region = atoi(tempinput.c_str());
			if (region != 0) {
				cout << "输入有误，请重新输入正确的数字" << endl;
			}
		} while ((!isnumber(tempinput, 0)) || region != 0);
	}
	a.push_back(region);

	int isbaby = 0;
	do {
		cout << endl << ">客票类型：1.成人/儿童售票旅客              2.婴儿售票旅客" << endl;
		cout << "请输入对应数字序号：";
		cin >> tempinput;
		isbaby = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 2, isbaby));
	a.push_back(isbaby);

	int level = 0;
	do {
		cout << endl << ">舱位类型：1.头等舱        2.公务舱        3.悦享/超级经济舱        4.经济舱" << endl;
		cout << "请输入对应数字序号：";
		cin >> tempinput;
		level = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 4, level));
	a.push_back(level);

	int vip = 0;
	do {
		cout << endl << ">身份类型：1.普通旅客        2.凤凰知音终身白金卡、白金卡旅客        3.凤凰知音金卡、银卡旅客        4.星空联盟金卡旅客" << endl;
		cout << "请输入对应数字序号：";
		cin >> tempinput;
		vip = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(1, 4, vip));
	a.push_back(vip);

	float ticket = 0;
	do {
		cout << endl << ">当日直达经济舱普通票价（元）：";
		cin >> tempinput;
	} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
	ticket = stof(tempinput);
	a.push_back(ticket);

	return a;
}

// 输入行李件数、重量、尺寸、类型函数
vector<luggage> sizeweight(int& outrule) {
	string tempinput;
	int num = 0;
	do {
		cout << endl << ">请输入行李件数：";
		cin >> tempinput;
		num = atoi(tempinput.c_str());
	} while ((!isnumber(tempinput, 0)) || input_verify(0, 0, num));
	vector<luggage> bags;

	cout << endl << "*行李类型：" << endl <<
		"  0-普通行李" << endl <<
		"  1-电动轮椅、电动代步工具、手动折叠轮椅、机械假肢及专用小型气瓶、心脏起搏器或其它植入人体的装置、便携式氧气浓缩器（POC）、"
		"持续正压呼吸机（CPAP）、其它内含锂电池的辅助设备等。折叠式婴儿车或摇篮或婴儿汽车安全座椅服务犬（经过专门训练为残疾人生活"
		"和工作提供协助的特种犬，包括：导盲犬、助听犬、辅助犬）" << endl <<
		"  2-高尔夫球包、保龄球、滑翔伞/降落伞、滑雪/滑水用具（不包括雪橇 / 水撬）、轮滑 / 滑板用具、潜水用具、射箭用具、曲棍球用具、冰球"
		"用具、网球用具、登山用具、自行车。" << endl <<
		"  3-皮划艇/独木舟、悬挂式滑翔运动用具、雪橇/水撬。冲浪板、风帆冲浪用具、橡皮艇或船。" << endl <<
		"  4-撑杆、标枪、单独包装的划船用具或浆、骑马用具。" << endl <<
		"  5-睡袋、背包、野营用具、渔具、乐器、辅助设备（非残疾、伤、病旅客托运）、可折叠婴儿床、可折叠婴儿车或婴儿摇篮或婴儿汽车安全座"
		"椅（非婴儿旅客托运）。" << endl <<
		"  6-小型电器或仪器、媒体设备。" << endl <<
		"  7-可作为行李运输的枪支。" << endl <<
		"  8-可作为行李运输的子弹。" << endl <<
		"  9-小动物（仅限家庭驯养的猫、狗）。}"
		<< endl;

	for (int i = 0; i < num; i++) {
		luggage  cur;
		do {
			cout << "行李" << i + 1 << ":" << endl;
			cout << "	  请输入行李类型对应数字：";
			cin >> tempinput;
			cur.kind = atoi(tempinput.c_str());
		} while ((!isnumber(tempinput, 0)) || input_verify(0, 9, cur.kind));
		do {
			cout << "	  请输入重量（kg）：";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.wt = stof(tempinput);
		if ((cur.kind == 0 || cur.kind == 6 || cur.kind == 7 || cur.kind == 9) && (cur.wt < 2 || cur.wt > 32)) {
			cout << "行李" << i + 1 << "重量不符合规定，无法托运" << endl;
			outrule = 1;
			return bags;
		}
		else if ((cur.kind == 3 || cur.kind == 4) && (cur.wt < 2 || cur.wt > 45)) {
			cout << "行李" << i + 1 << "重量不符合规定，无法托运" << endl;
			outrule = 1;
			return bags;
		}
		else if ((cur.kind == 8) && (cur.wt < 2 || cur.wt > 5)) {
			cout << "行李" << i + 1 << "重量不符合规定，无法托运" << endl;
			outrule = 1;
			return bags;
		}
		do {
			cout << "	  请输入行李长（cm）：";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.a = stof(tempinput);
		do {
			cout << "          请输入行李宽（cm）：";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.b = stof(tempinput);
		do {
			cout << "	  请输入行李高（cm）：";
			cin >> tempinput;
		} while ((!isnumber(tempinput, 1)) || input_verify(0, 0, stof(tempinput)));
		cur.c = stof(tempinput);
		if (cur.a + cur.b + cur.c < 60 || cur.a + cur.b + cur.c > 203) {
			cout << "行李" << i+1 << "尺寸不符合规定，无法托运" << endl;
			outrule = 1;
			break;
		}
		bags.push_back(cur);
	}
	return bags;
}

//判断输入是否为数字, isfloat为1判断输入是否为浮点数
bool isnumber(string str, bool isfloat) {
	if (str[0] != 45)    // 要把负号摘除
	{
		for (int i = 0; i < str.length(); i++)    // 逐一字符查验
		{
			if (isfloat && str[i] != '.') {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "请输入正确的数字" << endl;
					return false;
				}
			}
			else if (!isfloat) {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "请输入正确的数字" << endl;
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
					cout << "请输入正确的数字" << endl;
					return false;
				}
			}
			else if (!isfloat) {
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "请输入正确的数字" << endl;
					return false;
				}
			}
		}
		return true;
	}
}

//判断单个输入是否在合理范围内
bool input_verify(int min,	int max, int value) {
	if (value < min || (min != max && value > max)) {
		cout << "输入有误，请重新输入正确的数字" << endl;
		return true;
	}
	return false;
}

//国内航线计价
float inchina(vector<int> a, vector<luggage> bags) {
	int num = bags.size();
	float price = 0;
	float sumwt0 = 0;   // 计入免费行李额部分行李重量
	float sumwt1 = 0;   // 特殊行李中不计入免费行李额部分，直接加入到超出额度
	float overwt = 0;    // 计算总超出额度
	for (int i = 0; i < num; i++) {   // 计算计入免费行李额度的总行李重量
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

	if (a[2] == 1) {    // 成人/儿童票
		if (a[3] == 1) {      // 头等舱
			if (a[4] == 1) {     // 普通旅客
				overwt += (sumwt0 - 40);
			}
			else if(a[4] == 2) {      // 凤凰白金卡
				overwt += (sumwt0 - 70);
			}
			else if (a[4] == 3 || a[4] == 4) {   //凤凰知音金卡/星空联盟金卡
				overwt += (sumwt0 - 60);
			}
		}
		else if (a[3] == 2) {   // 公务舱
			if (a[4] == 1) {     // 普通旅客
				overwt += (sumwt0 - 30);
			}
			else if (a[4] == 2) {      // 凤凰白金卡
				overwt += (sumwt0 - 60);
			}
			else if (a[4] == 3 || a[4] == 4) {   //凤凰知音金卡/星空联盟金卡
				overwt += (sumwt0 - 50);
			}
		}
		else if (a[3] == 3 || a[3] == 4) {   // 悦享经济舱、经济舱
			if (a[4] == 1) {     // 普通旅客
				overwt += (sumwt0 - 20);
			}
			else if (a[4] == 2) {      // 凤凰白金卡
				overwt += (sumwt0 - 50);
			}
			else if (a[4] == 3 || a[4] == 4) {   //凤凰知音金卡/星空联盟金卡
				overwt += (sumwt0 - 40);
			}
		}
	}
	else if (a[2] == 2) {     // 婴儿票
		if (a[4] == 1) {     // 普通旅客
			overwt += (sumwt0 - 10);
		}
		else if (a[4] == 2) {      // 凤凰白金卡
			overwt += (sumwt0 - 40);
		}
		else if (a[4] == 3 || a[4] == 4) {   //凤凰知音金卡/星空联盟金卡
			overwt += (sumwt0 - 30);
		}
	}
	overwt = (overwt > 0 ? overwt + sumwt1 : sumwt1);
	price = overwt * 0.015 * a[5];
	return price;
}

// 超件数收费函数
float overnum(int num, int limit, int region) {   // num-总件数，limit-免费额度，region-区域
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

// 国际航线所有普通行李以及部分计入行李额的超重超尺寸收费函数
float overwtsize(vector<luggage> bags, int wlimit, int region) {   // bags-所有行李，wlimit-重量限制，region-区域
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

// 国外航线特殊行李计价
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

// 国外航线计价
float interfly(vector<int> a, vector<luggage> bags) {
	float cost = 0;
	int num = bags.size(), ordnum = 0, spenum = 0;
	for (int i = 0; i < num; i++) {
		if (bags[i].kind == 0 || bags[i].kind == 2 || bags[i].kind == 5) {
			ordnum += 1;
		}
		if (bags[i].kind == 3 || bags[i].kind == 4 || bags[i].kind == 6 || bags[i].kind ==7  || bags[i].kind == 8 || bags[i].kind == 9) {
			cost += speccost(bags[i]);         // 特殊行李计价
		}
	}
	if (a[2] == 1) {    // 成人/儿童票
		if (a[3] == 1 || a[3] == 2) {      // 头等舱/公务舱
			if (a[4] == 1) {     // 普通旅客
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3) {      // 凤凰白金卡/凤凰知音金卡
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 4) {   // 星空联盟金卡
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
		}
		else if (a[3] == 3) {   // 悦享/超级经济舱
			if (a[4] == 1) {     // 普通旅客
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3 || a[4] == 4) {      // 凤凰白金卡/凤凰知音金卡/星空联盟金卡
				cost += overnum(ordnum, 3, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
		else if (a[3] == 4) {   // 经济舱
			if (a[4] == 1) {     // 普通旅客
				if (a[1] == 1 || a[1] == 5) {
					cost += overnum(ordnum, 1, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
				else {
					cost += overnum(ordnum, 2, a[1]);
					cost += overwtsize(bags, 23, a[1]);
				}
			}
			else if (a[4] == 2) {      // 凤凰白金卡/凤凰知音金卡/星空联盟金卡
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
	else if (a[2] == 2) {     // 婴儿票
		if (a[3] == 1 || a[3] == 2) {      // 头等舱/公务舱
			if (a[4] == 1) {     // 普通旅客
				cost += overnum(ordnum, 1, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3) {      // 凤凰白金卡/凤凰知音金卡
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 32, a[1]);
			}
			else if (a[4] == 4) {   // 星空联盟金卡
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
		else if (a[3] == 3 || a[3] == 4) {   // 悦享/超级经济舱、经济舱
			if (a[4] == 1) {     // 普通旅客
				cost += overnum(ordnum, 1, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
			else if (a[4] == 2 || a[4] == 3 || a[4] == 4) {      // 凤凰白金卡/凤凰知音金卡/星空联盟金卡
				cost += overnum(ordnum, 2, a[1]);
				cost += overwtsize(bags, 23, a[1]);
			}
		}
	}
	return cost;
}