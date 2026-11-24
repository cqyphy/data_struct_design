#include "manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
void manager::build_by_files(std::string filename) {//文件里必须以'|'为分隔符
	std::ifstream in;
	in.open(filename);
	if (!in.is_open())
	{
		std::cout << "No such file" << std::endl;
		return;
	}
	std::string str;
	while (std::getline(in, str))
	{
		std::stringstream ss(str);
		std::string name, phone, qq, wechat, email;
		std::getline(ss, name, '|');
		std::getline(ss, phone, '|');
		std::getline(ss, qq, '|');
		std::getline(ss, wechat, '|');
		std::getline(ss, email, '|');
		contractor tmp(name, phone, qq, wechat, email);
		contractors.push_back(tmp);
	}
	std::sort(contractors.begin(), contractors.end(), [](contractor a, contractor b) {
			return a.getname()[0] < b.getname()[0]; 
		}
	);
}
	bool manager::insert() {
		std::string name, phone, qq, wechat, email;
		std::cout << "input contractor's name:" << std::endl;
		std::getline(std::cin, name);
		int p = seek(name);
		if (p != -1) {//第一次查重判别
			std::cout << "same name contractor exist, still add?(y/n)";
			int tmp_c = getchar();
			if (tmp_c == 'n' || tmp_c == 'N') return false;
		}
		std::cout << "input contractor's phone number:" << std::endl;
		std::getline(std::cin, phone);
		if (phone == contractors[p].getphone())//第二次查重判别
		{
			std::cout << "same phone number!! ending this operation" << std::endl;
			return false;
		}
		std::cout << "input contractor's qq number:" << std::endl;
		std::getline(std::cin, qq);
		std::cout << "input contractor's wechar number:" << std::endl;
		std::getline(std::cin, wechat);
		std::cout << "input contractor's email:" << std::endl;
		std::getline(std::cin, email);
		contractor tmp(name, phone, qq, wechat, email);
		contractors.push_back(tmp);
		return true;
	}

	int manager::seek(std::string name) {
		auto res = std::find(contractors.begin(), contractors.end(), [&name](const auto &x) {
			return name == x.name;
			});
		if (res != contractors.end())
		{
			return std::distance(contractors.begin(), res);
		}
		else return -1;
	}

	void manager::alter_info(std::string name) {
		int p = seek(name);
		if (p == -1)
		{
			std::cout << "no such contractor" << std::endl;
			return ;
		}
		bool alter_cyc = true;
		while (alter_cyc)
		{
			std::cout << "choose you want to alter:" << std::endl
				<< "1.name" << std::endl
				<< "2.phone number" << std::endl
				<< "3.qq number" << std::endl
				<< "4.wechat number" << std::endl
				<< "5.email" << std::endl
				<< "6.exit" << std::endl;
			int choose;
			std::cin >> choose;
			std::cout << "alter to:" << std::endl;
			std::string alter_info;
			std::cin >> alter_info;
			switch (choose)
			{
			case 1:
				contractors[p].altername(alter_info);
				break;
			case 2:
				contractors[p].alterphone(alter_info);
				break;
			case 3:
				contractors[p].alterqq(alter_info);
				break;
			case 4:
				contractors[p].alterwechat(alter_info);
				break;
			case 5:
				contractors[p].alteremail(alter_info);
				break;
			default:
				choose = false;
				break;
			}
		}
	}

	bool manager::drop() {

	}

	void manager::output_all() {

	}

	void manager::output_one() {

	}
