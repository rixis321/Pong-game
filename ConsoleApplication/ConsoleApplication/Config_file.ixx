export module Config_file;
import <filesystem>;
import <iostream>;
import <fstream>;
import <string>;
import <regex>;


namespace fs = std::filesystem;
int sum = 0;
std::string profile;
fs::path config_dir("C:/Users/zento/source/repos/rixis321/Pong-game/ConsoleApplication/ConsoleApplication");

void check_res_frame(std::string p)
{
	std::regex res_frame("^[1-9][0-9]*");

	if (std::regex_match(p, res_frame))
	{
		sum++;
	}


}

void check_vertical_sync(std::string p)
{
	std::regex vertical("^[0-1]$");
	if (std::regex_match(p, vertical))
	{
		sum++;
	}
}

void init_settingsFile()
{
	std::ofstream plik(config_dir / "config" / "settings.txt");
	while (plik)
	{
		plik << "Pong Game" << std::endl;
		plik << "800 600" << std::endl;
		plik << "120" << std::endl;
		plik << "0" << std::endl;
		plik.close();
		break;
	}
}

export void set_configFile()
{
	for (auto& iter : fs::directory_iterator(config_dir))
	{
		std::string file = iter.path().filename().string();
		if (file == "config")
		{
			for (auto& iter2 : fs::directory_iterator(config_dir / "config"))
			{
				std::string file2 = iter2.path().filename().string();
				if (file2 == "settings.txt")
				{

					fs::path path2(config_dir / "config" / "settings.txt");
					std::ifstream plik(path2);
					if (plik.is_open())
					{
						std::string line1, line2;
						std::getline(plik, line2);
						plik >> line1 >> line2;
						check_res_frame(line1);
						check_res_frame(line2);
						plik >> line1;
						check_res_frame(line1);
						plik >> line1;
						check_vertical_sync(line1);
						if (sum != 4)
						{
							std::cout << "Starting game in a safe mode" << std::endl;
							init_settingsFile();
							break;
						}
						break;
					}
				}
				else
					init_settingsFile();


			}
		}
		else
			{
				fs::create_directory(config_dir / "config");

			}
	}
}



