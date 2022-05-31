#include "ProfileManager.h"

void ProfileManager::Draw(const float dt)
{
	this->game->window->draw(rec);
	
	if (this->load_mode == false)
	{
		this->game->window->draw(this->text_box);
		for (int i = 0; i < buttons.size(); i++)
		{
			this->buttons[i]->Draw(this->game->window);
		}
		if (isValid)
		{
			sf::Text invalid_profile;
			invalid_profile.setFont(font);
			invalid_profile.setCharacterSize(12);
			invalid_profile.setPosition(320, 315);
			invalid_profile.setString("Invalid profile name. Try again!");
			this->game->window->draw(invalid_profile);
		}
		if (isExist)
		{
			sf::Text invalid_profile;
			invalid_profile.setFont(font);
			invalid_profile.setCharacterSize(12);
			invalid_profile.setPosition(290, 315);
			invalid_profile.setString("This profile exists. Use a different name.");
			this->game->window->draw(invalid_profile);
		}
	}
	else
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			this->buttons[i]->Draw(this->game->window);
		}
	}
	
	
}

void ProfileManager::Update(const float dt)
{
	this->UpdateButtons();
}

void ProfileManager::saveToFile()
{
	std::fstream plik("C:/Users/zento/source/repos/rixis321/Pong-game/ConsoleApplication/ConsoleApplication/data/data.txt");

	for (int i = 0; i < players.size(); i++)
	{
		plik << players[i]->profile_name << std::endl;
	}

}

void ProfileManager::Input()
{
	sf::Event event;
	std::string inputText;

	while (this->game->window->pollEvent(event))
	{
		if (this->load_mode == false)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->game->popState();
					break;
				}
				else  if (event.key.code == sf::Keyboard::Up)
				{

					if (optionIndex > 0)
					{
						optionIndex--;
					}
					else
					{
						optionIndex = buttons.size() - 1;
					}


				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					if (optionIndex < buttons.size() - 1)
					{
						optionIndex++;
					}
					else
						optionIndex = 0;
				}

				else if (optionIndex == 0)
				{
					if (event.key.code == sf::Keyboard::Enter)
					{
						if (this->check == false)
						{
							this->check = true;
						}
						else
							this->check = false;
					}
				}
				else if (optionIndex == 2)
				{
					if (event.key.code == sf::Keyboard::Enter)
					{
						this->game->popState();
						break;
					}
				}
				else if (optionIndex == 1)
				{
					if (this->player->profile_name.size() <= 0)
					{
						isValid = true;
					}
					else
					{
						if (checkProfile(this->player->profile_name) == true)
						{
							this->players.push_back(this->player);
							
							saveToFile();
	
							this->game->pushState(new Main_menu(game,this->player->profile_name));
						}
						else
						{
							isExist = true;
						}


					}


				}


			}
			else if (optionIndex == 0)
			{
				if (this->check == true)
				{
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128)
						{
							if (std::isprint(event.text.unicode))
							{
								this->player->profile_name += event.text.unicode;
								this->player_input.setString(this->player->profile_name);

								this->player->profile_name = removeSpaces(this->player->profile_name);

								buttons[0]->text.setString(this->player->profile_name);


							}
							else if (event.text.unicode == 8)
							{

								this->player->profile_name = this->player->profile_name.substr(0, this->player->profile_name.size() - 1);
								this->player_input.setString(this->player->profile_name);
								buttons[0]->text.setString(this->player->profile_name);

							}
						}
					}
				}
			}
		}
		else
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->game->popState();
					break;
				}
				else  if (event.key.code == sf::Keyboard::Down)
				{

					if (optionIndex > 0)
					{
						optionIndex--;
					}
					else
					{
						optionIndex = buttons.size() - 1;
					}


				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					if (optionIndex < buttons.size() - 1)
					{
						optionIndex++;
					}
					else
						optionIndex = 0;
				}
				else
				{
					std::string name = this->players[optionIndex]->profile_name;
					this->game->pushState(new Main_menu(game,name));
					
					
					
				}

			}

			

			
		}
		
		


	}

}

