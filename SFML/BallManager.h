#pragma once

#include <vector>

namespace sf
{
    class RenderWindow;
}

class Ball;

class BallManager
{
private:
    sf::RenderWindow* m_pWindow;

    std::vector<Ball*> m_oBalls;

public:
    BallManager( sf::RenderWindow* pWindow );

    void CreateBall( int iX, int iY, int iRadius );

    Ball* GetBallAt( int iX, int iY );

    void DestroyBall( Ball* pBallToDestroy );

    void LaunchBall( Ball* pBallToLaunch );

    void UpdateBalls( float fDeltaTime );

    void DrawBalls( sf::RenderWindow* pWindow ) const;
};

