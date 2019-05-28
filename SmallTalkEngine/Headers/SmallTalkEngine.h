#include <math.h>
class SmallTalkEngine
{
	public:
		class Point2D
		{
		public:
			float X;
			float Y;
			Point2D(float x, float y)
			{
				X = x;
				Y = y;
			}
			float DistanceCalc(Point2D point1, Point2D point2)
			{
				float temp = point1.X + point2.X;
				temp = pow(temp,2);

			}
		};
		class Vector2D
		{
		public:
			float X;
			float Y;
			float Velocity;
			Vector2D(float x, float y, float velocity)
			{
				X = x;
				Y = y;
				Velocity = velocity;
			}
			Vector2D(float x, float y)
			{
				X = x;
				Y = y;
				Velocity = 0;
			}

		};
};
