#include "Game.h"
#include "SplashScreen.h"
#include <iostream>
#include "Field.h"
#include "SFML/Network.hpp"
#include <thread>
#include <fstream>
void morenka()
{
    std::cout << " oro" << std::endl;
}
int main()
{


 /*   std::thread p1(morenka);
    p1.join();*/
   /* std::vector<std::string> poland;
    std::string nazwa;
    std::fstream plik("morenka.txt", std::ios::out | std::ios::app);
    std::fstream plik34("morenka34.txt", std::ios::out | std::ios::app);
    int a;
    std::string tab[5] = { "Marek","Poziomek","Alberto","Jhin", "Diego"};

    for (int i = 0; i < 5; i++)
    {
        plik << tab[i] << std::endl;
    }


    std::ifstream plik2("morenka.txt");
    while (getline(plik2, nazwa))
    {
        poland.push_back(nazwa);
    }
    

    std::cout << poland.size() << std::endl;*/

    
    //std::ifstream plik2("morenka.txt");

    //plik2 >> a >> std::e
    //    poland.push_back(a);

    //for (int i = 0; i < poland.size(); i++)
    //{
    //    std::cout << poland[i];
    //}
    
    
    srand(time(NULL));

    Game game;

    game.pushState(new SplashScreen(&game));
    game.gameLoop();

    return 0;



   
    


    
}

//#include <filesystem>
//#include <fstream>;
//#include <regex>



//namespace fs = std::filesystem;
//int sum = 0;

//void check_res_frame(std::string p)
//{
//    std::regex res_frame("^[1-9][0-9]*");
//
//    if (std::regex_match(p, res_frame))
//    {
//        sum++;
//    }
//
//
//}
//
//void check_vertical_sync(std::string p)
//{
//    std::regex vertical("^[0-1]$");
//    if (std::regex_match(p, vertical))
//    {
//        sum++;
//  

/*  sf::Clock clock;
  while (window.isOpen())
  {

      sf::Time time = clock.getElapsedTime();
      int f = time.asSeconds();
      std::cout << f << std::endl;


      window.clear(sf::Color::Blue);


      window.display();
  }*/

//sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");



/*   sf::Keyboard::Key input;
   input = sf::Keyboard::Key::A;
   std::string text = fromKeytoString(input);

   std::cout << text << std::endl;*/




   //fs::path config_dir("c:/users/zento/source/repos/rixis321/pong-game/consoleapplication/consoleapplication");
   //
   //        for (auto& iter : fs::directory_iterator(config_dir))
   //   {
   //    std::string pog = iter.path().filename().string();
   //    if (pog == "config")
   //    {
   //       
   //        for (auto& iter2 : fs::directory_iterator(config_dir / "config"))
   //        {
   //            std::string file2 = iter2.path().filename().string();
   //            if (file2 == "settings.txt")
   //            {
   //                
   //                fs::path path2(config_dir / "config" / "settings.txt");
   //                std::ifstream plik(path2);
   //                if (plik.is_open())
   //                {
   //                    std::string line1,line2;
   //                    std::getline(plik, line2);
   //                    plik >> line1 >> line2;
   //                    check_res_frame(line1);
   //                    check_res_frame(line2);
   //                    plik >> line1;
   //                    check_res_frame(line1);
   //                    plik >> line1;
   //                    check_vertical_sync(line1);
   //                    if (sum != 4)
   //                    {
   //                        throw "Invaild data. Check setting file";
   //                    }

   //                }
   //                   
   //            }
   //            else
   //            {
   //                std::ofstream plik(config_dir/"config"/"settings.txt");
   //                while (plik)
   //                {
   //                    plik << "Pong Game" << std::endl;
   //                    plik << "800 600" << std::endl;
   //                    plik << "120" << std::endl;
   //                    plik << "0" << std::endl;
   //                    plik.close();
   //                    break;
   //                }
   //               

   //            }

   //        }

   //        }
   //        else
   //        {
   //        fs::create_directory(config_dir /"config");
   //        }
   //   }

