
/*
	| Just a header file with classes		|
	| for bonnie's and chica's coordinates	|
	| to define. And the doors class.		|
*/

namespace Coord {
	class Bonnie_pos {
	public:
		short x{ 0 }, y{ 0 };
	};


	class Chica_pos {
	public:
		short x{ 0 }, y{ 0 };
	};

	class Doors {
	public:
		bool isRight{ false }, isLeft{ false };
	};

}

