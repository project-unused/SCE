//SCE V4.0B7.cpp

#include<iostream>
#include<string>
#include<iomanip>
#include"Core.h"
#include"Val.h"
#include "tools.h"

//linux 适配
#ifdef _WIN32 // Windows
#define CLS "cls"
#else
#define CLS "clear"
#endif
using namespace std;

SCE_tools t;
res r;

string changename(string a)
{
	cout << "当前标识名：" << supportcardname << " 更改为：";
	cin >> a;
	return a;
}


void law();
void mix();

void print_main();
void print_res();
void print_val();
void print_set();
void print_about();

void control_about();
void control_set();
void control_res();
void control_cul();
void control_main();


int main()
{
	//t.fortest();
	t.val_setting();
	
	//For test

	//r.write_res("123", 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1);
	//r.delete_res(1);

	control_main();
}

//实现

void law()
{
	
	system(CLS);
	ifstream i("../assets/LICENSE");
	if (i.is_open()) {
		string line;
		while (std::getline(i, line)) {
			std::cout << line << std::endl; // 输出每一行
		}
	}
	else {
		t.error_res("law");
	}
	if (inputERR == 1) {
		cout << "\033[31m请输入有效数字\033[0m\n\n";
		inputERR = 0;
	}
	cout << endl << "[000]返回关于界面\n\n"


		<< "[   ]\b\b\b\b";
	int num;
	cin >> num;
	cout << num;
	switch (num)
	{
	case 000:control_about(); break;
	default:
		t.error_res("error_inputerr"); law(); break;
	}

}

void mix()
{
	system(CLS);
	ifstream i("../assets/about.txt");
	if (i.is_open()) {
		string line;
		while (std::getline(i, line)) {
			std::cout << line << std::endl; // 输出每一行
		}
	}
	else {
		t.error_res("mix");
	}
	if (inputERR == 1) {
		cout << "\033[31m请输入有效数字\033[0m\n";
		inputERR = 0;
	}
	cout << endl << "[000]返回关于界面\n\n"


		<< "[   ]\b\b\b\b";
	int num;
	cin >> num;
	cout << num;
	switch (num)
	{
	case 000:control_about(); break;
	default:
		t.error_res("error_inputerr"); mix(); break;
	}


}

void print_main()
{
	system(CLS);
	cout << "SupportCard Evaluator\n";//标题呈现
	cout << "[001] 开始\n";
	if (ex_setting == false) {
		cout << "\033[90m[997] 设置\033[0m\n";
	}
	else {
		cout << "[997] 设置\n";
	}
		cout << "[998] 关于\n[999] 退出\n";
	if (inputERR == 1)
	{
		cout << "\033[31m 请输入有效数字 \033[0m \n";
	}
	else if (input_no_exist_setting == 1) {
		cout << "\033[31m设置不可用\033[0m\n";
		input_no_exist_setting = 0;
	}
	inputERR = 0;
	if (ex_setting == false)
	{
		cout << "\033[33m警告：无法读取设置文件，请检查是否授予相关权限！\033[0m\n";
	}
	cout << "[   ]\b\b\b\b";
}

