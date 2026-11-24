#pragma once
#include "contractor.h"
#include <vector>
class manager
{
private:
	std::vector<contractor> contractors;
public:
	manager() = default;
	//功能模块
	void build_by_files(std::string filename);
	bool insert();
	int seek(std::string name);
	void alter_info(std::string name);
	bool drop();
	void output_all();
	void output_one();
};

