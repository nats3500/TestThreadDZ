#include "Parser.h"

void Parser::createThreads()
{
	/*const unsigned cores_count = std::thread::hardware_concurrency();
	const unsigned cores_count*/

	for (unsigned i = 0; i < config.getThreads() /*< cores_count ? config.getThreads() : cores_count*/; i++)
	{
		std::thread th([&](){ this->changeText(); });
		threads.push_back(std::move(th));
	}
	/*for (auto& th : this->threads )
	{
		if (th.joinable())
			th.join();
	}*/
}

void Parser::changeText(/*Config& config*/)
{
	//using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
	//std::mutex locker;
	//locker.lock();
	
	for (auto& dirEntry : std::filesystem::recursive_directory_iterator(config.getRoot()))
	{

		if (!dirEntry.is_directory())
		{
			std::filesystem::path path;
			path = dirEntry.path();

			//std::mutex locker;
			/*locker.lock();
			bool isNotCheck = true;
			for (auto it : paths)
				if (it == path)
					isNotCheck = false;

			if (isNotCheck)
				paths.push_back(path);
			locker.unlock();*/

			if (isNotCheck(path)/*isNotCheck*/)
			{
						
				//locker.lock();
				std::cout << std::this_thread::get_id() << ' ' << path << std::endl;
				std::ifstream file;
				/*std::mutex mtx;
				mtx.lock();*/
				//;
				file.open(path);
				//locker.unlock();

				if (file.is_open())
				{
								
					//std::cout << std::this_thread::get_id() << ' ' << path << std::endl;
					//locker.lock();
					std::string all_text(std::istreambuf_iterator<char>{file}, {});
					//locker.unlock();

					for (auto it : config.getTemplates())
						all_text = std::regex_replace(all_text, std::regex(it.key), it.value);
					file.close();

					std::ofstream file2;
					//locker.lock();
					file2.open(path);
					//mtx.unlock();
					if (file2.is_open())
					{
						//исправить баг
						file2 << all_text;
						file2.close();
					}
					//locker.unlock();			
				}			
			}
		}
	}
	
		//
	//locker.unlock();
	//paths.clear();
}

void Parser::joinThred()
{
	for (auto& th : this->threads )
	{
		if (th.joinable())
			th.join();
	}
}

bool Parser::isNotCheck(std::filesystem::path& path)
{
	std::mutex locker;
	locker.lock();
	bool isNotCheck = true;
	for (const auto& it : paths)
	{ 
		if (it == path)
			isNotCheck = false;
	}
	if (isNotCheck)
		paths.push_back(path);
	locker.unlock();
	return 	isNotCheck ;
	
	//joinThred();
}



