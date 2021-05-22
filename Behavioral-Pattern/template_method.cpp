#include <iostream>

class Game{
	public:
		explicit Game(int number_of_players): number_of_players_(number_of_players) {}
		
		void Run(){
			Start();

			while(!HaveWinner()){
				TakeTurn();
			}

			std::cout << "Player: " << GetWinner() << " wins\n";
			return ;
		}

	protected:
		virtual void Start() = 0;
		virtual bool HaveWinner() = 0;
		virtual void TakeTurn() = 0;
		virtual int GetWinner() = 0;

		int current_player_{0};
		int number_of_players_;
};

class Chess: public Game{
	public:
		explicit Chess(): Game{2} {}
	protected:
		void Start() override{
			std::cout << "Starting a game of chess with " << number_of_players_ << " players\n";
			return;
		}

		bool HaveWinner() override{
			return turns_ == max_turns_;
		}

		void TakeTurn() override{
			std::cout << "Turn: " << turns_ << " taken by player " << current_player_ << "\n";
			turns_ ++;
			current_player_ = (current_player_ + 1) % number_of_players_;
		}

		int GetWinner() override{
			return current_player_;
		}

	private:
		int turns_{0};
		int max_turns_{10};
};

int main(){
	Chess chess;
	chess.Run();
	return 0;
}
