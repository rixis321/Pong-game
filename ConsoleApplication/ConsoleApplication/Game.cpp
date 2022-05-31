#include "Game.h"


void Game::loadTextures()
{
    texmgr.loadTextures("background", "textures/menu.png");
    texmgr.loadTextures("player", "textures/paddle.png");
    texmgr.loadTextures("field", "textures/background_field.png");
    texmgr.loadTextures("splash", "textures/Splash.png");
    texmgr.loadTextures("ball", "textures/ball.png");
  
}

void Game::pushState(State* state)
{
    this->states.push(state);
}   

void Game::popState()
{
    delete this->states.top();
    this->states.pop();
}

void Game::changeState(State* state)
{
    if (!this->states.empty())
    {
        popState();
    }
    pushState(state);
}

State* Game::peekState()
{
    if (this->states.empty())
    {
        return nullptr;
    }
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (this->window->isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        if (peekState() == nullptr)
        {
            continue;
        }
        peekState()->Input();
        peekState()->Update(dt);
       
      //  this->window->clear();
        peekState()->Draw(dt);
        this->window->display();
        

    }
}

Game::Game()
{
   
    std::string title;
    sf::VideoMode window_b;
    unsigned int framerate_limit;
    bool vertical_sync;
    set_configFile();
    std::ifstream stream("C:/Users/zento/source/repos/rixis321/Pong-game/ConsoleApplication/ConsoleApplication/config/settings.txt");

    if (stream.is_open())
    {
        std::getline(stream, title);
        stream >> window_b.width >> window_b.height;
        stream >> framerate_limit;
        stream >> vertical_sync;
    }

    this->window = new sf::RenderWindow(window_b, title.c_str());
    this->loadTextures();
    this->background.setTexture(this->texmgr.getRef("background"));
    this->player.setTexture(this->texmgr.getRef("player"));
    this->playing_field.setTexture(this->texmgr.getRef("field"));
    this->splash_screen.setTexture(this->texmgr.getRef("splash"));
    this->sp_ball.setTexture(this->texmgr.getRef("ball"));
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync);
  

    
}

Game::~Game()
{
    while (!this->states.empty())
    {
        popState();
    }
}










