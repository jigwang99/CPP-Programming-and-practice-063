#include <SFML/Graphics.hpp>
//#include <iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include <sstream>
//#include <random>
using namespace sf;
using namespace std;
#define HEIGHT 1200
#define WIDTH 600


struct pos
{
	int x;
	int y;
};

class Dino
{
	enum
	{
		JUMP_TIME	= 5
	};
	private:
		pos dino_pos;
		Texture t[4];
		Sprite dinoSprite[4];
		bool jumping;
		int up, down;
		
	public:
		Dino()
		{
			dino_pos.x = 50;
			dino_pos.y = 450;
			t[0].loadFromFile("images/dino1.png");
			t[1].loadFromFile("images/dino2.png");
			t[2].loadFromFile("images/dino_fly1.png");
			t[3].loadFromFile("images/dino_fly2.png");	
			dinoSprite[0] = Sprite(t[0]);
			dinoSprite[1] = Sprite(t[1]);
			dinoSprite[2] = Sprite(t[2]);
			dinoSprite[3] = Sprite(t[3]);
			jumping = false;
			up = 5;
			down = 5;
		}
		Sprite GetSprite(int i) const
		{
			return dinoSprite[i];
		}
		

		
		pos GetPos() const
		{
			return dino_pos;
		}
		
		void PlusXPos(int j)
		{
			dino_pos.x += j;
		}
		
		void PlusYPos(int k)
		{
			dino_pos.y += k;
		}
};

class Obstacle
{
	private:
		int index;
		int speed;
		int speedMax;
		pos obs_pos;
		Texture t1, t2;
		Sprite obsSprite[2];
		bool goDino;
	public:
		Obstacle()
		{
			srand((unsigned)time(NULL));
			goDino = false;
			speed = 0;
			speedMax = 70;
			obs_pos.x = 1300;
			obs_pos.y = 450;
			t1.loadFromFile("images/cactus.png");
			t2.loadFromFile("images/dino_fly1.png");
			obsSprite[0] = Sprite(t1);
			obsSprite[1] = Sprite(t2);
		}
		pos GetPos() const
		{
			return obs_pos;
		}
		Sprite GetSprite(int j) const
		{
			return obsSprite[j];
		}
		bool GetgoDino() const
		{
			return goDino;
		}
		void goDinoSet(bool tf)
		{
			goDino = tf;
		}
		
		void SetPos(int m, int n)
		{
			obs_pos.x = m;
			obs_pos.y = n;
		}
		
		void PlusXPos(int k)
		{
			obs_pos.x += k;
		}
		
		void PlusYPos(int l)
		{
			obs_pos.y += l;
		}
		
		void PlusXPos_speed()
		{
			if(goDino)
				obs_pos.x -= speed;
		}
		
		void ObstacleSpeedSet(int speedup, int speedmult)
		{
			speed *= speedmult;
			if(speed < speedMax)
			{	
				speed += speedup;
			}
		}
		
		int GetObstacleSpeed() const
		{
			return speed;
		}
};

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
class backgrond
{
	
};

class Score
{
	private:
		int score;
		Font font;
		Text text;
	
	public:
		Score(int i)
		{
			score = i;
			stringstream ss;
			string score_str;
			
			ss.str("");
			ss << score;
			score_str = ss.str();
			
			if (!font.loadFromFile("SEBANG Gothic.ttf"));
			text.setFont(font);
			text.setCharacterSize(30);
			text.setFillColor(Color::Black);
			text.setString("score : " + score_str);
		}
		
		void PlusScore(int j)
		{
			score += j;
		}
		
		Text GetScoreText() 
		{
			stringstream ss;
			string score_str;	
			ss.str("");
			ss << score;
			score_str = ss.str();
			text.setString("score : " + score_str);
			return text;
		}
		
		void ResetScore()
		{
			score = 0;
		}
};

