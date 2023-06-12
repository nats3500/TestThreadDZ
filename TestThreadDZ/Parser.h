#pragma once
#include <filesystem>
#include <regex>
#include <fstream>
#include <mutex>
#include <iterator>
#include <exception>
#include "Config.h"
class Parser
{
public:
	Parser(Config& config) : config{ config }, threads{}, paths{} {}
	void createThreads();
	void changeText();
	void joinThred();
private:
	Config config;
	std::vector<std::thread> threads;
	std::vector<std::filesystem::path> paths;
	bool isNotCheck(std::filesystem::path& path);
};