void ProfileManager::loadDataFromFile()
{
	bool flag = false;
	namespace fs = std::filesystem;

	fs::path data_dir("C:/Users/zento/source/repos/rixis321/Pong-game/ConsoleApplication/ConsoleApplication");
	for (auto& iter : fs::directory_iterator(data_dir))
	{
		std::string file = iter.path().filename().string();
		if (file == "data")
		{
			flag = true;
			break;
		}
			
	}

	if (flag)
	{
		for (auto& iter2 : fs::directory_iterator(data_dir / "data"))
		{
			std::string file2 = iter2.path().filename().string();
			if (file2 == "data.txt")
			{
				fs::path path2(data_dir / "data" / "data.txt");
				std::ifstream plik(path2);
				std::string profile_name;
				while (getline(plik, profile_name))
				{
					Player* _player = new Player;
					_player->profile_name = profile_name;
					players.push_back(_player);
				}
			}
			else
				std::ofstream plik2(data_dir / "data" / "data.txt");
		}
	}
	else
	{
		fs::create_directory(data_dir / "data");
		std::ofstream plik2(data_dir / "data" / "data.txt");
	}
	

}



bool ProfileManager::checkProfile(std::string name)
{
	if (!players.empty())
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i]->profile_name == name)
			{
				return false;
			}
			else 
				return true;
		}
	}
	else
		return true;

}

void ProfileManager::UpdateButtons()
{
	if (this->buttons.empty())
		return;

	this->buttons[optionIndex]->Update();
}

void ProfileManager::loadProfiles()
{
	float position = 250.0f;

	

	for (int i = 0; i < players.size(); i++)
	{
		buttons.push_back(new Button(rec.getSize().x / 2 + 330, rec.getSize().y / 2 + position + 170, 180, 40, &font,this->players[i]->profile_name, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
		position -= 50;
		
	}

	
}

ProfileManager::ProfileManager(Game *game)
{

	this->player = new Player;
	// do wpisywania tekstu do przycisku
	this->check = false;
	// czy profil jest prawidlowy (> 0)
	this->isValid = false;
	// czy profil istnieje
	this->isExist = false;
	// tryb dzialania na create profile
	this->load_mode = false;


	loadDataFromFile();
	this->game = game;
	sf::Color color(168, 81, 171, 40);
	rec.setFillColor(color);
	rec.setSize({float(this->game->window->getSize().x/2),float(this->game->window->getSize().y / 2) });
	rec.setPosition(float(this->game->window->getPosition().x / 2 - 60), float(this->game->window->getPosition().y / 2 + 70));

	font.loadFromFile("textures/gol.ttf");

	this->text_box.setFont(font);
	this->text_box.setCharacterSize(12);
	this->text_box.setPosition(260, 230);
	this->text_box.setString("Enter a profile name");

	this->buttons.push_back(new Button(rec.getSize().x / 2 + 50, rec.getSize().y / 2 + 100, 340, 50, &font, "", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(rec.getSize().x /2 + 150, rec.getSize().y / 2 + 190  , 150, 50, &font, "Create", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(rec.getSize().x / 2 + 150, rec.getSize().y / 2 + 250, 150, 50, &font, "Back", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	
}

ProfileManager::ProfileManager(Game* game, bool mode)
{
	this->game = game;
	// tryb dzialania na load profile
	this->load_mode = mode;

	loadDataFromFile();
	loadProfiles();
	sf::Color color(168, 81, 171, 40);
	rec.setFillColor(color);
	rec.setSize({ float(this->game->window->getSize().x / 2),float(this->game->window->getSize().y / 2 + 100) });
	rec.setPosition(float(this->game->window->getPosition().x / 2 - 60), float(this->game->window->getPosition().y / 2 + 70));
		

	
	font.loadFromFile("textures/gol.ttf");





}

ProfileManager::~ProfileManager()
{
	for (auto& it : buttons)
	{
		delete it;
	}
	

	for (auto& it : players)
	{
		delete it;
	}

}
// sprawdzac spacje
// duza litera