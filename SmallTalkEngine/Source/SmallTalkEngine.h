#include "SmallTalkMath.h"
#include "SmallTalkUI.h"
#include "SmallTalkAudio.h"
//I intend to remove the need for external libs later - but for now i'll use them or... hmm
#define SmallTalkUI:: UI

	class SmallTalkEngine
	{
	public:
		double version = 0.3;

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
			Point2D()
			{
				X = 0.0f;
				Y = 0.0f;
			}
			float DistanceCalc(Point2D point1, Point2D point2)
			{
				Math calc;
				float temp = point1.X + point2.X;
				float temp2 = point1.Y + point2.Y;
				temp = calc.Pow(temp, 2);
				temp2 = calc.Pow(temp2, 2);
				temp = temp + temp2;
				temp = calc.Sqrt(temp);
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
		class GameObject2D
		{
		public:
			Point2D position;
			float rotX;
			float rotY;
			GameObject2D()
			{

			}

		};
		class Area
		{
		private:
			int id;
		public:
			GameObject2D objList[0];
			Area()
			{

			}
			void addObject(GameObject2D obj)
			{
				int l = getLength(objList);
				GameObject2D* temp = new GameObject2D[l + 1];
				objList[l + 1] = obj;
			}
			int getLength(GameObject2D objList[])
			{
				int result = 0;
				result = (sizeof(objList) / sizeof(*objList));
				return result;
			}
		};
		class BoxCollider2D
		{
		public:
			float size;
			bool IsActive;
			bool IsSolid;
			Point2D center;
			BoxCollider2D(float Size, Point2D Center, bool isSolid = true, bool isActive = true)
			{

			}
		};
		class AudioListener
		{
		public:
			float volume;
			float getVolume()
			{

			}
			int getLength(AudioListener objList[])
			{
				int result = 0;
				result = (sizeof(objList) / sizeof(*objList));
				return result;
			}
		};
		class AudioPlayer
		{
		public:
			AudioPlayer()
			{

				//attach itself to the global list of soundplaying objects
			}
			int getLength(AudioPlayer objList[])
			{
				int result = 0;
				result = (sizeof(objList) / sizeof(*objList));
				return result;
			}
		};
		class Wav
		{
		public:
			Wav(std::string pathToFile)
			{

			}
		};
		void selfTest()
		{

		}



};
