//SCE V4.0B7.cpp

#include<iostream>
#include<string>
#include<iomanip>
#include"Core.h"
#include"Val.h"
#include "tools.h"

//linux ����
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
	cout << "��ǰ��ʶ����" << supportcardname << " ����Ϊ��";
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

//ʵ��

void law()
{
	
	system(CLS);
	ifstream i("../assets/LICENSE");
	if (i.is_open()) {
		string line;
		while (std::getline(i, line)) {
			std::cout << line << std::endl; // ���ÿһ��
		}
	}
	else {
		t.error_res("law");
	}
	if (inputERR == 1) {
		cout << "\033[31m��������Ч����\033[0m\n\n";
		inputERR = 0;
	}
	cout << endl << "[000]���ع��ڽ���\n\n"


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
			std::cout << line << std::endl; // ���ÿһ��
		}
	}
	else {
		t.error_res("mix");
	}
	if (inputERR == 1) {
		cout << "\033[31m��������Ч����\033[0m\n";
		inputERR = 0;
	}
	cout << endl << "[000]���ع��ڽ���\n\n"


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
	cout << "SupportCard Evaluator\n";//�������
	cout << "[001] ��ʼ\n";
	if (ex_setting == false) {
		cout << "\033[90m[997] ����\033[0m\n";
	}
	else {
		cout << "[997] ����\n";
	}
		cout << "[998] ����\n[999] �˳�\n";
	if (inputERR == 1)
	{
		cout << "\033[31m ��������Ч���� \033[0m \n";
	}
	else if (input_no_exist_setting == 1) {
		cout << "\033[31m���ò�����\033[0m\n";
		input_no_exist_setting = 0;
	}
	inputERR = 0;
	if (ex_setting == false)
	{
		cout << "\033[33m���棺�޷���ȡ�����ļ��������Ƿ��������Ȩ�ޣ�\033[0m\n";
	}
	cout << "[   ]\b\b\b\b";
}

void print_res()
{
	system(CLS);
	cout << "֧Ԯ�����ͣ�" << nametype <<"     ֧Ԯ����ʶ����"<< supportcardname << endl;
	cout << "����ӳɣ�" << fs << "  �������飺" << sfs << "  �ɾ��ӳɣ�" << dr << "\nѵ���ӳɣ�" << tr << "  ��ʼ�" << trap << "  �� �� �ʣ�" << gatr
		<< "\n�ٶȼӳɣ�" << speed << "  �����ӳɣ�" << stamina << "  �����ӳɣ�" << power << "\n���Լӳɣ�" << willp << "  �����ӳɣ�" << wit << "  S P �ӳɣ�" << sp
		<< endl << endl;

	cout << "\033[90mV4G1���֣�" << "( " << V4G1umaSCEcore_mainept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " + "
		<< V4G1umaSCEcore_foldept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " + "
		<< V4G1umaSCEcore_spept(type, fs, sfs, dr, tr, trap, gatr, speed, stamina, power, willp, wit, sp) << " )\033[0m";

	if (input_no_exist_res == 1) {
		cout << "\n\033[31m�����¼�����ݲ�����\033[0m";
		input_no_exist_res = 0;
	}
	if (ex_res_saver == false)
	{
		cout << "\n\033[33m���棺�޷���ȡ��¼�ļ��������Ƿ��������Ȩ�ޣ�\033[0m\n";
	}
	cout << "\n\n[001]���ı�ʶ�� ";
	if (set004 == 0) {
		if (ex_res_saver == false) {
			cout << "\033[90m[999]����֧Ԯ����Ϣ \033[0m";
		}
		else {
			cout << "[999]����֧Ԯ����Ϣ ";
		}
	}
	cout << "[000]������һ��\n\n";
	if (SaveState)
	{
		cout << "\033[32m����ɹ�\033[0m\n\n";
	}
	if (inputERR == 1) {
		cout << "\033[31m��������Ч����\033[0m\n";
		inputERR = 0;
	}

	cout<<"[   ]\b\b\b\b";
}

