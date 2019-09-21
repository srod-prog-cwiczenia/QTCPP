#pragma once
class TMenu
{
private:
	vector<string> tabItemsV;
public:
	void add(string item);
	unsigned int wybierz();
	TMenu();
	~TMenu();
};

