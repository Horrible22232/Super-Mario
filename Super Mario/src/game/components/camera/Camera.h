#pragma once
class Camera
{
protected:
	Camera();
	~Camera();
public:
	void init(int* width, int* height);
	int& GetX();
	int& GetY();
	int& GetWidth();
	int& GetHeight();
	static Camera* Instance();
private:
	int m_X;
	int m_Y;
	int* m_Width;
	int* m_Height;
	static Camera* m_Instance;
};

