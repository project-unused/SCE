#ifndef _SCE_TOOLS_
#define _SCE_TOOLS_
#ifdef _WIN32
#define CLS "cls"
#else
#define CLS "clear"
#endif // _WIN32
#include "json.hpp"
#include "Val.h"
#include <fstream>
#include <iostream>

#define N "normal"
using namespace std;
using json = nlohmann::json;
class SCE_tools
{
public:
	void fortest() {
		ofstream o("../assets/res.json");
		o << "{}" << endl;
		o.close();
		ofstream p("../assets/setting.json");
		json j = {
			{"set001", false},
			{"set002", false},
			{"set003", false},
			{"set004", false},
			{"set005", false},
			{"set999", false},
			{"set998", false}
		};
		p << j << endl;
		p.close();
		ofstream q("../assets/about.txt");
		q << "debug mod" << endl;
		q.close();
		ofstream r("../assets/LICENSE");
		r << "debug mod" << endl;
		r.close();
		ofstream s("../assets/updatalog.txt");
		s << "debug mod" << endl;
		s.close();


	};
	bool read_setting(const char* setting_name) {
		json j;
		std::ifstream i("../assets/setting.json");
		i >> j;
		i.close();
		bool temp = j.at(setting_name);
		return temp;
	};
	bool write_setting(const char* setting_name, bool setting_stat) {
		json j;
		std::ifstream i("../assets/setting.json");
		i >> j;
		i.close();
		if (j.contains(setting_name)) {
			j[setting_name] = setting_stat; //      µ ֵ
		}
		std::ofstream o("../assets/setting.json");
		o<<j;
		o << endl;
		o.close();
		return setting_stat;
	}
	void val_setting() {
		json j;
		std::ifstream i("../assets/res.json");
		if (i.is_open() == false) {
			i.close();
			ofstream o("../assets/res.json");
			o << "{}";
			o.close();
		}
		try {
			i >> j;
		}
		catch (json::parse_error& e) {
			error_res("load");
		};
		i.close();
		try {
			set001 = read_setting("set001");
			set002 = read_setting("set002");
			set003 = read_setting("set003");
			set004 = read_setting("set004");
			set005 = read_setting("set005");
			set999 = read_setting("set999");
			set998 = read_setting("set998");
		}
		catch (const json::parse_error& e) {
			control_error();
		}
		catch (const json::out_of_range& e) {
			control_error();

		}
		catch (const std::exception& e) {
			control_error();
		};
	}

	void error_res(const string errortype) {
		if (errortype == "load") {
			ex_res_saver = 0;
		}
		else if (errortype == "read") {
			cout << "\033[31m ޷   ȡ  Դ ļ \033[0m\n";
			ex_res_saver = 0;
			getchar();
		}
		else if (errortype == "write") {
			cout << "\033[31m ޷ д    Դ ļ \033[0m\n";
			ex_res_saver = 0;
			getchar();

		}
		else if (errortype == "delete") {
			system(CLS);
			int num;
			cout << "\033[31m ޷ ɾ  ָ    Դ,   ǿ  ɾ       ܻᶪʧ       ݣ \033[0m\n[1]ǿ  ɾ     [2]    \n";
			ex_res_saver = 0;
			if (inputErr) {
				cout << "\033[31m        Ч    \033[0m\n";
				inputErr = 0;
			}
			cout << "[ ]\b\b";
			cin >> num;
			switch (num) {
			case 1: {
				ofstream o("../assets/res.json");
				o << "{}" << endl;
				o.close();
				system(CLS);
				cout << "\033[32mɾ    ɣ \033[0m";
				getchar();
				break;
			};
			case 2:
			{
				break;
			};
			default:
				inputErr = 1; cin.clear(); cin.ignore(); error_res("delete"); break;
			}
		}
		else if (errortype == "error_inputerr") {
			cin.clear();
			cin.ignore();
			inputERR = 1;
		}
		else if (errortype == "law") {

		}
	}

private:
	int inputErr = 0; int num;

protected:
	void auto_fix() {
		std::ofstream o("../assets/setting.json");
		if (!o.is_open()) {
			cout << "\033[31m Զ  ޸ ʧ  ,          SCE   ° \033[0m";
			//getchar();
			cin.get();
			exit(1);
		}
		json j = {
			{"set001", false},
			{"set002", false},
			{"set003", false},
			{"set004", false},
			{"set005", false},
			{"set999", false},
			{"set998", false}
		};
		o << j << endl;
		o.close();
		system(CLS);
		cout << " ޸   ɣ               ";
		//getchar();
		cin.get();

		exit(2);

	}
	void print_error() {
		system(CLS);
		cout << "\033[31mȱ ٱ Ҫ ļ                °汾  SCE     ߽    Զ  ޸ \033[0m\n[1] Զ  ޸      [2]         [3] ˳ " << endl;
		if (inputErr == 1) {
			cout << "\n\033[31m       \033[0m\n\n" << endl; cin.clear(); cin.ignore(); inputErr = 0;
		}
		cout << "\n[ ]\b\b";
	};
	void control_error() {
		print_error();
		cin >> num;
		cin.ignore();
		switch (num)
		{
		case 1:
			auto_fix(); break;
		case 2:
			ex_setting = false; break;
		case 3:
			exit(1);
		default:
			inputErr = 1;control_error(); break;
		}
	}
	};



