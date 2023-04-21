#pragma once
class Line
{
public:
	Line(Vector2 start, Vector2 end) :_startPos(start), _endPos(end) {}
	~Line();

	void Update();
	void Render(HDC hdc);

	int length(Vector2 start, Vector2 end)
	{
		return (end - start).Length();
	}

public:
	Vector2 _startPos;
	Vector2 _endPos;
};