void print_res()
{
	system(CLS);
	cout << "支援卡类型：" << nametype <<"     支援卡标识名："<< supportcardname << endl;
	cout << "友情加成：" << fs << "  固有友情：" << sfs << "  干劲加成：" << dr << "\n训练加成：" << tr << "  初始羁绊：" << trap << "  得 意 率：" << gatr
		<< "\n速度加成：" << speed << "  耐力加成：" << stamina << "  力量加成：" << power << "\n根性加成：" << willp << "  智力加成：" << wit << "  S P 加成：" << sp
		<< endl << endl;

	cout << "\033[90mV4G1评分：" << "( " << V4G1umaSCEcore_mainept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " + "
		<< V4G1umaSCEcore_foldept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " + "
		<< V4G1umaSCEcore_spept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " )\033[0m";

	if (input_no_exist_res == 1) {
		cout << "\n\033[31m输出记录操作暂不可用\033[0m";
		input_no_exist_res = 0;
	}
	if (ex_res_saver == false)
	{
		cout << "\n\033[33m警告：无法读取记录文件，请检查是否授予相关权限！\033[0m\n";
	}
	cout << "\n\n[001]更改标识名 ";
	if (set004 == 0) {
		if (ex_res_saver == false) {
			cout << "\033[90m[999]保存支援卡信息 \033[0m";
		}
		else {
			cout << "[999]保存支援卡信息 ";
		}
	}
	cout << "[000]返回上一级\n\n";
	if (SaveState)
	{
		cout << "\033[32m保存成功\033[0m\n\n";
	}
	if (inputERR == 1) {
		cout << "\033[31m请输入有效数字\033[0m\n";
		inputERR = 0;
	}

	cout<<"[   ]\b\b\b\b";
}

