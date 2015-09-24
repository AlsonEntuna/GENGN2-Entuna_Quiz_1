#include "BaseObject.h"

void BaseObject::setX(float val)
{
    //x = val;
	m_transform.GetPos()->x = val;
}

void BaseObject::setY(float val)
{
   // y = val;
	m_transform.GetPos()->y = val;
}

void BaseObject::setZ(float val)
{
    //z = val;
	m_transform.GetPos()->z = val;
}

float BaseObject::getX()
{
    //return x;
	return m_transform.GetPos()->x;
}

float BaseObject::getY()
{
    //return y;
	return m_transform.GetPos()->y;
}

float BaseObject::getZ()
{
   // return z;
	return m_transform.GetPos()->z;
}

ModelTransform* BaseObject::Transform(){ return &m_transform; }
