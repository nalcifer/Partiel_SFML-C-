#include "Utils.h"

#include <cmath>

#define M_PI 3.14159265358979323846

float Utils::GetDistance( float fX1, float fY1, float fX2, float fY2 )
{
	float fX = fX1 - fX2;
	float fY = fY1 - fY2;

	return sqrt( fX * fX + fY * fY );
}

float Utils::GetDegreeToRadian( float fAngleDegree )
{
	return fAngleDegree * M_PI / 180.f;
}

sf::Vector2f Utils::GetDirectionFromAngle( float fAngleDegree )
{
	sf::Vector2f oOut;

	float fAngleRadian = GetDegreeToRadian( fAngleDegree );

	oOut.x = cos( fAngleRadian );
	oOut.y = -sin( fAngleRadian );

	return oOut;
}

int Utils::GetRandomNumber( int iMin, int iMax )
{
	int iRandom = std::rand();

	iRandom = ( iRandom % ( iMax - iMin ) ) + iMin;

	return iRandom;
}