int main()
{
	RenderWindow window(VideoMode(HEIGHT, WIDTH), "Dino_Run");
	window.setFramerateLimit(60);
	Dino dino;
	Obstacle obs[3];
	obs[0].goDinoSet(true);
	Score score(0);
	Heart heart(0);
	Bomb bomb(0);
	
	srand((unsigned)time(NULL));
	
	int frame = 0;
	
	int index = 0, index0 = 0, rnum;
	int i = 0;
	
	bool jumping = false, double_jumping = false, djumpUsed = false, running = false, 
	autoMode = false, crash = false, pause = false, flyMode = false;
	int jumping_up = 20, jumping_down = 20;
	int djumping_up = 20, djumping_down = 20;
	for(i = 0; i < 3; i++)
		obs[i].SetPos(1300, 450);
	
	while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        while(running && !pause)
        {
        	while (window.pollEvent(event))
        	{
            if (event.type == Event::Closed)
                window.close();
        	}
        	
	        if (Keyboard::isKeyPressed(Keyboard::Space))
	        {
	        	if(!jumping)
				{
					jumping = true;
					djumpUsed = false;
				}
				
	        	
			}
			/*if (Keyboard::isKeyPressed(Keyboard::D))
			{
				if(double_jumping == false && djumpUsed == false)
				{
					double_jumping = true;
					djumpUsed = true;
				}
			}*/
			if (Keyboard::isKeyPressed(Keyboard::A))
	        {
	        	autoMode = true;	
			}
			
			if (Keyboard::isKeyPressed(Keyboard::U))
	        {
	        	autoMode = false;	
			}
			
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				pause = true;
			}
			
			index++;
			
			
			if (index >= 4)
			{
				index = 0;
			}
			if(index == 3)
			{	
				pos pos0, pos1;
				index0++;
				if(index0 == 50)
				{
					index0 = 0;
					bomb.PlusBomb(1);
				}
				for(i = 0; i < 2; i++)
				{
					obs[i].PlusXPos_speed();
					pos0 = obs[i].GetPos();
					pos1 = obs[(i + 1) % 2].GetPos();
					if(i == 0 && !(rand() % 8) && pos1.x == 1300)
					{
						obs[i + 1].PlusXPos((obs[i + 1].GetObstacleSpeed()) / 20);
						obs[i + 1].goDinoSet(true);
					}
					else if(pos0.x + obs[(i + 1) % 2].GetObstacleSpeed() * 20 + 100 + rand() % 500 < pos1.x)
					{
						obs[(i + 1) % 2].goDinoSet(true);
					}
				}
				
				heart.PlusXPos_speed();
				bomb.PlusXPos_speed();
				
			}
			if(jumping)
			{
				if(double_jumping)
				{
					if(djumping_up > 0 && djumping_down == 20)
					{
						dino.PlusYPos(-1 * djumping_up * djumping_up / 25);				
						djumping_up--;
					}
					else if(djumping_up == 0 && djumping_down > 0)
					{
						dino.PlusYPos(1 * djumping_down * djumping_down / 25);
						djumping_down--;
					}
					else
					{
						djumping_up = 20;
						djumping_down = 20;
						double_jumping = false;
					}	
				}
				else
				{
					if(jumping_up > 0 && jumping_down == 20)
					{
						dino.PlusYPos(-1 * jumping_up * jumping_up / 25);				
						jumping_up--;
					}
					else if(jumping_up == 0 && jumping_down > 0)
					{
						dino.PlusYPos(1 * jumping_down * jumping_down / 25);
						jumping_down--;
					}
					else
					{
						jumping_up = 20;
						jumping_down = 20;
						jumping = false;
						djumpUsed == false;
					}
				}
			}
				
			window.clear(Color::White);
			i = (int)(index / 2);
			if(flyMode)
				i += 2;
			Sprite temp_sprite_dino = dino.GetSprite(i);
			pos temp_pos_dino = dino.GetPos();
			
				
			Sprite temp_sprite_obs[2];
			pos temp_pos_obs[2];
			for(i = 0; i < 2; i++)
			{
				temp_sprite_obs[i] = obs[i].GetSprite(0);
				temp_pos_obs[i] = obs[i].GetPos();
				temp_sprite_obs[i].setPosition(temp_pos_obs[i].x, temp_pos_obs[i].y);
				window.draw(temp_sprite_obs[i]);
			}
			
			Sprite temp_sprite_heart = heart.GetSprite(0);
			pos temp_pos_heart = heart.GetPos();
			temp_sprite_heart.setPosition(temp_pos_heart.x, temp_pos_heart.y);
			window.draw(temp_sprite_heart);
			
			Sprite temp_sprite_bomb = bomb.GetSprite(0);
			pos temp_pos_bomb = bomb.GetPos();
			temp_sprite_dino.setPosition(temp_pos_dino.x, temp_pos_dino.y);
			window.draw(temp_sprite_dino);
			
			temp_sprite_bomb.setPosition(temp_pos_bomb.x, temp_pos_bomb.y);
			window.draw(temp_sprite_bomb);
			
			score.PlusScore(1);
		
			Text text = score.GetScoreText();
			text.setPosition(10, 10);
			window.draw(text);
			
			Text text1 = score.GetScoreText();
			text1.setPosition(10, 10);
			Text text2 = heart.GetHeartText();
			text2.setPosition(10, 50);
			Text text3 = bomb.GetBombText();
			text3.setPosition(10, 90);
			
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			
			
			if(autoMode)
			{
				for(i = 0; i < 2; i++)
				{
					if(temp_pos_obs[i].x - temp_pos_dino.x < obs[i].GetObstacleSpeed() * 2 + 50 && temp_pos_obs[i].x - temp_pos_dino.x > 0)
					{
						if(!jumping)
						{
							jumping = true;
						}
						else if(jumping && !(double_jumping) && !(djumpUsed))
						{
							//double_jumping = true;
							//djumpUsed = true;
						}
					}
					if(temp_pos_obs[i].x - temp_pos_dino.x < obs[i].GetObstacleSpeed() * 4 + 100)
					{
						if(jumping && !(double_jumping) && !(djumpUsed))
						{
							//double_jumping = true;
							//djumpUsed = true;
						}
					}
				}
				
			}
			 
			if(temp_pos_heart.x - temp_pos_dino.x < 55 && temp_pos_heart.x - temp_pos_dino.x > 0 && temp_pos_heart.y - temp_pos_dino.y < 40)
			{
				heart.Plusheart();
				heart.PlusXPos(27000);
			}
			
			
			
					
			if (Keyboard::isKeyPressed(Keyboard::B))
			{
				if(0 < bomb.Bombindex() && temp_pos_bomb.x - temp_pos_dino.x > 100)
				{
					bomb.ShootBomb();
					bomb.MinusBomb();
				}
				else{
				}
			}
			if(0 < bomb.BombSpeed())
			{
				for(i = 0; i < 2; i++)
				{
					if(temp_pos_bomb.x - temp_pos_obs[i].x < 50 && temp_pos_obs[i].x - temp_pos_bomb.x < 50)
					{
						bomb.BombPlace1();
						obs[i].SetPos(1300, 450);
						obs[i].ObstacleSpeedSet(1, 1);
					}
				}
			}
			else
			{
				if(temp_pos_bomb.x - temp_pos_dino.x < 55 && temp_pos_bomb.x - temp_pos_dino.x > 0 && temp_pos_bomb.y - temp_pos_dino.y < 40)
				{
				bomb.PlusBomb(5);
				bomb.PlusXPos(27000);
				}
			}
			for(i = 0; i < 2; i++)
			{
				if(temp_pos_obs[i].x - temp_pos_dino.x < 55 && temp_pos_obs[i].x - temp_pos_dino.x > 0 && temp_pos_obs[i].y - temp_pos_dino.y < 40)
				{
					if(0 < heart.Heartindex())
					{
						heart.Minusheart();
						obs[i].PlusXPos(-200);
					}
					else
					{
						running = false;
						crash = true;
						text.setString("The dinosaur collided with an obstacle.");
						
						text.setCharacterSize(50);
						text.setFillColor(Color(0, 0, 0));
						text.setPosition(100, 150);
						window.draw(text);
						
						text.setString("TO GO HOME : PRESS \"H\"");
						text.setCharacterSize(80);
						text.setFillColor(Color(255, 127, 0));
						text.setPosition(100, 200);
						window.draw(text);
					}
				}
			}

			
			window.display();
			bomb.BombPlace2();
			
			for(i = 0; i < 2; i++)
			{
				if(temp_pos_obs[i].x < 50)
				{
					obs[i].goDinoSet(false);
					obs[i].SetPos(1300, 450);
					obs[i].ObstacleSpeedSet(1, 1);
					if(i == 1)
					{
						obs[0].goDinoSet(true);
					}
				}
			}
			if(temp_pos_heart.x < -100)
				heart.PlusXPos(27000);
				
			if(temp_pos_bomb.x < -100)
				bomb.PlusXPos(27000);
		}
		
		if(!running && !crash)
		{
			Font font_start;
			Text text_start;
			
			window.clear(Color::White);
			
			
			
			
			if (!font_start.loadFromFile("SEBANG Gothic.ttf"));
			text_start.setFont(font_start);
			text_start.setCharacterSize(80);
			text_start.setFillColor(Color::Black);
			text_start.setString("Dino_Run");
			text_start.setPosition(300, 200);
			window.draw(text_start);
			
			text_start.setCharacterSize(40);
			text_start.setFillColor(Color(255, 127, 0));
			text_start.setString("\tTO START : PRESS \"S\"");
			text_start.setPosition(300, 300);
			window.draw(text_start);
			
			text_start.setCharacterSize(20);
			text_start.setFillColor(Color(0, 0, 0));
			text_start.setString("Team dino_run\n201824170 Jung, Da-Hyun\n201824604 Choi, Ji-Gwang \n\/\/201724519 Lee, Gang-Yoon");
			text_start.setPosition(800, 400);
			window.draw(text_start);
			window.display();
		}
		else if(!running && crash)
		{

		}
		
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			if(crash)
			{
				running = false;
				crash = false;
				for(i = 0; i < 3; i++)
					obs[i].ObstacleSpeedSet(20, 0);
			}
		}
		
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if(!crash)
			{
				running = true;
				score.ResetScore();
				heart.ResetHeart();
				bomb.ResetBomb();
				for(i = 0; i < 3; i++)
				{
					obs[i].ObstacleSpeedSet(30, 0);
					obs[i].SetPos(1300, 450);
				}
			}
		}
		
		if (Keyboard::isKeyPressed(Keyboard::A))
	    {
	        autoMode = true;	
		}
			
		if (Keyboard::isKeyPressed(Keyboard::U))
	    {
	       	autoMode = false;	
		}
		
		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			pause = false;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			flyMode = true;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			flyMode = false;
		}	
	}  
    return 0;
}
