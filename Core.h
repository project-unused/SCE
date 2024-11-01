//Core.h

#ifndef _UMACULCORE_
#define _UMACULCORE_

#include <string>

using namespace std;

int V4G1umaSCEcore_mainept(int type, int fs, int sfs, int dr, int tr, int trap, int gatr, int speed, int stamina, int power, int willp, int wit, int sp)
{
	//将int转换为float
	float a = (1 + 0.01 * fs);
	float b = (1 + 0.01 * sfs);
	float fsrate = a * b;
	float drrate = 1 + 0.002 * dr;
	float trrate = 1 + 0.01 * tr;
	//end

	//得意率计算
	float c = (100 + gatr);
	float d = (550 + gatr);
	float gat = c / d;
	float e = (550 + gatr);
	float ngat = 100 / e;
	float f = (550 + gatr);
	float eht = 50 / f;
	//end

	//计算失效率
	float x = (80 - trap) / 5;
	if (x != int(x))
		if (x > int(x))
			x = 1 + int(x);
		else
			x = int(x);
	//Todo :向上取整
	//end
	float fht = x / 72;//失效率
	//end

	//与回合相关的计算
	//实际训练回合
	int actualround = 10000 - 10000 * eht;
	//失效回
	int failround = actualround * fht;
	//友情训练趋势回合
	int trendround = actualround - failround;
	//end

	//杂项
	//不含友情加成的训练倍率
	float anfsrate = drrate * trrate;
	//包含友情‘s
	float afsrate = fsrate * drrate * trrate;
	//失效回
	int ngfailround = failround * ngat;
	int gfailround = failround * gat;
	//趋势回
	int ngtrendround = trendround * ngat;
	int gtrendround = trendround * gat;
	//end
	float foldept; float mainept;

	if (type == 1)
		mainept = (afsrate + 0.1 * anfsrate * speed) * gfailround + (afsrate + 0.1 * afsrate * speed) * gtrendround - gfailround - gtrendround;
	else if (type == 2)
		mainept = (afsrate + 0.1 * anfsrate * stamina) * gfailround + (afsrate + 0.1 * afsrate * speed) * gtrendround - gfailround - gtrendround;

	else if (type == 3)
		mainept = (afsrate + 0.1 * anfsrate * power) * gfailround + (afsrate + 0.1 * afsrate * speed) * gtrendround - gfailround - gtrendround;


	else if (type == 4)
		mainept = (afsrate + 0.1 * anfsrate * willp) * gfailround + (afsrate + 0.1 * afsrate * speed) * gtrendround - gfailround - gtrendround;


	else if (type == 5)
		mainept = (afsrate + 0.1 * anfsrate * wit) * gfailround + (afsrate + 0.1 * afsrate * speed) * gtrendround - gfailround - gtrendround;


	//计算期待p
	

	//Todo:stewmpt?
	//end
	//返回
	return mainept;
}
int V4G1umaSCEcore_foldept(int type, int fs, int sfs, int dr, int tr, int trap, int gatr, int speed, int stamina, int power, int willp, int wit, int sp)
{
	//将int转换为float
	float a = (1 + 0.01 * fs);
	float b = (1 + 0.01 * sfs);
	float fsrate = a * b;
	float drrate = 1 + 0.002 * dr;
	float trrate = 1 + 0.01 * tr;
	//end

	//得意率计算
	float c = (100 + gatr);
	float d = (550 + gatr);
	float gat = c / d;
	float e = (550 + gatr);
	float ngat = 100 / e;
	float f = (550 + gatr);
	float eht = 50 / f;
	//end

	//计算失效率
	float x = (80 - trap) / 5;
	if (x != int(x))
		if (x > int(x))
			x = 1 + int(x);
		else
			x = int(x);
	//Todo :向上取整
	//end
	float fht = x / 72;//失效率
	//end

	//与回合相关的计算
	//实际训练回合
	int actualround = 10000 - 10000 * eht;
	//失效回
	int failround = actualround * fht;
	//友情训练趋势回合
	int trendround = actualround - failround;
	//end

	//杂项
	//不含友情加成的训练倍率
	float anfsrate = drrate * trrate;
	//包含友情‘s
	float afsrate = fsrate * drrate * trrate;
	//失效回
	int ngfailround = failround * ngat;
	int gfailround = failround * gat;
	//趋势回
	int ngtrendround = trendround * ngat;
	int gtrendround = trendround * gat;
	//end
	float foldept; float mainept;
	if (type == 1)
		foldept = (ngfailround + ngtrendround) * (4 * anfsrate + 0.1 * anfsrate * (stamina + power + willp + wit)) - 4 * (ngfailround + ngtrendround);
	else if (type == 2)
		foldept = (ngfailround + ngtrendround) * (4 * anfsrate + 0.1 * anfsrate * (speed + power + willp + wit)) - 4 * (ngfailround + ngtrendround);
	else if (type == 3)
		foldept = (ngfailround + ngtrendround) * (4 * anfsrate + 0.1 * anfsrate * (speed + stamina + willp + wit)) - 4 * (ngfailround + ngtrendround);
	else if (type == 4)
		foldept = (ngfailround + ngtrendround) * (4 * anfsrate + 0.1 * anfsrate * (speed + stamina + power + wit)) - 4 * (ngfailround + ngtrendround);
	else if (type == 5)
		foldept = (ngfailround + ngtrendround) * (4 * anfsrate + 0.1 * anfsrate * (speed + stamina + willp + power)) - 4 * (ngfailround + ngtrendround);
	//?
	// 
	//计算期待p

	//Todo:stewmpt?
	//end
	//返回
	return foldept;
}
int V4G1umaSCEcore_spept(int type, int fs, int sfs, int dr, int tr, int trap, int gatr, int speed, int stamina, int power, int willp, int wit, int sp)
{
	//将int转换为float
	float a = (1 + 0.01 * fs);
	float b = (1 + 0.01 * sfs);
	float fsrate = a * b;
	float drrate = 1 + 0.002 * dr;
	float trrate = 1 + 0.01 * tr;
	//end


	//得意率计算
	float c = (100 + gatr);
	float d = (550 + gatr);
	float gat = c / d;
	float e = (550 + gatr);
	float ngat = 100 / e;
	float f = (550 + gatr);
	float eht = 50 / f;
	//end

	//计算失效率
	float x = (80 - trap) / 5;
	if (x != int(x))
		if (x > int(x))
			x = 1 + int(x);
		else
			x = int(x);
	//Todo :向上取整
	//end
	float fht = x / 72;//失效率
	//end

	//与回合相关的计算
	//实际训练回合
	int actualround = 10000 - 10000 * eht;
	//失效回
	int failround = actualround * fht;
	//友情训练趋势回合
	int trendround = actualround - failround;
	//end

	//杂项
	//不含友情加成的训练倍率
	float anfsrate = drrate * trrate;
	//包含友情‘s
	float afsrate = fsrate * drrate * trrate;
	//失效回
	int ngfailround = failround * ngat;
	int gfailround = failround * gat;
	//趋势回
	int ngtrendround = trendround * ngat;
	int gtrendround = trendround * gat;
	//end
	float foldept; float mainept;
	int spept;

	spept = gfailround * (afsrate + afsrate * 0.1 * sp) + (actualround - gfailround) * (anfsrate + anfsrate * 0.1 * sp) - actualround;
	//计算期待p

	//Todo:stewmpt?
	//end
	//返回
	return spept;
}

