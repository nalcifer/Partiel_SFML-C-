#include "BallManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.h"

#define RADIUS 20

#define SPEED_MIN 50
#define SPEED_MAX 100

#define ANGLE_MIN 0
#define ANGLE_MAX 360

BallManager::BallManager( sf::RenderWindow* pWindow )
{
    m_pWindow = pWindow;
    //std::vector<Ball> m_oBalls;
}

// 1 ) =============================================================
void BallManager::CreateBall( int iX, int iY, int iRadius )
{
    Ball* myBall = &Ball(iX, iY, iRadius);
    m_oBalls.push_back(myBall);

    /*
        Instruction:
            Crée une balle à la position iX, iY et de radius RADIUS
            et l'ajoute au tableau 'm_oBalls'
    */

    //#TODO
}

void BallManager::DrawBalls( sf::RenderWindow* pWindow ) const
{
    for( int i = 0; i < m_oBalls.size(); ++i )
    {
        m_oBalls[ i ]->Draw( pWindow );
    }
}

// 2 ) =============================================================

Ball* BallManager::GetBallAt( int iX, int iY )
{
    for (int i = 0; i < m_oBalls.size(); ++i)
    {
        if (m_oBalls[i]->IsPointInside(iX, iY)==true) {
            return m_oBalls[i];
        }
    }
    
    return nullptr;
    /*
        Instruction:
            Renvoie la première balle trouvée au point iX, iY
            si aucune balle n'est trouvée renvoie 'nullptr'

        Indication:
            Utiliser la méthode 'IsPointInside' de la classe 'Ball'
    */

    //#TODO
}

void BallManager::DestroyBall( Ball* pBallToDestroy )
{   
    /*for (int i = 0; i < m_oBalls.size(); ++i)
    {
        if (m_oBalls[i]== pBallToDestroy) {
            m_oBalls.erase(m_oBalls[i]);
            //m_oBalls.resize(m_oBalls.size() - 1); 
        }
    */

    /*
        Instruction:
            Retire 'pBallToDestroy' du tableau 'm_oBalls'
            puis la détruit

        Indication:
            Utiliser la méthode 'erase' de la classe 'vector'
    */

    //#TODO
}

// 3 ) =============================================================

void BallManager::LaunchBall( Ball* pBallToLaunch )
{
    int angle = Utils::GetRandomNumber(ANGLE_MIN, ANGLE_MAX);
    sf::Vector2f direction = Utils::GetDirectionFromAngle(angle);
    int speed = Utils::GetRandomNumber(SPEED_MIN, SPEED_MAX);
    pBallToLaunch->Start(direction,speed);
    /*
    Instruction:
        appelle la méthode 'start' de 'pBallToLaunch' en renseignant une direction aléatoire
        entre ANGLE_MIN et ANGLE_MAX, ainsi qu'une vitesse aléatoire entre SPEED_MIN et SPEED_MAX

    Indication:
        Utiliser la/les méthodes du namespace 'Utils'

        Attention:
            Quand on retire un élément d'un tableau qu'on est en train de parcourir
            tous les elements d'après se décallent vers la gauche
    */

    //#TODO
}

void BallManager::UpdateBalls( float fDeltaTime )
{
    for (int i = 0; i < m_oBalls.size(); i++)
    {
        m_oBalls[i]->Update(fDeltaTime);
        if (m_oBalls[i]->IsOutOfBound(0, 0, 1280, 720) == true) {
            DestroyBall(m_oBalls[i]);
            i--;
        }
    }
    /*
    Instruction:
        Met à jour toutes les balles du tableau 'm_oBalls'
        Vérifie si une balle est sortie de l'écran,
        si c'est le case: on retire la balle du tableau 'm_oBalls' et on la détruit

    Indication:
        Utiliser la méthode 'Update' de la classe 'Ball'
        Utiliser la méthode 'IsOutOfBound' de la classe 'Ball'

        Attention:
            Quand on retire un élément d'un tableau qu'on est en train de parcourir
            tous les elements d'après se décallent vers la gauche
    */

    //#TODO
}