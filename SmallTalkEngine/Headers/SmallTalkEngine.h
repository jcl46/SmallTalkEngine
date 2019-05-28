#include "SmallTalkMath.h"
//I intend to remove the need for external libs later - but for now i'll use them or... hmm
class SmallTalkEngine
{
	public:
		class GameObject
		{
		public:
			
		};
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
				float temp2 = point1.Y + point2.Y;
				temp = pow(temp,2);
				temp2 = pow(temp2, 2);
				temp = temp + temp2;
				temp = sqrt(temp);
				return temp;

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
				Velocity = 0.0f;
			}

		};
		class Area
		{
		private:
			int id;
		};
		class BoxCollider2D
		{
		public:
			float size;
			bool isActive;
			bool isSolid;

			Point2D center;
			BoxCollider2D(float Size, Point2D Center, isSolid = true, isActive = true) 
			{

			}
		};
};