class res : protected SCE_tools {
public:
	void read_res(const string supportcardname) {
		string res_name = supportcardname;
		json j;
		std::ifstream i("../assets/res.json");
		if (i.is_open() == false) {
			error_res("read");
		}
		i >> j;
		i.close();
		try {
			type = j[res_name]["type"];
			fs = j[res_name]["fs"];
			sfs = j[res_name]["sfs"];
			dr = j[res_name]["dr"];
			tr = j[res_name]["tr"];
			trap = j[res_name]["trap"];
			gatr = j[res_name]["gatr"];
			speed = j[res_name]["speed"];
			stamina = j[res_name]["stamina"];
			power = j[res_name]["power"];
			willp = j[res_name]["willp"];
			wit = j[res_name]["wit"];
			sp = j[res_name]["sp"];
			v4g1mainept = j[res_name]["v4g1mainept"];
			v4g1foldept = j[res_name]["v4g1foldept"];
			v4g1spept = j[res_name]["v4g1spept"];
			//mainept,foldept,spept
		}
		catch (std::exception& e) {
			error_res("read");

		}
		catch (json::out_of_range& e) {
			error_res("read");
		}
		catch (json::parse_error& e) {
			error_res("read");
		}
	}
	void write_res(const string supportcardname , int type, int fs, int sfs, int dr, int tr, int trap, int gatr, int speed, int stamina, int power, int willp, int wit, int sp,int v4g1mainept,int v4g1foldept,int v4g1spept) {
		json j;
		string res_name = supportcardname;
		ifstream i("../assets/res.json");
		if (i.is_open() == false) {
			i.close();
			error_res("write");
		}
		i>>j;
		i.close();
		j[res_name] = {
			{"type",type},
			{"fs",fs},
			{"sfs",sfs},
			{"dr",dr},
			{"tr",tr},
			{"trap",trap},
			{"gatr",gatr},
			{"speed",speed},
			{"stamina",stamina},
			{"power",power},
			{"willp",willp},
			{"wit",wit},
			{"sp",sp},
			{"v4g1mainept",v4g1mainept},
			{"v4g1foldept",v4g1foldept},
			{"v4g1spept",v4g1spept}

		};
		ofstream o("../assets/res.json");
		if (o.is_open() == false) {
			
			o.close();
			error_res("write");
		}
		try {
			o<<j;
		}
		catch (std::exception& e) {
			error_res("write");
		}
		catch (json::parse_error& e) {
			error_res("write");
		}
		catch (json::out_of_range& e) {
			error_res("write");
		}
		o.close();
	};
	void delete_res(const string supportcardname){
		json j;
		ifstream i("../assets/res.json");
		if (i.is_open() == false) {
			error_res("delete");

		}
		i >> j;
		i.close();
		string res_name = supportcardname;
		try {
			j.erase(res_name);
		}
		catch (std::exception& e) {
			error_res("delete");
		}
		catch (json::parse_error& e) {
			error_res("delete");
		}
		catch (json::out_of_range& e) {
			error_res("delete");
		};
		ofstream o("../assets/res.json");
		if (o.is_open() == false) {
			error_res("delete");
		};
		o << j;
		o.close();
	};
private:

protected:

};

class debug :public SCE_tools {
public:
	void print_debug();
	void control_debug();
	void debug_mod(bool state) {
		if (state) {
			control_debug();
		}
	}
private:
	int inputErr = 0;
protected:

};


#endif
