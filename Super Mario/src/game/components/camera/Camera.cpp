#include "stdafx.h"
#include "Camera.h"

Camera* Camera::m_Instance;

Camera::Camera()
{
	
}


Camera::~Camera()
{
	delete(m_Instance);
}

Camera* Camera::Instance()
{
	if (m_Instance == NULL) {
		m_Instance = new Camera();
	}
	return m_Instance;
}

void Camera::init(int* width, int* height)
{
	m_X = 0;
	m_Y = 0;
	m_Width = width;
	m_Height = height;

}

int& Camera::GetX()
{
	return m_Y;
}

int& Camera::GetY()
{
	return m_X;
}

int& Camera::GetWidth()
{
	return *m_Width;
}

int& Camera::GetHeight()
{
	return *m_Height;
}
