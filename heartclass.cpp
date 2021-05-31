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
