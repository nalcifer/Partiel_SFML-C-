
#include <SFML/Graphics.hpp>
#include <vector>

#include "Utils.h"
#include "BallManager.h"
#include "Ball.h"

#define WIDTH 1280
#define HEIGHT 720

class Program
{
private:
    sf::RenderWindow m_oWindow;
    BallManager oBallManager;

public:
    Program() :
    m_oWindow( sf::VideoMode( WIDTH, HEIGHT ), "SFML" ), 
    oBallManager( &m_oWindow )
    {
        std::srand( std::time( nullptr ) );
    }

    int Launch()
    {
        //GAMELOOP
        sf::Clock oClock;
        float fDeltaTime = 0.f;
        while( m_oWindow.isOpen() )
        {
            Event();

            Update( fDeltaTime );
            
            Draw();

            fDeltaTime = oClock.restart().asSeconds();
        }

        return 0;
    }

private:
    void Event()
    {
        sf::Event oEvent;
        while( m_oWindow.pollEvent( oEvent ) )
        {
            if( oEvent.type == sf::Event::Closed )
                m_oWindow.close();

            if( oEvent.type == sf::Event::MouseButtonPressed )
            {
                if( oEvent.mouseButton.button == sf::Mouse::Left )
                {
                    OnMouseLeft();
                }
                else
                if( oEvent.mouseButton.button == sf::Mouse::Middle )
                {
                    OnMouseMiddle();
                }
                else
                if( oEvent.mouseButton.button == sf::Mouse::Right )
                {
                    OnMouseRight();
                }   
            }
        }
    }

    // 1 ) =============================================================
    void OnMouseLeft()
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_oWindow);
        oBallManager.CreateBall(mousePosition.x, mousePosition.y, 10);
        /*
        Instruction:
            Crée une balle à la position de la souris

        Indication:
            Utiliser 'sf::Mouse::getPosition' pour obtenir les coordonnées de la souris
            (attention à bien mettre la fenêtre en paramètre)

            Utiliser la/les méthodes de la classe 'BallManager'
        */

        //#TODO
    }

    // 2 ) =============================================================
    void OnMouseMiddle()
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_oWindow);
        Ball* ballToDestroy = oBallManager.GetBallAt(mousePosition.x, mousePosition.y);
        oBallManager.DestroyBall(ballToDestroy);

        /*
        Instruction:
            Selectionne une balle à la position de la souris et la détruit

        Indication:
            Utiliser 'sf::Mouse::getPosition' pour obtenir les coordonnées de la souris
            (attention à bien mettre la fenêtre en paramètre)

            Utiliser la/les méthodes de la classe 'BallManager'
        */

        //#TODO
    }

    // 3 ) =============================================================
    void OnMouseRight()
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_oWindow);
        Ball* ballToLaunch = oBallManager.GetBallAt(mousePosition.x, mousePosition.y);
        oBallManager.LaunchBall(ballToLaunch);

        /*
        Instruction:
            Selectionne une balle à la position de la souris et l'envoie
            dans une direction aléatoire à une vitesse aléatoire

        Indication:
            Utiliser 'sf::Mouse::getPosition' pour obtenir les coordonnées de la souris
            (attention à bien mettre la fenêtre en paramètre)

            Utiliser la/les méthodes de la classe 'BallManager'
        */

        //#TODO
    }

    void Update( float fDeltaTime )
    {
        oBallManager.UpdateBalls( fDeltaTime );
    }

    void Draw()
    {
        m_oWindow.clear();

        oBallManager.DrawBalls( &m_oWindow );

        m_oWindow.display();
    }
};


int main( int argc, char* argv[] )
{
    Program oProgram;

    int iErrorCode = oProgram.Launch();

    return iErrorCode;
}