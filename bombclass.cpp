class Heart
{
	private:
		int index;
		int speed;
		int heart;
		pos heart_pos;
		Texture t4;
		Sprite heartArr[2];
		Font font;
		Text text;
		
	public:
		Heart(int i)
		{
			heart = 0;
			index = i;
			speed = -30;
			heart_pos.x = 27000;
			heart_pos.y = 350;
			t4.loadFromFile("images/heart.png");
			heartArr[0] = Sprite(t4);
			
			stringstream h;
			string heart_str;
			h.str("");
			h << heart;
			heart_str = h.str();
			
			if (!font.loadFromFile("SEBANG Gothic.ttf"));
			text.setFont(font);
			text.setCharacterSize(30);
			text.setFillColor(Color::Black);
			text.setString("Heart : " + heart_str);
		}
		pos GetPos() const
		{
			return heart_pos;
		}
		Sprite GetSprite(int j) const
		{
			return heartArr[j];
		}
		
		void PlusXPos(int k)
		{
			heart_pos.x += k;
		}
		
		void PlusYPos(int l)
		{
			heart_pos.y += l;
		}
		
		void PlusXPos_speed()
		{
			heart_pos.x += speed;
		}
		
		void Plusheart()
		{
			heart += 1;
		}
		
		void Minusheart()
		{
			heart -= 1;
		}
		
		int Heartindex()
		{
			return heart;
		}
				
		Text GetHeartText() 
		{
			stringstream h;
			string heart_str;	
			h.str("");
			h << heart;
			heart_str = h.str();
			text.setString("Heart : " + heart_str);
			return text;
		}
		
		void ResetHeart()
		{
			heart = 3;
		}
};

class Bomb
{
	private:
		int index;
		int speed;
		int bomb;
		pos bomb_pos;
		Texture t5;
		Sprite bombArr[2];
		Font font;
		Text text;
		
	public:
		Bomb(int i)
		{
			bomb = 0;
			index = i;
			speed = -20;
			bomb_pos.x = 15000;
			bomb_pos.y = 450;
			t5.loadFromFile("images/bomb.png");
			bombArr[0] = Sprite(t5);
			
			stringstream b;
			string bomb_str;
			b.str("");
			b << bomb;
			bomb_str = b.str();
			
			if (!font.loadFromFile("SEBANG Gothic.ttf"));
			text.setFont(font);
			text.setCharacterSize(30);
			text.setFillColor(Color::Black);
			text.setString("Bomb : " + bomb_str);
		}
		pos GetPos() const
		{
			return bomb_pos;
		}
		
		Sprite GetSprite(int j) const
		{
			return bombArr[j];
		}
		
		void XPos(int k)
		{
			bomb_pos.x = k;
		}
		
		void PlusXPos(int k)
		{
			bomb_pos.x += k;
		}
		
		void PlusYPos(int l)
		{
			bomb_pos.y += l;
		}
		
		void PlusXPos_speed()
		{
			bomb_pos.x += speed;
		}
		
		void PlusBomb(int m)
		{
			bomb += m;
		}
		
		void MinusBomb()
		{
			bomb -= 1;
		}
		
		int Bombindex()
		{
			return bomb;
		}
		int BombSpeed()
		{
			return speed;
		}		
		Text GetBombText() 
		{
			stringstream b;
			string bomb_str;	
			b.str("");
			b << bomb;
			bomb_str = b.str();
			text.setString("Bomb : " + bomb_str);
			return text;
		}
		
		void ResetBomb()
		{
			bomb = 3;
		}
		
		void ShootBomb()
		{
			speed = 40;
			bomb_pos.x = 100;
			bomb_pos.y = 450;	
		}
		
		void BombPlace1()
		{
			speed = -20;
			bomb_pos.x = 14400;
			bomb_pos.y = 450;
		}
		void BombPlace2()
		{
			if(1300 < bomb_pos.x && speed == 40){
			speed = -20;
			bomb_pos.x = 14400;
			bomb_pos.y = 450;
			}
		}
};
