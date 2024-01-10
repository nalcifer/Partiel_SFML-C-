#pragma once

#include <SFML/Graphics.hpp>

namespace Utils
{
	float GetDistance( float fX1, float fY1, float fX2, float fY2 );
	float GetDegreeToRadian( float fAngleDegree );
	sf::Vector2f GetDirectionFromAngle( float fAngleDegree );
	int GetRandomNumber( int iMin, int iMax );
};

