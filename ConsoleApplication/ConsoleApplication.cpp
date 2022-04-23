#include "Game.h"
#include "SplashScreen.h"
#include <iostream>
#include "Field.h"

int main()
{
    
    
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");







    srand(time(NULL));

    Game game;

    game.pushState(new SplashScreen(&game));
    game.gameLoop();
    return 0;



  /*  sf::Clock clock;
    while (window.isOpen())
    {
  
        sf::Time time = clock.getElapsedTime();
        int f = time.asSeconds();
        std::cout << f << std::endl;

        
        window.clear(sf::Color::Blue);
 
       
        window.display();
    }*/

}