int V3G1umaSCEcore_ept(int type, int fs, int sfs, int dr, int tr, int gatr, int speed, int stamina, int power, int willp, int wit, int sp)
{
	//将int转换为float
	float a = (1 + 0.01 * fs);
	float b = (1 + 0.01 * sfs);
	float fsrate = a * b;
	float drrate = 1 + 0.002 * dr;
	float trrate = 1 + 0.01 * tr;
	//end

	//得意率计算
	float c = (100 + gatr);
	float d = (550 + gatr);
	float gat = c / d;
	float e = (550 + gatr);
	float ngat = 100 / e;
	float f = (550 + gatr);
	float eht = 50 / f;
	//end

	//杂项
	//不含友情加成的训练倍率
	float anfsrate = drrate * trrate;
	//包含友情‘s
	float afsrate = fsrate * drrate * trrate;

	int v3ept{};
	if (type == 1)
	{
		v3ept = ((((anfsrate + anfsrate * 0.1 * speed) * (ngat * 4) + (afsrate + afsrate * 0.1 * speed) * gat) - 0.909) * 10000);
		cin.get();
	}
	else if (type == 2)
		v3ept = ((((anfsrate + anfsrate * 0.1 * stamina) * (ngat * 4) + (afsrate + afsrate * 0.1 * stamina) * gat) - 0.909) * 10000);

	else if (type == 3)
		v3ept = ((((anfsrate + anfsrate * 0.1 * power) * (ngat * 4) + (afsrate + afsrate * 0.1 * power) * gat) - 0.909) * 10000);


	else if (type == 4)
		v3ept = ((((anfsrate + anfsrate * 0.1 * willp) * (ngat * 4) + (afsrate + afsrate * 0.1 * willp) * gat) - 0.909) * 10000);


	else if (type == 5)
		v3ept = ((((anfsrate + anfsrate * 0.1 * wit) * (ngat * 4) + (afsrate + afsrate * 0.1 * wit) * gat) - 0.909) * 10000);
	    
	return v3ept;

}
int V3G2umaSCEcore_ept(int type, int fs, int sfs, int dr, int tr, int gatr, int speed, int stamina, int power, int willp, int wit, int sp)
{
	return 0;
}


double V2umaSCEcore_ept(int type, int fs, int sfs, int dr, int tr, int speed, int stamina, int power, int willp, int wit)
{
	double a = 1 + 0.01 * fs;
	double b = 1 + 0.01 * sfs;
	double ab = a * b;
	double c= 1 + 0.01 * dr;
	double d= 1 + 0.01 * tr;

	double e = ab * c * d;
	double f = 0.01 * ab * c * d ;

	if (type == 1)
	{
		return e + f * speed;
	}
	if (type == 2)
	{
		return e + f * stamina;
	}
	if (type == 3)
	{
		return e + f * power;
	}
	if (type == 4)
	{
		return e + f * willp;
	}
	if (type == 5)
	{
		return e + f * wit;
	}
	else
	{
		return 0;
	}
	
}


#endif

