#include "Config.h"

void Config::setThreads(const unsigned threads)
{
	this->threads = threads;
}

void Config::setRoot(const std::string& root)
{
	this->root = root;
}

void Config::setTemplate(const unsigned countTemplat)
{
	for (unsigned i = 0; i < countTemplat; i++)
	{
		Pair pair;
		std::cin >> pair.key >> pair.value;
		templates.push_back(pair);
	}
}

void Config::save()
{
	std::ofstream file;
	file.open("Config.txt");
	if (file.is_open())
	{
		file << threads << std::endl << templates.size() << std::endl
			<< root << std::endl;
		for (unsigned i = 0; i < templates.size(); i++)
		{
			file << templates[i].key << std::endl << 
				templates[i].value << std::endl;
		}
		file.close();
	}
}

void Config::load()
{
	std::ifstream file;
	file.open("Config.txt");
	if (file.is_open())
	{
		unsigned size;
		std::string txt;
		file >> threads >> size;
		templates.resize(size);
		file.get();
		getline(file, txt);
		root = txt;
		for (unsigned i = 0; i < size; i++)
		{
			getline(file, txt);
			templates[i].key = txt;
			getline(file, txt);
			templates[i].value = txt;
		}

		file.close();
	}
}