void print_val()
{
	system(CLS);
	switch (type)
	{
	case 1:nametype = "�ٶ�"; break;
	case 2:nametype = "����"; break;
	case 3:nametype = "����"; break;
	case 4:nametype = "����"; break;
	case 5:nametype = "����"; break;
	}

	cout << "[100]���ͣ�"<< nametype << endl;
	cout << "[01]����ӳɣ�" << fs << "\n"
		<< "[02]�������飺" << sfs << "\n"
		<< "[03]�ɾ��ӳɣ�" << dr << endl
		<< "[04]ѵ���ӳɣ�" << tr << "\n";

	if (set001)
	{
		cout << "\033[90m{���鱶�ʣ�" << (fs * 0.01 + 1) * (sfs * 0.01 + 1) * (dr * 0.002 + 1) * (tr * 0.01 + 1) << "}\033[0m \n\n";
	}

	cout << "[05]�����" << trap << "\n"
		<< "[06]�� �� �ʣ�" << gatr << "\n";

	if (set002)
	{
		double a = (gatr + 100);
		double b = (550 + gatr);
		cout << setprecision(4) << "\033[90m{" << (a / b) << "," << ((100) / b) << "," << ((50) / b) << "}\033[0m\n\n" << defaultfloat ;
	}

	cout<< "[07]�ٶȼӳɣ�" << speed << "\n"
		 << "[08]�����ӳɣ�" << stamina << "\n"
		 << "[09]�����ӳɣ�" << power << endl
		 << "[10]���Լӳɣ�" << willp << "\n"
		 << "[11]�����ӳɣ�" << wit << "\n"
		 << "[12]S P �ӳɣ�" << sp << endl;

	if (set003)
	{
		cout << "\033[90m{����ѵ�����ʣ�" << V2umaSCEcore_ept(type,fs,sfs,dr,tr,speed,stamina,power,willp,wit) << "}\033[0m\n\n";
	}


	cout << "[999]��ʼ����   [000]����������\n";
	if (inputERR == 1)
	{
		cout << "\033[31m ��������Ч���� \033[0m\n";
	}
	inputERR = 0;
	cout << "[   ]\b\b\b\b";

}
void print_set()
{
	system(CLS);
	cout << "[001]���鱶��  " << "{";
	if (set001)
	{
		cout << "��";		
		cout << "}\n";
		cout << "  \033[90m [04]ѵ���ӳɣ�10\n   {���鱶�ʣ�1.5444}\n   [05]�����25\n\n\033[0m";
	}
	else
	{
		cout << "��";
		cout << "}\n\n";
	}

	cout << "[002]����ѵ������  " << "{";
	if (set002)
	{
		cout << "��";
		cout << "}\n";
		cout << "  \033[90m [12]S P �ӳɣ�10\n   {����ѵ�����ʣ�1.6988}\n\n \033[0m";
	}
	else
	{
		cout << "��";
		cout << "}\n\n";
	}

	cout << "[003]��ʵ��������ʾ  " << "{";
	if (set003)
	{
		cout << "��";
		cout << "}\n";
		cout << "  \033[90m [06]�� �� �ʣ�50\n   {0.2500,0.1667,0.0833}\n\n \033[0m";
	}
	else
	{
		cout << "��";
		cout << "}\n\n";
	}

	cout << "[004]֧Ԯ����Ϣ����  " << "{";
	if (set004)
	{
		cout << "ÿ��ѯ��";
		cout << "}\n";
		cout << "   \033[90m��ѯ��ʶ���Զ�����\n\n \033[0m";
	}
	else
	{
		cout << "ÿ�β�ѯ��";
		cout << "}\n";
		cout << "   \033[90m�ֶ�ѡ�񱣴�\n\n \033[0m";
	}

	cout << "[005]����չʾ��ʽ  " << "{";
	if (set005)
	{
		cout << "( mainept + foldept + spept )";
		cout << "}\n";
		cout << "  \033[90m ֧Ԯ������ ( 1863 + 1774 + 3715 )\n\n \033[0m";
	}
	else
	{
		cout << "( mainept + spept + foldept )";
		cout << "}\n";
		cout << "  \033[90m ֧Ԯ������ ( 1863 + 3715 + 1774 )\n\n\033[0m";
	}

	cout << "[999]ʵ���Թ���  " << "{";
	if (set999)
	{
		cout << "��";
		cout << "}\n";

		cout << "     [998]��V4������չʾV3����  " << "{";
		if (set998)
		{
			cout << "��";
			cout << "}\n";
			cout << "      \033[90m ֧Ԯ������ ( 1863 + 1774 + 3715 )\n       V3���� (3591)\n\n \033[0m";
		}
		else
		{
			cout << "��";
			cout << "}\033[0m\n\n";
		}
	}
	else
	{
		cout << "��";
		cout << "}\033[0m\n\n";
	}

	cout << "[000]����������\n";

	if (inputERR == 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\033[31m ��������Ч���� \033[0m\n";
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
			std::cout << line << std::endl; // ���ÿһ��
		}
	}
	else {
		t.error_res("data");
	}
	cout << endl << "[000]����������  [001]������Ϣ [002]����\n";
	if (inputERR == 1) 
	{
		cout << "\033[31m��������Ч����\033[0m\n";
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
        
		cout << "��ǰ���ԣ�" << nametype << "   �޸����ԣ�[   ]\b\b\b\b";

		cin >> type;

		if (type > 5 || type < 1)
		{
			cout << "\n\033[91m�����ڵ�֧Ԯ������\033[0m";
			type = 1;
			int a;
			cin >> a;
			control_cul();
		}
		control_cul();
		break;

	case 1:
		    
		cin.ignore();

		cout << "��ǰ���ԣ�" << fs << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> fs;
		control_cul();
		break;

	case 2:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << sfs << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> sfs;
		control_cul();
		break;

	case 3:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << dr << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> dr;
		control_cul();
		break;

	case 4:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << tr << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> tr;
		control_cul();
		break;

	case 5:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << trap << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> trap;
		control_cul();
		break;

	case 6:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << gatr << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> gatr;
		control_cul();
		break;

	case 7:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << speed << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> speed;
		control_cul();
		break;

	case 8:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << stamina << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> stamina;
		control_cul();
		break;

	case 9:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << power << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> power;
		control_cul();
		break;

	case 10:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << willp << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> willp;
		control_cul();
		break;

	case 11:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << wit << "   �޸����ԣ�[   ]\b\b\b\b";
		cin >> wit;
		control_cul();
		break;

	case 12:
		    
		cin.ignore();
		cout << "��ǰ���ԣ�" << sp << "   �޸����ԣ�[   ]\b\b\b\b";
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