void print_val()
{
	system(CLS);
	switch (type)
	{
	case 1:nametype = "速度"; break;
	case 2:nametype = "耐力"; break;
	case 3:nametype = "力量"; break;
	case 4:nametype = "根性"; break;
	case 5:nametype = "智力"; break;
	}

	cout << "[100]类型："<< nametype << endl;
	cout << "[01]友情加成：" << fs << "\n"
		<< "[02]固有友情：" << sfs << "\n"
		<< "[03]干劲加成：" << dr << endl
		<< "[04]训练加成：" << tr << "\n";

	if (set001)
	{
		cout << "\033[90m{友情倍率：" << (fs * 0.01 + 1) * (sfs * 0.01 + 1) * (dr * 0.002 + 1) * (tr * 0.01 + 1) << "}\033[0m \n\n";
	}

	cout << "[05]初期羁绊：" << trap << "\n"
		<< "[06]得 意 率：" << gatr << "\n";

	if (set002)
	{
		double a = (gatr + 100);
		double b = (550 + gatr);
		cout << setprecision(4) << "\033[90m{" << (a / b) << "," << ((100) / b) << "," << ((50) / b) << "}\033[0m\n\n" << defaultfloat ;
	}

	cout<< "[07]速度加成：" << speed << "\n"
		 << "[08]耐力加成：" << stamina << "\n"
		 << "[09]力量加成：" << power << endl
		 << "[10]根性加成：" << willp << "\n"
		 << "[11]智力加成：" << wit << "\n"
		 << "[12]S P 加成：" << sp << endl;

	if (set003)
	{
		cout << "\033[90m{友情训练倍率：" << V2umaSCEcore_ept(type,fs,sfs,dr,tr,speed,stamina,power,willp,wit) << "}\033[0m\n\n";
	}


	cout << "[999]开始计算   [000]返回主界面\n";
	if (inputERR == 1)
	{
		cout << "\033[31m 请输入有效数字 \033[0m\n";
	}
	inputERR = 0;
	cout << "[   ]\b\b\b\b";

}
void print_set()
{
	system(CLS);
	cout << "[001]友情倍率  " << "{";
	if (set001)
	{
		cout << "开";		
		cout << "}\n";
		cout << "  \033[90m [04]训练加成：10\n   {友情倍率：1.5444}\n   [05]初期羁绊：25\n\n\033[0m";
	}
	else
	{
		cout << "关";
		cout << "}\n\n";
	}

	cout << "[002]友情训练倍率  " << "{";
	if (set002)
	{
		cout << "开";
		cout << "}\n";
		cout << "  \033[90m [12]S P 加成：10\n   {友情训练倍率：1.6988}\n\n \033[0m";
	}
	else
	{
		cout << "关";
		cout << "}\n\n";
	}

	cout << "[003]真实得意率显示  " << "{";
	if (set003)
	{
		cout << "开";
		cout << "}\n";
		cout << "  \033[90m [06]得 意 率：50\n   {0.2500,0.1667,0.0833}\n\n \033[0m";
	}
	else
	{
		cout << "关";
		cout << "}\n\n";
	}

	cout << "[004]支援卡信息保存  " << "{";
	if (set004)
	{
		cout << "每次询问";
		cout << "}\n";
		cout << "   \033[90m咨询标识后自动保存\n\n \033[0m";
	}
	else
	{
		cout << "每次不询问";
		cout << "}\n";
		cout << "   \033[90m手动选择保存\n\n \033[0m";
	}

	cout << "[005]评分展示格式  " << "{";
	if (set005)
	{
		cout << "( mainept + foldept + spept )";
		cout << "}\n";
		cout << "  \033[90m 支援卡评分 ( 1863 + 1774 + 3715 )\n\n \033[0m";
	}
	else
	{
		cout << "( mainept + spept + foldept )";
		cout << "}\n";
		cout << "  \033[90m 支援卡评分 ( 1863 + 3715 + 1774 )\n\n\033[0m";
	}

	cout << "[999]实验性功能  " << "{";
	if (set999)
	{
		cout << "开";
		cout << "}\n";

		cout << "     [998]在V4评分旁展示V3评分  " << "{";
		if (set998)
		{
			cout << "开";
			cout << "}\n";
			cout << "      \033[90m 支援卡评分 ( 1863 + 1774 + 3715 )\n       V3评分 (3591)\n\n \033[0m";
		}
		else
		{
			cout << "关";
			cout << "}\033[0m\n\n";
		}
	}
	else
	{
		cout << "关";
		cout << "}\033[0m\n\n";
	}

	cout << "[000]返回主界面\n";

	if (inputERR == 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\033[31m 请输入有效数字 \033[0m\n";
	}
	inputERR = 0;

	cout << "[   ]\b\b\b\b";
}


void print_about()
{
	system(CLS);
	ifstream i("../assets/data.txt");
	if (i.is_open()) {
		string line;
		while (std::getline(i, line)) {
			std::cout << line << std::endl; // 输出每一行
		}
	}
	else {
		t.error_res("data");
	}
	cout << endl << "[000]返回主界面  [001]法律信息 [002]杂项\n";
	if (inputERR == 1) 
	{
		cout << "\033[31m请输入有效数字\033[0m\n";
		inputERR = 0;
	}
		cout<< "[   ]\b\b\b\b";
	
}

void control_about()
{
	print_about();
	int num;
	cin >> num;
	cout << num;
	switch (num)
	{
	case 000:control_main(); break;
	case 001:law(); break;
	case 002:mix(); break;

	default:
		t.error_res("error_inputerr"); control_about(); break;
	}
}


void control_set()
{
	print_set();
	int num;
	cin >> num;
	switch (num)
	{
	case 1:if (set001)set001 = t.write_setting("set001", 0); else set001 = t.write_setting("set001", 1);control_set();break;
	case 2:if (set002)set002 = t.write_setting("set002", 0); else set002 = t.write_setting("set002", 1); control_set();break;
	case 3:if (set003)set003 = t.write_setting("set003", 0); else set003 = t.write_setting("set003", 1); control_set();break;
	case 4:if (set004)set004 = t.write_setting("set004", 0); else set004 = t.write_setting("set004", 1); control_set();break;
	case 5:if (set005)set005 = t.write_setting("set005", 0); else set005 = t.write_setting("set005", 1); control_set();break;
	case 999:if (set999)set999 = t.write_setting("set999", 0); else set999 = t.write_setting("set999", 1); control_set();break;
	case 998:if (999){ if (set998)set998 = t.write_setting("set998", 0); else set998 = t.write_setting("set998", 1); control_set(); }break;
	case 0:control_main(); break;
	default:inputERR = 1; control_set();

	}
}

void control_res()
{
	print_res();
	SaveState = 0;
	int num;
	cin >> num;
	switch (num)
	{
	case 001:supportcardname=changename(supportcardname);control_res();break;
	case 999:
	{
		if (!set004) 
		{
			if (ex_res_saver = 1) 
			{
				try 
				{
					r.write_res(supportcardname, type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp, v4g1mainept, v4g1foldept, v4g1spept);
					SaveState = 1;
					control_res(); 
					break;
				}
				catch (std::exception& e) 
				{
					input_no_exist_res = 1; control_res(); break;

				}

			}
			else 
			{
				input_no_exist_res = 1; control_res(); break;
			}
		}
		t.error_res("error_inputerr"); control_res(); break;
		break;
	}
	case 000:control_cul();
	default:t.error_res("error_inputerr"); control_res(); break;
	}
}

void control_cul()
{
	print_val();
	int num;
	cin >> num;
	switch (num)
	{
	case 100:

		cin.ignore();
        
		cout << "当前属性：" << nametype << "   修改属性：[   ]\b\b\b\b";

		cin >> type;

		if (type > 5 || type < 1)
		{
			cout << "\n\033[91m不存在的支援卡类型\033[0m";
			type = 1;
			int a;
			cin >> a;
			control_cul();
		}
		control_cul();
		break;

	case 1:
		    
		cin.ignore();

		cout << "当前属性：" << fs << "   修改属性：[   ]\b\b\b\b";
		cin >> fs;
		control_cul();
		break;

	case 2:
		    
		cin.ignore();
		cout << "当前属性：" << sfs << "   修改属性：[   ]\b\b\b\b";
		cin >> sfs;
		control_cul();
		break;

	case 3:
		    
		cin.ignore();
		cout << "当前属性：" << dr << "   修改属性：[   ]\b\b\b\b";
		cin >> dr;
		control_cul();
		break;

	case 4:
		    
		cin.ignore();
		cout << "当前属性：" << tr << "   修改属性：[   ]\b\b\b\b";
		cin >> tr;
		control_cul();
		break;

	case 5:
		    
		cin.ignore();
		cout << "当前属性：" << trap << "   修改属性：[   ]\b\b\b\b";
		cin >> trap;
		control_cul();
		break;

	case 6:
		    
		cin.ignore();
		cout << "当前属性：" << gatr << "   修改属性：[   ]\b\b\b\b";
		cin >> gatr;
		control_cul();
		break;

	case 7:
		    
		cin.ignore();
		cout << "当前属性：" << speed << "   修改属性：[   ]\b\b\b\b";
		cin >> speed;
		control_cul();
		break;

	case 8:
		    
		cin.ignore();
		cout << "当前属性：" << stamina << "   修改属性：[   ]\b\b\b\b";
		cin >> stamina;
		control_cul();
		break;

	case 9:
		    
		cin.ignore();
		cout << "当前属性：" << power << "   修改属性：[   ]\b\b\b\b";
		cin >> power;
		control_cul();
		break;

	case 10:
		    
		cin.ignore();
		cout << "当前属性：" << willp << "   修改属性：[   ]\b\b\b\b";
		cin >> willp;
		control_cul();
		break;

	case 11:
		    
		cin.ignore();
		cout << "当前属性：" << wit << "   修改属性：[   ]\b\b\b\b";
		cin >> wit;
		control_cul();
		break;

	case 12:
		    
		cin.ignore();
		cout << "当前属性：" << sp << "   修改属性：[   ]\b\b\b\b";
		cin >> sp;
		control_cul();
		break;

	case 999:
	{
		control_res();
			break;
	}
	case 0:
	{
		control_main(); break;
	}
	default:
		inputERR = 1; control_cul();	
	}

}
void control_main()
{
	print_main();
	int num;
	cin >> num;
	switch (num)
	{
	case 49:control_cul(); break;
	case 001:control_cul(); break;
	case 997: {
		if (ex_setting) {
			system(CLS); control_set(); break;
		}
		else {
			system(CLS); input_no_exist_setting = 1; control_main(); break;
		}
	}
	case 998:system(CLS); control_about(); break;
	case 999:exit(0);
	default:inputERR = 1; cin.clear(); cin.ignore(); control_main();
	}
}