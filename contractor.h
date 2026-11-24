#pragma once
#include <string>
class contractor
{
private:
	std::string name;
	std::string phone_num;
	std::string qq_num;
	std::string wechat_num;
	std::string email;
public:
	contractor() = default;
	contractor(std::string name, std::string phone, std::string qq, std::string wechat, std::string email) :name(name), phone_num(phone), qq_num(qq), wechat_num(wechat), email(email) {};
	//getters
	std::string getname() { return name; }
	std::string getphone() { return phone_num; }
	std::string getqq() { return qq_num; }
	std::string getwechat() { return wechat_num; }
	std::string getemail() { return email; }
	//修改功能接口
	void altername(std::string info) { name = info; }
	void alterphone(std::string info) { phone_num = info; }
	void alterqq(std::string info) { qq_num = info; }
	void alterwechat(std::string info) { wechat_num = info; }
	void alteremail(std::string info) { email = info; }

};