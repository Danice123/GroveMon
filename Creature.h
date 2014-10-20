struct move{

};

struct attack:move{
	int power, accuracy;
};


enum type{WATER, GRASS, FIRE};

class Creature{
	public:
		virtual void attack();


	private:
		type creature_type;

		int attack, defense, hp, speed;
};