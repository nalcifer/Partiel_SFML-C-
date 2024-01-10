#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utils.h"

class Ball
{
private:
	sf::CircleShape m_oModel;

	sf::Vector2f m_oDirection;
	float m_fSpeed;

public:
	Ball( int iX, int iY, int iRadius );

	~Ball();

	void Draw( sf::RenderWindow* pRenderWindow ) const;

	bool IsPointInside( int iX, int iY ) const;

	void Start( const sf::Vector2f& oDirection, float fSpeed );

	void Update( float fDeltaTime );

	bool IsOutOfBound( int iXMin, int iYMin, int iXMax, int iYMax ) const;
};

