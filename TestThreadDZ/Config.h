#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


struct Pair
{
	std::string key;
	std::string value;
};

class Config
{
public:
	

	void setThreads(const unsigned threads);
	void setRoot(const std::string& root);
	void setTemplate(const unsigned countTemplat);

	unsigned getThreads() const { return threads; }
	const std::string& getRoot() const { return root; }
	const std::vector<Pair>& getTemplates() const { return templates; }

	void save();
	void load();


private:

	std::string root;
	std::vector<Pair> templates;
	unsigned threads;
};

