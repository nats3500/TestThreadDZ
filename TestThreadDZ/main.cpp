#include <iostream>
#include <thread>
#include "Config.h"
#include "Parser.h"




using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	Config config;
	config.setThreads(8);
	config.setRoot("D:\\Testovaya_papka");
	
	cout << "Ввод шаблона и значения через пробел\n";
	config.setTemplate(2);

	cout << config.getThreads() << endl;
	cout << config.getRoot() << endl;
	auto res = config.getTemplates();
	for (auto it : res)
	{
		cout << it.key << ' ' << it.value << endl;
	}

	//config.save();
	////config.load();
	//Config config2;
	//config2.load();

	//cout << config2.getThreads() << endl;
	//cout << config2.getRoot() << endl;
	//auto res2 = config2.getTemplates();
	//for (auto it : res)
	//{
	//	cout << it.key << ' ' << it.value << endl;
	//}

	Parser pars(config);
	/*config.getThreads() > 0 ? pars.createThreads() : pars.changeText();*/
	pars.createThreads();

	
	pars.joinThred();
	return 0;
}