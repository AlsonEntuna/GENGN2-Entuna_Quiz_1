#include "BaseObject.h"

void BaseObject::setX(float val)
{
	m_transform.GetPos()->x = val;
}

void BaseObject::setY(float val)
{
	m_transform.GetPos()->y = val;
}

void BaseObject::setZ(float val)
{
	m_transform.GetPos()->z = val;
}

float BaseObject::getX()
{
	return m_transform.GetPos()->x;
}

float BaseObject::getY()
{
	return m_transform.GetPos()->y;
}

float BaseObject::getZ()
{
	return m_transform.GetPos()->z;
}

ModelTransform* BaseObject::Transform(){ return &m_transform; }
