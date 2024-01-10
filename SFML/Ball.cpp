#include "Ball.h"

// 1 ) =============================================================
Ball::Ball( int iX, int iY, int iRadius )
{
	std::cout << "CREATED" << std::endl;

	m_oModel.setOrigin( iRadius, iRadius );
	m_oModel.setPosition( iX, iY );
	m_oModel.setRadius( iRadius );

	m_oDirection.x = 0.f;
	m_oDirection.y = 0.f;

	m_fSpeed = 0.f;
}

Ball::~Ball()
{
	std::cout << "DESTROYED" << std::endl;
}

void Ball::Draw( sf::RenderWindow* pRenderWindow ) const
{
	pRenderWindow->draw( m_oModel );
}

// 2 ) =============================================================
bool Ball::IsPointInside( int iX, int iY ) const
{
	sf::Vector2f positionBall = m_oModel.getPosition();
	float distance = Utils::GetDistance(iX, iY, positionBall.x, positionBall.y);
	if (distance > 0) {
		return true;
	}
	else {
		return false;
	}

	/*
		Instruction:
			Renvoie 'True' si le point est dans le cercle False' sinon 

		Indication:
			Utiliser la/les fonctions du namespace 'Utils'
	*/

	//#TODO
}

// 3 ) =============================================================
void Ball::Start( const sf::Vector2f& oDirection, float fSpeed )
{
	m_oDirection = oDirection;
	m_fSpeed = fSpeed;
}

void Ball::Update( float fDeltaTime )
{
	sf::Vector2f position = m_oModel.getPosition();
	float newX = position.x + (m_fSpeed * (fDeltaTime * m_oDirection.x));
	float newY = position.y + (m_fSpeed * (fDeltaTime * m_oDirection.y));
	m_oModel.setPosition(newX, newY);
	/*
		Instruction:
			Fait avancer d'une frame la balle dans sa direction (m_oDirection) 
			en respectant sa vitesse (m_fSpeed)

		Indication:
			fDeltaTime represente le temps écoulé (en seconde) depuis la dernière frame
			m_fSpeed la vitesse de la balle (en pixel par seconde)
			m_oDirection le vecteur de direction de la balle (le vecteur a une norme de 1 pixel)
	*/

	//#TODO
}

bool Ball::IsOutOfBound( int iXMin, int iYMin, int iXMax, int iYMax ) const
{
	sf::Vector2f position = m_oModel.getPosition();
	if (position.x<=iXMin || position.x>= iXMax || position.y<=iYMin || position.y <= iYMax) {
		return true;
	}
	else {
		return false;
	}
	/*
		Instruction:
			Renvoie 'True' si la balle est en dehors du rectangle representé par iXMin, iYMin, iXMax, iYMax
			'False' sinon

		Indication:
			On fera une approximation, on considerera la balle comme un carré pour savoir si ses bords
			sont en dehors du rectangle
	*/

	//#TODO
}