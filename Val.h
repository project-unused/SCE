//Val.h

#ifndef _VAL_H_
#define _VAL_H_
#include <string>
int inputERR = 0;//Ö÷½çÃæÊäÈë´íÎó²¶×½
int read_res_error = 0; //¶ÁÈ¡res´íÎó²¶×½
int write_res_error = 0; //Ğ´Èëres´íÎó²¶×½
int delete_res_error = 0;
string supportcardname = "NULL";

int witept = 0;
int type = 1;
int fs = 0; int sfs = 0; int dr = 0; int tr = 0; int trap = 0; int gatr = 0;
int speed = 0; int stamina = 0; int power = 0; int willp = 0; int wit = 0; int sp = 0;
string nametype="ËÙ¶È";
bool ex_setting = true;
int input_no_exist_setting = 0;
bool ex_res_saver = 1;
int v4g1mainept, v4g1foldept, v4g1spept = 0;
int input_no_exist_res = 0;
int SaveState = 0;

bool set001;
bool set002;
bool set003;
bool set004;
bool set005;
bool set999;
bool set998;


#endif // !_VAL_H_
